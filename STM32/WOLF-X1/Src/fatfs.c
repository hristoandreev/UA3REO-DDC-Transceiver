/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file   fatfs.c
 * @brief  Code for fatfs applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
#include "fatfs.h"
#include "hardware.h"

uint8_t retUSER;  /* Return value for USER */
char USERPath[4]; /* USER logical drive path */
FATFS USERFatFS;  /* File system object for USER logical drive */
FIL USERFile;     /* File object for USER */

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

void MX_FATFS_Init(void) {
	/* USER CODE BEGIN Init */
	/* additional user code for init */
	/* USER CODE END Init */
}

/**
 * @brief  Gets Time from RTC
 * @param  None
 * @retval Time in DWORD
 */
DWORD get_fattime(void) {
	/* USER CODE BEGIN get_fattime */
	RTC_TimeTypeDef sTime = {0};
	RTC_DateTypeDef sDate = {0};
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	// get time
	return ((DWORD)(2000 + sDate.Year - 1980) << 25) | ((DWORD)sDate.Month << 21) | ((DWORD)sDate.Date << 16) | ((DWORD)sTime.Hours << 11) | ((DWORD)sTime.Minutes << 5) |
	       ((DWORD)sTime.Seconds >> 1);
	/* USER CODE END get_fattime */
}

/* USER CODE BEGIN Application */

/* USER CODE END Application */
