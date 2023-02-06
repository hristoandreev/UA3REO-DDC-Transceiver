#include "FT8_main.h"
#include "Process_DSP.h"
#include "decode_ft8.h"
#include <stdbool.h>
// #include "WF_Table.h"
#include "FT8_GUI.h"
#include "arm_math.h"
#include "locator_ft8.h"
#include "traffic_manager.h"

#include "lcd.h"
#include "lcd_driver.h"

#include "constants.h"

#define ft8_shift 6.25

int ft8_flag, FT_8_counter, ft8_marker, decode_flag, WF_counter;
int num_decoded_msg = 0;

int DSP_Flag;

uint16_t cursor_line = 100;

uint16_t FT8_DatBlockNum;
bool FT8_DecodeActiveFlg;
bool FT8_ColectDataFlg;
// bool FT8_Bussy = false;

// Function prototypes
void process_data(void);
void update_synchronization(void);

void InitFT8_Decoder(void) {
	if (LCD_busy) {
		return;
	}
	LCD_busy = true; //

	// draw the GUI
	LCDDriver_Fill(COLOR_BLACK);

	LCDDriver_printText("FT-8 Decoder", 100, 5, COLOR_GREEN, COLOR_BLACK, 2);

	strcpy(Station_Call, TRX.CALLSIGN); // set out callsign
	strcpy(Locator, TRX.LOCATOR);       // set out grid Locator

	init_DSP();
	initalize_constants();

	FT8_DatBlockNum = 0;
	FT8_DecodeActiveFlg = true;

	update_synchronization();
	set_Station_Coordinates(Locator);

	println("FT8-Initialised"); // Debug

	Unarm_FT8_Buttons(); // deactivate all buttons (if something is active and we reenter the "FT8 decode"- to start clear)
	Draw_FT8_Buttons();
	FT8_Menu_Idx = 0;         // index of the "CQ" button
	Update_FT8_Menu_Cursor(); // show the menu cursor

	int8_t band = getBandFromFreq(CurrentVFO->Freq, true);
	if (band == BANDID_160m) { // 160m
		FT8_BND_Freq = FT8_Freq_160M;
	}
	if (band == BANDID_80m) { // 80m
		FT8_BND_Freq = FT8_Freq_80M;
	}
	if (band == BANDID_40m) { // 40m
		FT8_BND_Freq = FT8_Freq_40M;
	}
	if (band == BANDID_30m) { // 30m
		FT8_BND_Freq = FT8_Freq_30M;
	}
	if (band == BANDID_20m) { // 20m
		FT8_BND_Freq = FT8_Freq_20M;
	}
	if (band == BANDID_17m) { // 17m
		FT8_BND_Freq = FT8_Freq_17M;
	}
	if (band == BANDID_15m) { // 15m
		FT8_BND_Freq = FT8_Freq_15M;
	}
	if (band == BANDID_12m) { // 12m
		FT8_BND_Freq = FT8_Freq_12M;
	}
	if (band == BANDID_10m) { // 10m
		FT8_BND_Freq = FT8_Freq_10M;
	}
	if (band == BANDID_6m) { // 6m
		FT8_BND_Freq = FT8_Freq_6M;
	}
	if (band == BANDID_2m) { // 2m
		FT8_BND_Freq = FT8_Freq_2M;
	}

	receive_sequence();
	cursor_freq = (uint16_t)((float)(cursor_line + ft8_min_bin) * ft8_shift);
	FT8_Print_Freq();

	Set_Data_Colection(0); // Disable the data colection
	LCD_busy = false;
}

void MenagerFT8(void) {
	char ctmp[20] = {0};

	if (decode_flag == 0) {
		process_data();
	}

	if (LCD_busy) {
		return;
	}
	LCD_busy = true;

	if (DSP_Flag == 1) {
		if (!TRX_Tune) {
			// println("process_FT8_FFT");
			process_FT8_FFT();
		}

		if (xmit_flag == 1) {
			__disable_irq(); // Disable all interrupts
			int offset_index = 5;
			// 79
			if (ft8_xmit_counter >= offset_index && ft8_xmit_counter < 79 + offset_index) {
				set_FT8_Tone(tones[ft8_xmit_counter - offset_index]);
			}

			ft8_xmit_counter++;

			// Debug
			sprintf(ctmp, "ft8_xmit_c: %d ", ft8_xmit_counter);
			LCDDriver_printText(ctmp, 10, 65, COLOR_GREEN, COLOR_BLACK, 2);

			bool send_message_done = false;
			// 80
			if (ft8_xmit_counter == 80 + offset_index) {
				send_message_done = true;
			}

			uint32_t Time = RTC->TR;
			uint8_t Seconds = ((Time >> 4) & 0x07) * 10 + ((Time >> 0) & 0x0f);
			if (ft8_xmit_counter > offset_index && (Seconds == 14 || Seconds == 29 || Seconds == 44 || Seconds == 59)) { // 15s marker
				send_message_done = true;
			}

			if (send_message_done) // send mesage is done!
			{
				// xmit_flag = 0;
				receive_sequence();

				if (Beacon_State == 8) // if we are on the end of answering a "CQ" (we just send "73")
				{
					FT8_Menu_Idx = 0;      // index of the "CQ" button
					FT8_Menu_Pos_Toggle(); // deactivate the "CQ" button -> set green
				}
			}
			__enable_irq(); // Re-enable all interrupts
		}

		DSP_Flag = 0;
	}

	else if (decode_flag == 1) {
		HAL_SuspendTick();
		__disable_irq(); // Disable all interrupts

		FT8_Clear_Mess_Field(); // Clear the recieved mesages field

		num_decoded_msg = 0;
		//			FT8_ColectDataFlg = false;		//Stop Data colection
		//			FT8_Bussy = true;							//FT8 Decode => busy
		Set_Data_Colection(0); // Disable the data colection

		num_decoded_msg = ft8_decode();

		//			for (uint32_t wait_i = 0; wait_i < 360000000; wait_i++)
//				__asm("nop");

		// Debug
		sprintf(ctmp, "Decoded: %d ", num_decoded_msg);
		LCDDriver_printText(ctmp, 10, 45, COLOR_GREEN, COLOR_BLACK, 2);

		decode_flag = 0;

		Service_FT8();

		//			FT8_Bussy = false;

		/* Enable interrupts back */
		for (int i = 0; i < 5; i++) // Clear Interrupt Pending Register
		{
			NVIC->ICPR[i] = 0xFFFFFFFF;
		}
		__enable_irq(); // Re-enable all interrupts
		HAL_ResumeTick();
	}

	update_synchronization();
	LCD_busy = false; //
}

