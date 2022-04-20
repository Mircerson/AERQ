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
 * Automatically generated from STM32CubeMX/db/mcu/STM32L082CZUx.xml
 */

/* MBED TARGET LIST: MTB_MURATA_ABZ */

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
    PA_2       = 0x02,
    PA_2_ALT0  = PA_2  | ALT0, // same pin used for alternate HW
    PA_3       = 0x03,
    PA_3_ALT0  = PA_3  | ALT0, // same pin used for alternate HW
    PA_4       = 0x04,
    PA_5       = 0x05,
    PA_6       = 0x06,
    PA_6_ALT0  = PA_6  | ALT0, // same pin used for alternate HW
    PA_7       = 0x07,
    PA_7_ALT0  = PA_7  | ALT0, // same pin used for alternate HW
    PA_8       = 0x08,
    PA_9       = 0x09,
    PA_10      = 0x0A,
    PA_11      = 0x0B,
    PA_12      = 0x0C,
    PA_13      = 0x0D,
    PA_14      = 0x0E,
    PA_14_ALT0 = PA_14 | ALT0, // same pin used for alternate HW
    PA_15      = 0x0F,
    PB_0       = 0x10,
    PB_1       = 0x11,
    PB_2       = 0x12,
    PB_3       = 0x13,
    PB_4       = 0x14,
    PB_4_ALT0  = PB_4  | ALT0, // same pin used for alternate HW
    PB_5       = 0x15,
    PB_5_ALT0  = PB_5  | ALT0, // same pin used for alternate HW
    PB_6       = 0x16,
    PB_7       = 0x17,
    PB_8       = 0x18,
    PB_9       = 0x19,
    PB_10      = 0x1A,
    PB_11      = 0x1B,
    PB_12      = 0x1C,
    PB_13      = 0x1D,
    PB_14      = 0x1E,
    PB_15      = 0x1F,
    PC_0       = 0x20,
    PC_1       = 0x21,
    PC_2       = 0x22,
    PC_13      = 0x2D,
    PC_14      = 0x2E,
    PC_15      = 0x2F,
    PH_0       = 0x70,
    PH_1       = 0x71,

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


    /**** USB pins ****/
    USB_DM = PA_11,
    USB_DP = PA_12,

    /**** OSCILLATOR pins ****/
    RCC_OSC32_IN = PC_14,
    RCC_OSC32_OUT = PC_15,
    RCC_OSC_IN = PH_0,
    RCC_OSC_OUT = PH_1,

    /**** DEBUG pins ****/
    SYS_PVD_IN = PB_7,
    SYS_SWCLK = PA_14,
    SYS_SWDIO = PA_13,
    SYS_VREF_OUT_PB0 = PB_0,
    SYS_VREF_OUT_PB1 = PB_1,
    SYS_WKUP1 = PA_0,
    SYS_WKUP2 = PC_13,

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;


// Standardized LED and button names
#define LED1     PB_12   // Blue
#define BUTTON1  PB_5    // Button

// Aliases
#define I2C_SCL     PB_8
#define I2C_SDA     PB_9

#define SPI_MOSI    PB_15   // Also Connected to LoRa DIO4
#define SPI_MISO    PB_14
#define SPI_SCK     PB_13
#define SPI_CS      PB_12

#define LORA_SPI_MOSI   PA_7
#define LORA_SPI_MISO   PA_6
#define LORA_SPI_SCLK   PB_3
#define LORA_CS         PA_15
#define LORA_RESET      PC_0
#define LORA_DIO0       PB_4
#define LORA_DIO1       PB_1
#define LORA_DIO2       PB_0
#define LORA_DIO3       PC_13
#define LORA_ANT_RX     PA_1
#define LORA_ANT_TX     PC_2
#define LORA_ANT_BOOST  PC_1
#define LORA_VDD_TXCO   PB_14

#define D0      PA_10
#define D1      PA_9
#define D2      PB_5    // User Button
#define D3      PB_6    // BMA400 Interrupt 2
#define D4      PB_7    // GNSS PPS
#define D5      PB_2    // Enable GNSS
#define D8      PA_13
#define D9      PA_14
#define D10     PB_12
#define D11     PB_15
#define D12     PB_14
#define D13     PB_13

#define A0      PA_4    // GNSS VDD Backup
#define A1      PA_5    // Battery Voltage
#define A2      PA_2
#define A3      PA_3
#define A4      PA_0    // BMA400 Interrupt 1

#define TX2     PA_2    // Console TX
#define RX2     PA_3    // Console RX

#define TX3     PA_14
#define RX3     PA_13

#define PIN_VBUS           PA_8
#define PIN_VBAT           A1
#define PIN_GNSS_ENABLE    D5
#define PIN_GNSS_BACKUP    A0
#define PIN_GNSS_PPS       D4
#define PIN_GNSS_RX        PA_10
#define PIN_GNSS_TX        PA_9

#define BMA400_INT1        A4
#define BMA400_INT2        D3


#ifdef __cplusplus
}
#endif

#endif
