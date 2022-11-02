/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    ARMCMx/compilers/GCC/crt1.c
 * @brief   Startup stub functions.
 *
 * @addtogroup ARMCMx_GCC_STARTUP
 * @{
 */

#include <stdint.h>
#include <stdbool.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

#if !defined(CRT0_EXTRA_CORES_NUMBER) || defined(__DOXYGEN__)
#define CRT0_EXTRA_CORES_NUMBER             0
#endif

#if !defined(CRT0_AREAS_NUMBER) || defined(__DOXYGEN__)
#define CRT0_AREAS_NUMBER                   3
#endif

#if (CRT0_AREAS_NUMBER < 0) || (CRT0_AREAS_NUMBER > 5)
#error "CRT0_AREAS_NUMBER must be within 0 and 5"
#endif

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/**
 * @brief   Type of an area to be initialized.
 */
typedef struct {
  uint32_t              *init_text_area;
  uint32_t              *init_area;
  uint32_t              *clear_area;
//  uint32_t              *no_init_area;
} ram_init_area_t;

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

#if (CRT0_AREAS_NUMBER > 0) || defined(__DOXYGEN__)
extern uint32_t __iram_init_text__, __iram_init__, __iram_clear__;
#endif
#if (CRT0_AREAS_NUMBER > 1) || defined(__DOXYGEN__)
extern uint32_t __sram_init_text__, __sram_init__, __sram_clear__;
#endif
#if (CRT0_AREAS_NUMBER > 2) || defined(__DOXYGEN__)
extern uint32_t __sram4_init_text__, __sram4_init__, __sram4_clear__;
#endif
#if (CRT0_AREAS_NUMBER > 3) || defined(__DOXYGEN__)
extern uint32_t __itcmram_init_text__, __itcmram_init__, __itcmram_clear__;
#endif
#if (CRT0_AREAS_NUMBER > 4) || defined(__DOXYGEN__)
extern uint32_t __backup_sram_init_text__, __backup_sram_init__, __backup_sram_clear__;
#endif

/**
 * @brief   Static table of areas to be initialized.
 */
#if (CRT0_AREAS_NUMBER > 0) || defined(__DOXYGEN__)
static const ram_init_area_t ram_areas[CRT0_AREAS_NUMBER] = {
  {&__iram_init_text__, &__iram_init__, &__iram_clear__},
#if (CRT0_AREAS_NUMBER > 1) || defined(__DOXYGEN__)
  {&__sram_init_text__, &__sram_init__, &__sram_clear__},
#endif
#if (CRT0_AREAS_NUMBER > 2) || defined(__DOXYGEN__)
  {&__sram4_init_text__, &__sram4_init__, &__sram4_clear__},
#endif
#if (CRT0_AREAS_NUMBER > 3) || defined(__DOXYGEN__)
  {&__itcmram_init_text__, &__itcmram_init__, &__itcmram_clear__},
#endif
#if (CRT0_AREAS_NUMBER > 4) || defined(__DOXYGEN__)
  {&__backup_sram_init_text__, &__backup_sram_init__, &__backup_sram_clear__},
#endif
};
#endif

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Architecture-dependent core initialization.
 * @details This hook is invoked immediately after the stack initialization
 *          and before the DATA and BSS segments initialization.
 * @note    This function is a weak symbol.
 */
#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void __cpu_init(void) {

#if CORTEX_MODEL == 7

#endif
}

/**
 * @brief   Early initialization.
 * @details This hook is invoked immediately after the stack and core
 *          initialization and before the DATA and BSS segments
 *          initialization.
 * @note    This function is a weak symbol.
 */
#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void __early_init(void) {}
/*lint -restore*/

/**
 * @brief   Late initialization.
 * @details This hook is invoked after the DATA and BSS segments
 *          initialization and before any static constructor. The
 *          default behavior is to do nothing.
 * @note    This function is a weak symbol.
 */
#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void __late_init(void) {}
/*lint -restore*/

/**
 * @brief   Default @p main() function exit handler.
 * @details This handler is invoked or the @p main() function exit. The
 *          default behavior is to enter an infinite loop.
 * @note    This function is a weak symbol.
 */
#if !defined(__DOXYGEN__)
__attribute__((noreturn, weak))
#endif
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void __default_exit(void) {
/*lint -restore*/

  while (true) {
  }
}

#if (CRT0_EXTRA_CORES_NUMBER > 0) || defined(__DOXYGEN__)
#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void __c1_cpu_init(void) {

#if CORTEX_MODEL == 7
  SCB_EnableICache();
  SCB_EnableDCache();
#endif
}

#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void __c1_early_init(void) {}
/*lint -restore*/

#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void __c1_late_init(void) {}
/*lint -restore*/

#if !defined(__DOXYGEN__)
__attribute__((noreturn, weak))
#endif
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void __c1_default_exit(void) {
/*lint -restore*/

  while (true) {
  }
}
#endif

/**
 * @brief   Performs the initialization of the various RAM areas.
 */
void __init_ram_areas(void) {
#if CRT0_AREAS_NUMBER > 0
  const ram_init_area_t *rap = ram_areas;

  do {
    uint32_t *tp = rap->init_text_area;
    uint32_t *p = rap->init_area;

    /* Copying initialization data.*/
    while (p < rap->clear_area) {
      *p = *tp;
      p++;
      tp++;
    }

    /* Zeroing clear area.*/
//    while (p < rap->no_init_area) {
//      *p = 0;
//      p++;
//    }
    rap++;
  }
  while (rap < &ram_areas[CRT0_AREAS_NUMBER]);
#endif
}

/** @} */
