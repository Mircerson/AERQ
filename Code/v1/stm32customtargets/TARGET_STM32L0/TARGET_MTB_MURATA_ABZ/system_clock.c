/* mbed Microcontroller Library
* Copyright (c) 2006-2017 ARM Limited
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/**
  * This file configures the system clock as follows:
  *-----------------------------------------------------------------
  * System clock source | internal 16 MHz
  *-----------------------------------------------------------------
  * SYSCLK(MHz)         | 32
  * AHBCLK (MHz)        | 32
  * APB1CLK (MHz)       | 32
  * USB capable         | YES
  *-----------------------------------------------------------------
  */

#include "stm32l0xx.h"
#include "mbed_error.h"

uint8_t SetSysClock_PLL_HSI(void);


/**
  * @brief  Configures the System clock source, PLL Multiplier and Divider factors,
  *               AHB/APBx prescalers and Flash settings
  * @note   This function should be called only once the RCC clock configuration
  *         is reset to the default reset state (done in SystemInit() function).
  * @param  None
  * @retval None
  */
void SetSysClock(void)
{
    if (SetSysClock_PLL_HSI() == 0) {
        {
            error("SetSysClock failed\n");
        }
    }

    /* Output clock on MCO1 pin(PA8) for debugging purpose */
    //HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_SYSCLK, RCC_MCODIV_1);
    //HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSI48, RCC_MCODIV_1);
}

/******************************************************************************/
/*            PLL (clocked by HSI) used as System clock source                */
/******************************************************************************/
uint8_t SetSysClock_PLL_HSI(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit;

    /* The voltage scaling allows optimizing the power consumption when the device is
       clocked below the maximum system frequency, to update the voltage scaling value
       regarding system frequency refer to product datasheet. */
    __PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /* Enable HSI and HSI48 oscillators and activate PLL with HSI as source */
    RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_HSI48;
    RCC_OscInitStruct.HSEState            = RCC_HSE_OFF;
    RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.HSI48State          = RCC_HSI48_ON; /* For USB and RNG clock */
    // PLLCLK = (16 MHz * 4)/2 = 32 MHz
    RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLMUL          = RCC_PLLMUL_4;
    RCC_OscInitStruct.PLL.PLLDIV          = RCC_PLLDIV_2;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        return 0; // FAIL
    }

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
    RCC_ClkInitStruct.ClockType      = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK; // 32 MHz
    RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;         // 32 MHz
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;           // 32 MHz
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;           // 32 MHz
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
        return 0; // FAIL
    }

    RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
    RCC_PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;
    if (HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit) != HAL_OK) {
        return 0; // FAIL
    }

    /* Output clock on MCO1 pin(PA8) for debugging purpose */
    //HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSI, RCC_MCODIV_1); // 16 MHz

    return 1; // OK
}

