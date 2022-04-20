/* mbed Microcontroller Library
 * SPDX-License-Identifier: BSD-3-Clause
 ******************************************************************************
 *
 * Copyright (c) 2016-2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 *
 * Automatically generated from STM32CubeMX/db/mcu/STM32WLE5CCUx.xml
 */

/* MBED TARGET LIST: RAK3172, RAK3172_BREAKOUT */

#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#include "cmsis.h"
#include "PinNamesTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ALT0  = 0x100,
} ALTx;

typedef enum {
    PA_0       = 0x00,
    PA_1       = 0x01,
    PA_1_ALT0  = PA_1  | ALT0, // same pin used for alternate HW
    PA_2       = 0x02,
    PA_2_ALT0  = PA_2  | ALT0, // same pin used for alternate HW
    PA_3       = 0x03,
    PA_3_ALT0  = PA_3  | ALT0, // same pin used for alternate HW
    PA_4       = 0x04,
    PA_5       = 0x05,
    PA_6       = 0x06,
    PA_7       = 0x07,
    PA_7_ALT0  = PA_7  | ALT0, // same pin used for alternate HW
    PA_8       = 0x08,
    PA_9       = 0x09,
    PA_10      = 0x0A,
    PA_11      = 0x0B,
    PA_12      = 0x0C,
    PA_13      = 0x0D,
    PA_14      = 0x0E,
    PA_15      = 0x0F,
    PB_0       = 0x10,
    PB_2       = 0x12,
    PB_3       = 0x13,
    PB_4       = 0x14,
    PB_5       = 0x15,
    PB_6       = 0x16,
    PB_7       = 0x17,
    PB_8       = 0x18,
    PB_8_ALT0  = PB_8  | ALT0, // same pin used for alternate HW
    PB_12      = 0x1C,
    PC_13      = 0x2D,
    PC_14      = 0x2E,
    PC_15      = 0x2F,
    PH_3       = 0x73,

    /**** ADC internal channels ****/

    ADC_TEMP = 0xF0, // Internal pin virtual value
    ADC_VREF = 0xF1, // Internal pin virtual value
    ADC_VBAT = 0xF2, // Internal pin virtual value

    // STDIO for console print
#ifdef MBED_CONF_TARGET_STDIO_UART_TX
    CONSOLE_TX = MBED_CONF_TARGET_STDIO_UART_TX,
#else
    CONSOLE_TX = PA_2,
#endif
#ifdef MBED_CONF_TARGET_STDIO_UART_RX
    CONSOLE_RX = MBED_CONF_TARGET_STDIO_UART_RX,
#else
    CONSOLE_RX = PA_3,
#endif

    /**** OSCILLATOR pins ****/
    RCC_OSC32_IN = PC_14,
    RCC_OSC32_OUT = PC_15,

    /**** DEBUG pins ****/
    DEBUG_JTCK_SWCLK = PA_14,
    DEBUG_JTDI = PA_15,
    DEBUG_JTDO_SWO = PB_3,
    DEBUG_JTMS_SWDIO = PA_13,
    DEBUG_JTRST = PB_4,
    DEBUG_PWR_LDORDY = PA_2,
    DEBUG_PWR_REGLP1S = PA_0,
    DEBUG_PWR_REGLP2S = PA_1,
    DEBUG_RF_BUSY = PA_12,
    DEBUG_RF_DTB1 = PB_3,
    DEBUG_RF_HSE32RDY = PA_10,
    DEBUG_RF_LDORDY = PB_4,
    DEBUG_RF_NRESET = PA_11,
    DEBUG_RF_SMPSRDY = PB_2,
    DEBUG_SUBGHZSPI_MISOOUT = PA_6,
    DEBUG_SUBGHZSPI_MOSIOUT = PA_7,
    DEBUG_SUBGHZSPI_NSSOUT = PA_4,
    DEBUG_SUBGHZSPI_SCKOUT = PA_5,
    PWR_PVD_IN = PB_7,
    SYS_PWR_WKUP1 = PA_0,
    SYS_PWR_WKUP2 = PC_13,
    SYS_PWR_WKUP3 = PB_3,

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;

// Legacy I2C aliases
#define I2C_SDA  PA_11
#define I2C_SCL  PA_12
// Legacy SPI aliases
#define SPI_CS   PA_4
#define SPI_MOSI PA_7
#define SPI_MISO PA_6
#define SPI_SCK  PA_5

#ifdef __cplusplus
}
#endif

#endif
