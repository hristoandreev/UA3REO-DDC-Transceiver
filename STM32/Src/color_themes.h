#ifndef LCD_COLOR_THEMES_h
#define LCD_COLOR_THEMES_h

#include "lcd_driver.h"

typedef const struct {
	const uint16_t BACKGROUND;
	const uint16_t FOREGROUND;
	const uint16_t BUTTON_TEXT;
	const uint16_t BUTTON_INACTIVE_TEXT;
	const uint16_t BUTTON_BACKGROUND;
	const uint16_t FREQ_MHZ;
	const uint16_t FREQ_KHZ;
	const uint16_t FREQ_HZ;
	const uint16_t STATUS_VFO;
	const uint16_t STATUS_VFO_BG;
	const uint16_t STATUS_BAR_LEFT;
	const uint16_t STATUS_BAR_RIGHT;
	const uint16_t STATUS_BAR_LABELS;
	const uint16_t STATUS_RX;
	const uint16_t STATUS_TX;
	const uint16_t STATUS_TU;
	const uint16_t STATUS_LABELS_BW;
	const uint16_t STATUS_LABELS_TX;
	const uint16_t STATUS_LABEL_S_VAL;
	const uint16_t STATUS_LABEL_DBM;
	const uint16_t STATUS_LABEL_BW;
	const uint16_t STATUS_LABEL_RIT;
	const uint16_t STATUS_LABEL_THERM;
	const uint16_t STATUS_LABEL_NOTCH;
	const uint16_t STATUS_SMETER;
	const uint16_t STATUS_SMETER_HIGH;
	const uint16_t STATUS_SMETER_STRIPE;
	const uint16_t STATUS_SMETER_PEAK;
	const uint16_t STATUS_SMETER_FM_SQL;
	const uint16_t STATUS_MODE;
	const uint16_t STATUS_ERR;
	const uint16_t STATUS_INFO_BORDER;
	const uint16_t BANDMAP_CW;
	const uint16_t BANDMAP_SSB;
	const uint16_t BANDMAP_DIGI;
	const uint16_t BANDMAP_AM;
	const uint16_t BANDMAP_FM;
	const uint16_t GREETINGS;
	const uint16_t TOOLTIP_FORE;
	const uint16_t TOOLTIP_BACK;
	const uint16_t TOOLTIP_BORD;
	const uint16_t CLOCK;
	const uint16_t FFT_GRADIENT_START_R;
	const uint16_t FFT_GRADIENT_START_G;
	const uint16_t FFT_GRADIENT_START_B;
	const uint16_t FFT_GRADIENT_END_R;
	const uint16_t FFT_GRADIENT_END_G;
	const uint16_t FFT_GRADIENT_END_B;
	const bool WTF_BG_WHITE;
	const uint16_t BW_TRAPEZ_BORDER;
	const uint16_t BW_TRAPEZ_STRIPE;
	const uint16_t BW_TRAPEZ_FILL;
	const uint16_t ACTIVE_BORDER;
	// 7inch
	const uint16_t FREQ_B_MHZ;
	const uint16_t FREQ_B_KHZ;
	const uint16_t FREQ_B_HZ;
	const uint16_t FREQ_A_INACTIVE;
	const uint16_t FREQ_B_INACTIVE;
	const uint16_t STATUS_LABEL_ACTIVE;
	const uint16_t STATUS_LABEL_INACTIVE;
	const uint16_t BUTTON_BACK;
	const uint16_t BUTTON_BORDER;
	const uint16_t BUTTON_LIGHTER_ACTIVE;
	const uint16_t BUTTON_LIGHTER_INACTIVE;
	const uint16_t WINDOWS_BORDER;
	const uint16_t WINDOWS_BG;
	const uint16_t KEYBOARD_BG;
	const uint16_t IFGAIN_BAR_BG;
	const uint16_t IFGAIN_BAR_FG;
	const uint16_t AFGAIN_BAR_BG;
	const uint16_t AFGAIN_BAR_FG;
} STRUCT_COLOR_THEME;

#define COLOR_THEMES_COUNT 6