void process_data(void) {
	if (FT8_DatBlockNum >= num_que_blocks) {
		//    for (int i = 0; i<block_size*(FT8_DatBlockNum/8); i++) {
		//			input_gulp[i] = AudioBuffer_for_FT8[i];		//coppy to FFT buffer
		//			AudioBuffer_for_FT8[i] = 0; 		//	and empty the buffer
		//		}
		FT8_DatBlockNum = 0;

		// println("Prepare new Data!");	//Debug
		for (int i = 0; i < input_gulp_size; i++) {
			dsp_buffer[i] = dsp_buffer[i + input_gulp_size];
			dsp_buffer[i + input_gulp_size] = dsp_buffer[i + 2 * input_gulp_size];
			dsp_buffer[i + 2 * input_gulp_size] = input_gulp[i];
		}
		DSP_Flag = 1;
	}
}

// update the syncronisation and show the time
void update_synchronization(void) {
	char ctmp[30] = {0};

	uint32_t Time = RTC->TR;
	static uint8_t Seconds_Old;

	uint8_t Hours = ((Time >> 20) & 0x03) * 10 + ((Time >> 16) & 0x0f);
	uint8_t Minutes = ((Time >> 12) & 0x07) * 10 + ((Time >> 8) & 0x0f);
	uint8_t Seconds = ((Time >> 4) & 0x07) * 10 + ((Time >> 0) & 0x0f);

	if (Seconds >= 60) {      // Fix the seconds
		Seconds = Seconds - 60; // it is efect of the time correction
	}

	if (Seconds_Old != Seconds) // update the time on screen only when change
	{
		sprintf(ctmp, "%02d:%02d:%02d", Hours, Minutes, Seconds);
#if (defined(LAY_800x480))
		LCDDriver_printText(ctmp, 680, 5, COLOR_WHITE, COLOR_BLACK, 2);
#else
		LCDDriver_printText(ctmp, 300, 5, COLOR_WHITE, COLOR_BLACK, 2);
#endif

		// TX parameters
		sprintf(ctmp, "SWR: %.1f, PWR: %.1fW    ", (double)TRX_SWR, ((double)TRX_PWR_Forward - (double)TRX_PWR_Backward));
#if (defined(LAY_800x480))
		LCDDriver_printText(ctmp, 235, 400, FG_COLOR, BG_COLOR, 2);
#else
		LCDDriver_printText(ctmp, 200, 280, FG_COLOR, BG_COLOR, 2);
#endif

		sprintf(ctmp, "TEMP: % 2d    ", (int16_t)TRX_RF_Temperature);
#if (defined(LAY_800x480))
		LCDDriver_printText(ctmp, 235, 420, FG_COLOR, BG_COLOR, 2);
#else
		LCDDriver_printText(ctmp, 200, 300, FG_COLOR, BG_COLOR, 2);
#endif

		Seconds_Old = Seconds;
	}

	if ((ft8_flag == 0 && Seconds % 15 <= 1) && (decode_flag == 0)) // 15s marker
	{
		Set_Data_Colection(1); // Set new data colection
	}
}

// analyzer events to the encoder
void FT8_EncRotate(int8_t direction) {
	if (LCD_busy) {
		return;
	}
	LCD_busy = true;

	cursor_line += direction;

	if (cursor_line < 1) {
		cursor_line = 1;
	}
	if (cursor_line > ft8_buffer - 50) {
		cursor_line = ft8_buffer - 50;
	}

	cursor_freq = (uint16_t)((float)(cursor_line + ft8_min_bin) * ft8_shift);

	if (TRX_Tune) {
		set_Xmit_Freq(FT8_BND_Freq, cursor_freq);
	}

	FT8_Print_Freq(); // Print the new frequency

	LCD_busy = false;
}

void FT8_Enc2Rotate(int8_t direction) {

	if (LCD_busy) {
		return;
	}
	LCD_busy = true;

	Enc2Rotate_Menager(direction, num_decoded_msg);

	LCD_busy = false;
}

void FT8_Enc2Click(void) {
	if (LCD_busy) {
		return;
	}
	LCD_busy = true;

	cursor_line -= 1; // Bug fix (pressing the encoder causes one + 1 step of the main encoder)
	//	FT8_EncRotate(-1);					//Bug fix (pressing the encoder causes one + 1 step of the main encoder)

	FT8_Menu_Pos_Toggle();

	LCD_busy = false;
}