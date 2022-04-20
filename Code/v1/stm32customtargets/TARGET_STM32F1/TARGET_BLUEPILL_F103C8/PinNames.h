/* mbed Microcontroller Library
 * SPDX-License-Identifier: BSD-3-Clause
 ******************************************************************************
 *
 * Copyright (c) 2016-2020 STMicroelectronics.
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 *
 * Automatically generated from STM32CubeMX/db/mcu/STM32F103C(8-B)Tx.xml
 */

/* MBED TARGET LIST: BLUEPILL_F103C8 */

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
    PA_3       = 0x03,
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
    PB_0_ALT0  = PB_0  | ALT0, // same pin used for alternate HW
    PB_1       = 0x11,
    PB_1_ALT0  = PB_1  | ALT0, // same pin used for alternate HW
    PB_2       = 0x12,
    PB_3       = 0x13,
    PB_4       = 0x14,
    PB_5       = 0x15,
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
    PC_13      = 0x2D,
    PC_14      = 0x2E,
    PC_15      = 0x2F,
    PD_0       = 0x30,
    PD_1       = 0x31,

    // ADC internal channels
    ADC_TEMP = 0xF0,
    ADC_VREF = 0xF1,

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

    //USB pins
    USB_DM = PA_11,
    USB_DP = PA_12,

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;


// Standardized LED and button names
#define LED1     PC_13


// PCB printout
#define A0  PA_0,
#define A1  PA_1,
#define A2  PA_2,
#define A3  PA_3,
#define A4  PA_4,
#define A5  PA_5,
#define A6  PA_6,
#define A7  PA_7,
#define A8  PA_8,
#define A9  PA_9,
#define A10 PA_10,
#define A11 PA_11,
#define A12 PA_12,
#define A15 PA_15,

// #define B0  PB_0, // compilation issue with platform/cxxsupport/mstd_type_traits
// #define B1  PB_1, // compilation issue with platform/cxxsupport/mstd_type_traits
// #define B2  PB_2, // compilation issue with platform/cxxsupport/mstd_type_traits
// #define B3  PB_3, // compilation issue with platform/cxxsupport/mstd_type_traits
// #define B4  PB_4, // compilation issue with platform/cxxsupport/mstd_type_traits
#define B5  PB_5,
#define B6  PB_6,
#define B7  PB_7,
#define B8  PB_8,
#define B9  PB_9,
#define B10 PB_10,
#define B11 PB_11,
#define B12 PB_12,
#define B13 PB_13,
#define B14 PB_14,
#define B15 PB_15,

#define C13 PC_13,
#define C14 PC_14,
#define C15 PC_15,


// Default pin alias
#define I2C_SCL     = B6,
#define I2C_SDA     = B7,
#define SPI_MOSI    = A7,
#define SPI_MISO    = A6,
#define SPI_SCK     = A5,
#define SPI_CS      = A4,
#define PWM_OUT     = B5,


#ifdef __cplusplus
}
#endif

#endif