static const STRUCT_COLOR_THEME COLOR_THEMES[COLOR_THEMES_COUNT] = {
    // 0 - black
    {
        // 3'2 inch
        .BACKGROUND = COLOR_BLACK,
        .FOREGROUND = COLOR_WHITE,
        .BUTTON_TEXT = rgb888torgb565(32, 191, 17),
        .BUTTON_INACTIVE_TEXT = rgb888torgb565(130, 130, 130),
        .BUTTON_BACKGROUND = rgb888torgb565(50, 50, 50),
        .FREQ_MHZ = COLOR_WHITE,
        .FREQ_KHZ = COLOR_WHITE,
        .FREQ_HZ = rgb888torgb565(150, 150, 150),
        .STATUS_VFO = COLOR_BLACK,
        .STATUS_VFO_BG = COLOR_WHITE,
        .STATUS_BAR_LEFT = rgb888torgb565(100, 100, 255),
        .STATUS_BAR_RIGHT = rgb888torgb565(255, 100, 100),
        .STATUS_BAR_LABELS = rgb888torgb565(32, 171, 17),
        .STATUS_RX = COLOR_WHITE,
        .STATUS_TX = COLOR_RED,
        .STATUS_TU = rgb888torgb565(249, 205, 46),
        .STATUS_LABELS_BW = COLOR_WHITE,
        .STATUS_LABELS_TX = rgb888torgb565(32, 171, 17),
        .STATUS_LABEL_S_VAL = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_DBM = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_BW = rgb888torgb565(0, 200, 255),
        .STATUS_LABEL_RIT = COLOR_WHITE,
        .STATUS_LABEL_THERM = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_NOTCH = rgb888torgb565(0, 200, 255),
        .STATUS_SMETER = rgb888torgb565(249, 205, 46),
        .STATUS_SMETER_HIGH = rgb888torgb565(249, 150, 46),
        .STATUS_SMETER_STRIPE = COLOR_RED,
        .STATUS_SMETER_PEAK = rgb888torgb565(249, 151, 46),
        .STATUS_SMETER_FM_SQL = rgb888torgb565(30, 139, 28),
        .STATUS_MODE = rgb888torgb565(249, 205, 46),
        .STATUS_ERR = COLOR_RED,
        .STATUS_INFO_BORDER = COLOR_RED,
        .BANDMAP_CW = rgb888torgb565(50, 50, 255),
        .BANDMAP_SSB = rgb888torgb565(50, 237, 255),
        .BANDMAP_DIGI = rgb888torgb565(255, 50, 50),
        .BANDMAP_AM = rgb888torgb565(219, 255, 50),
        .BANDMAP_FM = rgb888torgb565(255, 50, 208),
        .GREETINGS = rgb888torgb565(0, 92, 86),
        .TOOLTIP_FORE = COLOR_WHITE,
        .TOOLTIP_BACK = COLOR_BLACK,
        .TOOLTIP_BORD = COLOR_WHITE,
        .CLOCK = COLOR_WHITE,
        .FFT_GRADIENT_START_R = 0,
        .FFT_GRADIENT_START_G = 11,
        .FFT_GRADIENT_START_B = 40,
        .FFT_GRADIENT_END_R = 46,
        .FFT_GRADIENT_END_G = 77,
        .FFT_GRADIENT_END_B = 158,
        .WTF_BG_WHITE = false,
        .BW_TRAPEZ_BORDER = rgb888torgb565(120, 120, 120),
        .BW_TRAPEZ_STRIPE = rgb888torgb565(0, 200, 255),
        .BW_TRAPEZ_FILL = rgb888torgb565(140, 140, 140),
        .ACTIVE_BORDER = rgb888torgb565(0, 102, 153),
        // 7inch
        .FREQ_B_MHZ = COLOR_WHITE,
        .FREQ_B_KHZ = COLOR_WHITE,
        .FREQ_B_HZ = rgb888torgb565(150, 150, 150),
        .FREQ_A_INACTIVE = rgb888torgb565(100, 100, 100),
        .FREQ_B_INACTIVE = rgb888torgb565(100, 100, 100),
        .STATUS_LABEL_ACTIVE = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_INACTIVE = rgb888torgb565(90, 90, 90),
        .BUTTON_BACK = rgb888torgb565(10, 10, 10),
        .BUTTON_BORDER = rgb888torgb565(105, 105, 105),
        .BUTTON_LIGHTER_ACTIVE = rgb888torgb565(32, 191, 17),
        .BUTTON_LIGHTER_INACTIVE = rgb888torgb565(90, 90, 90),
        .WINDOWS_BORDER = rgb888torgb565(249, 205, 46),
        .WINDOWS_BG = COLOR_BLACK,
        .KEYBOARD_BG = rgb888torgb565(20, 20, 20),
        .IFGAIN_BAR_BG = rgb888torgb565(20, 20, 20),
        .IFGAIN_BAR_FG = rgb888torgb565(255, 0, 0),
        .AFGAIN_BAR_BG = rgb888torgb565(20, 20, 20),
        .AFGAIN_BAR_FG = rgb888torgb565(0, 255, 0),
    },
    // 1 - white
    {
        // 3'2 inch
        .BACKGROUND = COLOR_WHITE,
        .FOREGROUND = COLOR_BLACK,
        .BUTTON_TEXT = rgb888torgb565(150, 130, 50),
        .BUTTON_INACTIVE_TEXT = rgb888torgb565(220, 220, 220),
        .BUTTON_BACKGROUND = rgb888torgb565(240, 240, 240),
        .FREQ_MHZ = COLOR_BLACK,
        .FREQ_KHZ = COLOR_BLACK,
        .FREQ_HZ = rgb888torgb565(130, 130, 130),
        .STATUS_VFO = COLOR_WHITE,
        .STATUS_VFO_BG = rgb888torgb565(150, 150, 150),
        .STATUS_BAR_LEFT = rgb888torgb565(100, 100, 255),
        .STATUS_BAR_RIGHT = rgb888torgb565(255, 100, 100),
        .STATUS_BAR_LABELS = rgb888torgb565(32, 171, 17),
        .STATUS_RX = COLOR_BLACK,
        .STATUS_TX = COLOR_RED,
        .STATUS_TU = rgb888torgb565(249, 205, 46),
        .STATUS_LABELS_BW = COLOR_BLACK,
        .STATUS_LABELS_TX = rgb888torgb565(32, 171, 17),
        .STATUS_LABEL_S_VAL = rgb888torgb565(150, 130, 50),
        .STATUS_LABEL_DBM = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_BW = rgb888torgb565(0, 100, 255),
        .STATUS_LABEL_RIT = COLOR_BLACK,
        .STATUS_LABEL_THERM = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_NOTCH = rgb888torgb565(0, 100, 255),
        .STATUS_SMETER = rgb888torgb565(255, 238, 175),
        .STATUS_SMETER_HIGH = rgb888torgb565(255, 180, 175),
        .STATUS_SMETER_STRIPE = COLOR_RED,
        .STATUS_SMETER_PEAK = rgb888torgb565(249, 151, 46),
        .STATUS_SMETER_FM_SQL = rgb888torgb565(30, 139, 28),
        .STATUS_MODE = rgb888torgb565(150, 130, 50),
        .STATUS_ERR = COLOR_RED,
        .STATUS_INFO_BORDER = COLOR_RED,
        .BANDMAP_CW = rgb888torgb565(100, 100, 250),
        .BANDMAP_SSB = rgb888torgb565(60, 225, 241),
        .BANDMAP_DIGI = rgb888torgb565(255, 50, 50),
        .BANDMAP_AM = rgb888torgb565(184, 215, 42),
        .BANDMAP_FM = rgb888torgb565(192, 0, 148),
        .GREETINGS = rgb888torgb565(0, 92, 86),
        .TOOLTIP_FORE = COLOR_BLACK,
        .TOOLTIP_BACK = COLOR_WHITE,
        .TOOLTIP_BORD = COLOR_BLACK,
        .CLOCK = COLOR_BLACK,
        .FFT_GRADIENT_START_R = 220,
        .FFT_GRADIENT_START_G = 220,
        .FFT_GRADIENT_START_B = 250,
        .FFT_GRADIENT_END_R = 255,
        .FFT_GRADIENT_END_G = 255,
        .FFT_GRADIENT_END_B = 255,
        .WTF_BG_WHITE = true,
        .BW_TRAPEZ_BORDER = rgb888torgb565(120, 120, 120),
        .BW_TRAPEZ_STRIPE = rgb888torgb565(0, 200, 255),
        .BW_TRAPEZ_FILL = rgb888torgb565(140, 140, 140),
        .ACTIVE_BORDER = rgb888torgb565(0, 102, 153),
        // 7inch
        .FREQ_B_MHZ = COLOR_BLACK,
        .FREQ_B_KHZ = COLOR_BLACK,
        .FREQ_B_HZ = rgb888torgb565(130, 130, 130),
        .FREQ_A_INACTIVE = rgb888torgb565(100, 100, 100),
        .FREQ_B_INACTIVE = rgb888torgb565(100, 100, 100),
        .STATUS_LABEL_ACTIVE = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_INACTIVE = rgb888torgb565(90, 90, 90),
        .BUTTON_BACK = rgb888torgb565(10, 10, 10),
        .BUTTON_BORDER = rgb888torgb565(105, 105, 105),
        .BUTTON_LIGHTER_ACTIVE = rgb888torgb565(32, 191, 17),
        .BUTTON_LIGHTER_INACTIVE = rgb888torgb565(90, 90, 90),
        .WINDOWS_BORDER = rgb888torgb565(249, 205, 46),
        .WINDOWS_BG = COLOR_BLACK,
        .KEYBOARD_BG = rgb888torgb565(20, 20, 20),
        .IFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .IFGAIN_BAR_FG = rgb888torgb565(255, 0, 0),
        .AFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .AFGAIN_BAR_FG = rgb888torgb565(0, 255, 0),
    },

    {
        // 2 - black, 7-segments FREQ
        // 3'2 inch
        .BACKGROUND = COLOR_BLACK,
        .FOREGROUND = COLOR_WHITE,
        .BUTTON_TEXT = rgb888torgb565(32, 191, 17),
        .BUTTON_INACTIVE_TEXT = rgb888torgb565(130, 130, 130),
        .BUTTON_BACKGROUND = rgb888torgb565(50, 50, 50),

        .FREQ_MHZ = rgb888torgb565(0, 255, 212),
        .FREQ_KHZ = rgb888torgb565(0, 255, 212),
        .FREQ_HZ = rgb888torgb565(255, 195, 0),

        .STATUS_VFO = COLOR_BLACK,
        .STATUS_VFO_BG = COLOR_WHITE,
        .STATUS_BAR_LEFT = rgb888torgb565(100, 100, 255),
        .STATUS_BAR_RIGHT = rgb888torgb565(255, 100, 100),
        .STATUS_BAR_LABELS = rgb888torgb565(32, 171, 17),
        .STATUS_RX = COLOR_WHITE,
        .STATUS_TX = COLOR_RED,
        .STATUS_TU = rgb888torgb565(249, 205, 46),
        .STATUS_LABELS_BW = COLOR_WHITE,
        .STATUS_LABELS_TX = rgb888torgb565(32, 171, 17),
        .STATUS_LABEL_S_VAL = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_DBM = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_BW = rgb888torgb565(0, 200, 255),
        .STATUS_LABEL_RIT = COLOR_WHITE,
        .STATUS_LABEL_THERM = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_NOTCH = rgb888torgb565(0, 200, 255),
        .STATUS_SMETER = rgb888torgb565(249, 205, 46),
        .STATUS_SMETER_HIGH = rgb888torgb565(249, 150, 46),
        .STATUS_SMETER_STRIPE = COLOR_RED,
        .STATUS_SMETER_PEAK = rgb888torgb565(249, 151, 46),
        .STATUS_SMETER_FM_SQL = rgb888torgb565(30, 139, 28),
        .STATUS_MODE = rgb888torgb565(249, 205, 46),
        .STATUS_ERR = COLOR_RED,
        .STATUS_INFO_BORDER = COLOR_RED,
        .BANDMAP_CW = rgb888torgb565(50, 50, 255),
        .BANDMAP_SSB = rgb888torgb565(50, 237, 255),
        .BANDMAP_DIGI = rgb888torgb565(255, 50, 50),
        .BANDMAP_AM = rgb888torgb565(219, 255, 50),
        .BANDMAP_FM = rgb888torgb565(255, 50, 208),
        .GREETINGS = rgb888torgb565(0, 92, 86),
        .TOOLTIP_FORE = COLOR_WHITE,
        .TOOLTIP_BACK = COLOR_BLACK,
        .TOOLTIP_BORD = COLOR_WHITE,
        .CLOCK = COLOR_WHITE,
        .FFT_GRADIENT_START_R = 0,
        .FFT_GRADIENT_START_G = 11,
        .FFT_GRADIENT_START_B = 40,
        .FFT_GRADIENT_END_R = 46,
        .FFT_GRADIENT_END_G = 77,
        .FFT_GRADIENT_END_B = 158,
        .WTF_BG_WHITE = false,
        .BW_TRAPEZ_BORDER = rgb888torgb565(120, 120, 120),
        .BW_TRAPEZ_STRIPE = rgb888torgb565(0, 200, 255),
        .BW_TRAPEZ_FILL = rgb888torgb565(140, 140, 140),
        .ACTIVE_BORDER = rgb888torgb565(0, 102, 153),
        // 7inch

        .FREQ_B_MHZ = rgb888torgb565(0, 255, 212),
        .FREQ_B_KHZ = rgb888torgb565(0, 255, 212),
        .FREQ_B_HZ = rgb888torgb565(255, 195, 0),

        .FREQ_A_INACTIVE = rgb888torgb565(100, 100, 100),
        .FREQ_B_INACTIVE = rgb888torgb565(100, 100, 100),

        .STATUS_LABEL_ACTIVE = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_INACTIVE = rgb888torgb565(90, 90, 90),
        .BUTTON_BACK = rgb888torgb565(10, 10, 10),
        .BUTTON_BORDER = rgb888torgb565(105, 105, 105),
        .BUTTON_LIGHTER_ACTIVE = rgb888torgb565(32, 191, 17),
        .BUTTON_LIGHTER_INACTIVE = rgb888torgb565(90, 90, 90),
        .WINDOWS_BORDER = rgb888torgb565(249, 205, 46),
        .WINDOWS_BG = COLOR_BLACK,
        .KEYBOARD_BG = rgb888torgb565(20, 20, 20),
        .IFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .IFGAIN_BAR_FG = rgb888torgb565(255, 0, 0),
        .AFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .AFGAIN_BAR_FG = rgb888torgb565(0, 255, 0),
    },

    {
        // CN
        // 2 - black, 7-segments FREQ
        // 3'2 inch
        .BACKGROUND = COLOR_BLACK,
        .FOREGROUND = COLOR_WHITE,
        .BUTTON_TEXT = COLOR_GREEN,
        .BUTTON_INACTIVE_TEXT = COLOR_WHITE,
        .BUTTON_BACKGROUND = rgb888torgb565(20, 20, 20),

        .FREQ_MHZ = rgb888torgb565(255, 50, 0),
        .FREQ_KHZ = rgb888torgb565(255, 50, 0),
        .FREQ_HZ = rgb888torgb565(255, 195, 0),

        .STATUS_VFO = COLOR_WHITE,
        .STATUS_VFO_BG = rgb888torgb565(255, 50, 0),
        .STATUS_BAR_LEFT = rgb888torgb565(100, 100, 255),
        .STATUS_BAR_RIGHT = rgb888torgb565(255, 100, 100),
        .STATUS_BAR_LABELS = rgb888torgb565(32, 171, 17),
        .STATUS_RX = COLOR_GREEN,
        .STATUS_TX = COLOR_RED,
        .STATUS_TU = rgb888torgb565(249, 205, 46),
        .STATUS_LABELS_BW = COLOR_WHITE,
        .STATUS_LABELS_TX = rgb888torgb565(32, 171, 17),
        .STATUS_LABEL_S_VAL = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_DBM = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_BW = rgb888torgb565(0, 200, 255),
        .STATUS_LABEL_RIT = COLOR_WHITE,
        .STATUS_LABEL_THERM = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_NOTCH = rgb888torgb565(0, 200, 255),
        .STATUS_SMETER = rgb888torgb565(249, 205, 46),
        .STATUS_SMETER_HIGH = rgb888torgb565(249, 150, 46),
        .STATUS_SMETER_STRIPE = COLOR_RED,
        .STATUS_SMETER_PEAK = rgb888torgb565(249, 151, 46),
        .STATUS_SMETER_FM_SQL = rgb888torgb565(129, 135, 247),
        .STATUS_MODE = rgb888torgb565(249, 205, 46),
        .STATUS_ERR = COLOR_RED,
        .STATUS_INFO_BORDER = COLOR_RED,
        .BANDMAP_CW = rgb888torgb565(50, 50, 255),
        .BANDMAP_SSB = rgb888torgb565(50, 237, 255),
        .BANDMAP_DIGI = rgb888torgb565(255, 50, 50),
        .BANDMAP_AM = rgb888torgb565(219, 255, 50),
        .BANDMAP_FM = rgb888torgb565(255, 50, 208),
        .GREETINGS = rgb888torgb565(0, 92, 86),
        .TOOLTIP_FORE = COLOR_WHITE,
        .TOOLTIP_BACK = COLOR_RED,
        .TOOLTIP_BORD = COLOR_YELLOW,
        .CLOCK = COLOR_WHITE,
        .FFT_GRADIENT_START_R = 0,
        .FFT_GRADIENT_START_G = 11,
        .FFT_GRADIENT_START_B = 40,
        .FFT_GRADIENT_END_R = 46,
        .FFT_GRADIENT_END_G = 77,
        .FFT_GRADIENT_END_B = 158,
        .WTF_BG_WHITE = false,
        .BW_TRAPEZ_BORDER = rgb888torgb565(120, 120, 120),
        .BW_TRAPEZ_STRIPE = rgb888torgb565(255, 0, 0),
        .BW_TRAPEZ_FILL = rgb888torgb565(140, 140, 140),
        .ACTIVE_BORDER = rgb888torgb565(0, 102, 153),
        // 7inch

        .FREQ_B_MHZ = rgb888torgb565(0, 255, 212),
        .FREQ_B_KHZ = rgb888torgb565(0, 255, 212),
        .FREQ_B_HZ = rgb888torgb565(255, 195, 0),

        .FREQ_A_INACTIVE = rgb888torgb565(100, 100, 100),
        .FREQ_B_INACTIVE = rgb888torgb565(100, 100, 100),

        .STATUS_LABEL_ACTIVE = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_INACTIVE = rgb888torgb565(90, 90, 90),
        .BUTTON_BACK = rgb888torgb565(60, 60, 60),
        .BUTTON_BORDER = rgb888torgb565(105, 105, 105),
        .BUTTON_LIGHTER_ACTIVE = rgb888torgb565(32, 191, 17),
        .BUTTON_LIGHTER_INACTIVE = 0,
        .WINDOWS_BORDER = rgb888torgb565(249, 205, 46),
        .WINDOWS_BG = COLOR_BLACK,
        .KEYBOARD_BG = rgb888torgb565(20, 20, 20),
        .IFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .IFGAIN_BAR_FG = rgb888torgb565(255, 0, 0),
        .AFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .AFGAIN_BAR_FG = rgb888torgb565(0, 255, 0),
    },

    {
        // CN+Green
        // 2 - black, 7-segments FREQ
        // 3'2 inch
        .BACKGROUND = COLOR_BLACK,
        .FOREGROUND = COLOR_WHITE,
        .BUTTON_TEXT = COLOR_GREEN,
        .BUTTON_INACTIVE_TEXT = COLOR_WHITE,
        .BUTTON_BACKGROUND = rgb888torgb565(10, 10, 30),

        .FREQ_MHZ = COLOR_GREEN,
        .FREQ_KHZ = COLOR_GREEN,
        .FREQ_HZ = COLOR_GREEN,

        .STATUS_VFO = COLOR_WHITE,
        .STATUS_VFO_BG = rgb888torgb565(255, 50, 0),
        .STATUS_BAR_LEFT = rgb888torgb565(100, 100, 255),
        .STATUS_BAR_RIGHT = rgb888torgb565(255, 100, 100),
        .STATUS_BAR_LABELS = rgb888torgb565(32, 171, 17),
        .STATUS_RX = COLOR_GREEN,
        .STATUS_TX = COLOR_RED,
        .STATUS_TU = rgb888torgb565(249, 205, 46),
        .STATUS_LABELS_BW = COLOR_WHITE,
        .STATUS_LABELS_TX = rgb888torgb565(32, 171, 17),
        .STATUS_LABEL_S_VAL = COLOR_YELLOW,
        .STATUS_LABEL_DBM = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_BW = rgb888torgb565(0, 200, 255),
        .STATUS_LABEL_RIT = COLOR_WHITE,
        .STATUS_LABEL_THERM = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_NOTCH = rgb888torgb565(0, 200, 255),
        .STATUS_SMETER = rgb888torgb565(249, 205, 46),
        .STATUS_SMETER_HIGH = rgb888torgb565(249, 150, 46),
        .STATUS_SMETER_STRIPE = COLOR_GREEN,
        .STATUS_SMETER_PEAK = COLOR_RED,
        .STATUS_SMETER_FM_SQL = rgb888torgb565(129, 135, 247),
        .STATUS_MODE = rgb888torgb565(249, 205, 46),
        .STATUS_ERR = COLOR_RED,
        .STATUS_INFO_BORDER = COLOR_RED,
        .BANDMAP_CW = rgb888torgb565(50, 50, 255),
        .BANDMAP_SSB = rgb888torgb565(50, 237, 255),
        .BANDMAP_DIGI = rgb888torgb565(255, 50, 50),
        .BANDMAP_AM = rgb888torgb565(219, 255, 50),
        .BANDMAP_FM = rgb888torgb565(255, 50, 208),
        .GREETINGS = rgb888torgb565(0, 92, 86),
        .TOOLTIP_FORE = COLOR_WHITE,
        .TOOLTIP_BACK = COLOR_RED,
        .TOOLTIP_BORD = COLOR_YELLOW,
        .CLOCK = COLOR_WHITE,
        .FFT_GRADIENT_START_R = 0,
        .FFT_GRADIENT_START_G = 11,
        .FFT_GRADIENT_START_B = 40,
        .FFT_GRADIENT_END_R = 46,
        .FFT_GRADIENT_END_G = 77,
        .FFT_GRADIENT_END_B = 158,
        .WTF_BG_WHITE = false,
        .BW_TRAPEZ_BORDER = rgb888torgb565(120, 120, 120),
        .BW_TRAPEZ_STRIPE = rgb888torgb565(255, 0, 0),
        .BW_TRAPEZ_FILL = rgb888torgb565(140, 140, 140),
        .ACTIVE_BORDER = rgb888torgb565(0, 102, 153),
        // 7inch

        .FREQ_B_MHZ = COLOR_YELLOW,
        .FREQ_B_KHZ = COLOR_YELLOW,
        .FREQ_B_HZ = COLOR_YELLOW,

        .FREQ_A_INACTIVE = rgb888torgb565(100, 100, 100),
        .FREQ_B_INACTIVE = rgb888torgb565(100, 100, 100),

        .STATUS_LABEL_ACTIVE = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_INACTIVE = rgb888torgb565(90, 90, 90),
        .BUTTON_BACK = rgb888torgb565(10, 10, 40),
        .BUTTON_BORDER = rgb888torgb565(105, 105, 105),
        .BUTTON_LIGHTER_ACTIVE = rgb888torgb565(32, 191, 17),
        .BUTTON_LIGHTER_INACTIVE = 0,
        .WINDOWS_BORDER = rgb888torgb565(249, 205, 46),
        .WINDOWS_BG = COLOR_BLACK,
        .KEYBOARD_BG = rgb888torgb565(20, 20, 20),
        .IFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .IFGAIN_BAR_FG = rgb888torgb565(255, 0, 0),
        .AFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .AFGAIN_BAR_FG = rgb888torgb565(0, 255, 0),
    },

    {
        // CN+White
        // 2 - black, 7-segments FREQ
        // 3'2 inch
        .BACKGROUND = COLOR_BLACK,
        .FOREGROUND = COLOR_WHITE,
        .BUTTON_TEXT = COLOR_GREEN,
        .BUTTON_INACTIVE_TEXT = COLOR_WHITE,
        .BUTTON_BACKGROUND = rgb888torgb565(20, 20, 20),

        .FREQ_MHZ = COLOR_WHITE,
        .FREQ_KHZ = COLOR_WHITE,
        .FREQ_HZ = COLOR_WHITE,

        .STATUS_VFO = COLOR_WHITE,
        .STATUS_VFO_BG = rgb888torgb565(255, 50, 0),
        .STATUS_BAR_LEFT = rgb888torgb565(100, 100, 255),
        .STATUS_BAR_RIGHT = rgb888torgb565(255, 100, 100),
        .STATUS_BAR_LABELS = rgb888torgb565(32, 171, 17),
        .STATUS_RX = COLOR_GREEN,
        .STATUS_TX = COLOR_RED,
        .STATUS_TU = rgb888torgb565(249, 205, 46),
        .STATUS_LABELS_BW = COLOR_WHITE,
        .STATUS_LABELS_TX = rgb888torgb565(32, 171, 17),
        .STATUS_LABEL_S_VAL = COLOR_YELLOW,
        .STATUS_LABEL_DBM = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_BW = rgb888torgb565(0, 200, 255),
        .STATUS_LABEL_RIT = COLOR_WHITE,
        .STATUS_LABEL_THERM = rgb888torgb565(249, 205, 46),
        .STATUS_LABEL_NOTCH = rgb888torgb565(0, 200, 255),
        .STATUS_SMETER = rgb888torgb565(249, 205, 46),
        .STATUS_SMETER_HIGH = rgb888torgb565(249, 150, 46),
        .STATUS_SMETER_STRIPE = COLOR_WHITE,
        .STATUS_SMETER_PEAK = COLOR_GREEN,
        .STATUS_SMETER_FM_SQL = rgb888torgb565(129, 135, 247),
        .STATUS_MODE = rgb888torgb565(249, 205, 46),
        .STATUS_ERR = COLOR_RED,
        .STATUS_INFO_BORDER = COLOR_RED,
        .BANDMAP_CW = rgb888torgb565(50, 50, 255),
        .BANDMAP_SSB = rgb888torgb565(50, 237, 255),
        .BANDMAP_DIGI = rgb888torgb565(255, 50, 50),
        .BANDMAP_AM = rgb888torgb565(219, 255, 50),
        .BANDMAP_FM = rgb888torgb565(255, 50, 208),
        .GREETINGS = rgb888torgb565(0, 92, 86),
        .TOOLTIP_FORE = COLOR_WHITE,
        .TOOLTIP_BACK = COLOR_RED,
        .TOOLTIP_BORD = COLOR_YELLOW,
        .CLOCK = COLOR_WHITE,
        .FFT_GRADIENT_START_R = 0,
        .FFT_GRADIENT_START_G = 11,
        .FFT_GRADIENT_START_B = 40,
        .FFT_GRADIENT_END_R = 46,
        .FFT_GRADIENT_END_G = 77,
        .FFT_GRADIENT_END_B = 158,
        .WTF_BG_WHITE = false,
        .BW_TRAPEZ_BORDER = rgb888torgb565(120, 120, 120),
        .BW_TRAPEZ_STRIPE = rgb888torgb565(255, 0, 0),
        .BW_TRAPEZ_FILL = rgb888torgb565(140, 140, 140),
        .ACTIVE_BORDER = rgb888torgb565(0, 102, 153),
        // 7inch

        .FREQ_B_MHZ = COLOR_WHITE,
        .FREQ_B_KHZ = COLOR_WHITE,
        .FREQ_B_HZ = COLOR_WHITE,

        .FREQ_A_INACTIVE = rgb888torgb565(90, 90, 90),
        .FREQ_B_INACTIVE = rgb888torgb565(90, 90, 90),

        .STATUS_LABEL_ACTIVE = rgb888torgb565(32, 191, 17),
        .STATUS_LABEL_INACTIVE = rgb888torgb565(90, 90, 90),
        .BUTTON_BACK = rgb888torgb565(60, 45, 60),
        .BUTTON_BORDER = rgb888torgb565(105, 105, 105),
        .BUTTON_LIGHTER_ACTIVE = rgb888torgb565(32, 191, 17),
        .BUTTON_LIGHTER_INACTIVE = 0,
        .WINDOWS_BORDER = rgb888torgb565(249, 205, 46),
        .WINDOWS_BG = COLOR_BLACK,
        .KEYBOARD_BG = rgb888torgb565(20, 20, 20),
        .IFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .IFGAIN_BAR_FG = rgb888torgb565(255, 0, 0),
        .AFGAIN_BAR_BG = rgb888torgb565(129, 135, 247),
        .AFGAIN_BAR_FG = rgb888torgb565(0, 255, 0),
    }};

#define BG_COLOR COLOR->BACKGROUND
#define FG_COLOR COLOR->FOREGROUND

// LCD dimensions defines
#include "screen_layout.h"

#endif
