/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2018, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */

#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#include "cmsis.h"
#include "PinNamesTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ALT0  = 0x100,
    ALT1  = 0x200,
    ALT2  = 0x300,
    ALT3  = 0x400
} ALTx;

typedef enum {
    PA_0  = 0x00,
    PA_0_ALT0 = PA_0 | ALT0,
    PA_0_ALT1 = PA_0 | ALT1,
    PA_1  = 0x01,
    PA_1_ALT0 = PA_1 | ALT0,
    PA_1_ALT1 = PA_1 | ALT1,
    PA_2  = 0x02,
    PA_2_ALT0 = PA_2 | ALT0,
    PA_2_ALT1 = PA_2 | ALT1,
    PA_3  = 0x03,
    PA_3_ALT0 = PA_3 | ALT0,
    PA_3_ALT1 = PA_3 | ALT1,
    PA_4  = 0x04,
    PA_4_ALT0 = PA_4 | ALT0,
    PA_5  = 0x05,
    PA_5_ALT0 = PA_5 | ALT0,
    PA_6  = 0x06,
    PA_6_ALT0 = PA_6 | ALT0,
    PA_7  = 0x07,
    PA_7_ALT0 = PA_7 | ALT0,
    PA_7_ALT1 = PA_7 | ALT1,
    PA_7_ALT2 = PA_7 | ALT2,
    PA_8  = 0x08,
    PA_9  = 0x09,
    PA_10 = 0x0A,
    PA_11 = 0x0B,
    PA_12 = 0x0C,
    PA_13 = 0x0D,
    PA_14 = 0x0E,
    PA_15 = 0x0F,
    PA_15_ALT0 = PA_15 | ALT0,

    PB_0  = 0x10,
    PB_0_ALT0 = PB_0 | ALT0,
    PB_0_ALT1 = PB_0 | ALT1,
    PB_1  = 0x11,
    PB_1_ALT0 = PB_1 | ALT0,
    PB_1_ALT1 = PB_1 | ALT1,
    PB_2  = 0x12,
    PB_3  = 0x13,
    PB_3_ALT0 = PB_3 | ALT0,
    PB_4  = 0x14,
    PB_4_ALT0 = PB_4 | ALT0,
    PB_4_ALT1 = PB_4 | ALT1,
    PB_5  = 0x15,
    PB_5_ALT0 = PB_5 | ALT0,
    PB_5_ALT1 = PB_5 | ALT1,
    PB_6  = 0x16,
    PB_7  = 0x17,
    PB_8  = 0x18,
    PB_8_ALT0 = PB_8 | ALT0,
    PB_8_ALT1 = PB_8 | ALT1,
    PB_9  = 0x19,
    PB_9_ALT0 = PB_9 | ALT0,
    PB_9_ALT1 = PB_9 | ALT1,
    PB_10 = 0x1A,
    PB_11 = 0x1B,
    PB_12 = 0x1C,
    PB_13 = 0x1D,
    PB_14 = 0x1E,
    PB_14_ALT0 = PB_14 | ALT0,
    PB_14_ALT1 = PB_14 | ALT1,
    PB_15 = 0x1F,
    PB_15_ALT0 = PB_15 | ALT0,
    PB_15_ALT1 = PB_15 | ALT1,

    PC_0  = 0x20,
    PC_0_ALT0 = PC_0 | ALT0,
    PC_0_ALT1 = PC_0 | ALT1,
    PC_1  = 0x21,
    PC_1_ALT0 = PC_1 | ALT0,
    PC_1_ALT1 = PC_1 | ALT1,
    PC_2  = 0x22,
    PC_2_ALT0 = PC_2 | ALT0,
    PC_2_ALT1 = PC_2 | ALT1,
    PC_3  = 0x23,
    PC_3_ALT0 = PC_3 | ALT0,
    PC_3_ALT1 = PC_3 | ALT1,
    PC_4  = 0x24,
    PC_4_ALT0 = PC_4 | ALT0,
    PC_5  = 0x25,
    PC_5_ALT0 = PC_5 | ALT0,
    PC_6  = 0x26,
    PC_6_ALT0 = PC_6 | ALT0,
    PC_7  = 0x27,
    PC_7_ALT0 = PC_7 | ALT0,
    PC_8  = 0x28,
    PC_8_ALT0 = PC_8 | ALT0,
    PC_9  = 0x29,
    PC_9_ALT0 = PC_9 | ALT0,
    PC_10 = 0x2A,
    PC_10_ALT0 = PC_10 | ALT0,
    PC_11 = 0x2B,
    PC_11_ALT0 = PC_11 | ALT0,
    PC_12 = 0x2C,
    PC_13 = 0x2D,
    PC_14 = 0x2E,
    PC_15 = 0x2F,

    PD_0  = 0x30,
    PD_1  = 0x31,
    PD_2  = 0x32,
    PD_3  = 0x33,
    PD_4  = 0x34,
    PD_5  = 0x35,
    PD_6  = 0x36,
    PD_7  = 0x37,
    PD_8  = 0x38,
    PD_9  = 0x39,
    PD_10 = 0x3A,
    PD_11 = 0x3B,
    PD_12 = 0x3C,
    PD_13 = 0x3D,
    PD_14 = 0x3E,
    PD_15 = 0x3F,

    PE_0  = 0x40,
    PE_1  = 0x41,
    PE_2  = 0x42,
    PE_3  = 0x43,
    PE_4  = 0x44,
    PE_5  = 0x45,
    PE_6  = 0x46,
    PE_7  = 0x47,
    PE_8  = 0x48,
    PE_9  = 0x49,
    PE_10 = 0x4A,
    PE_11 = 0x4B,
    PE_12 = 0x4C,
    PE_13 = 0x4D,
    PE_14 = 0x4E,
    PE_15 = 0x4F,

    PF_0  = 0x50,
    PF_1  = 0x51,
    PF_2  = 0x52,
    PF_3  = 0x53,
    PF_4  = 0x54,
    PF_5  = 0x55,
    PF_6  = 0x56,
    PF_7  = 0x57,
    PF_8  = 0x58,
    PF_9  = 0x59,
    PF_10 = 0x5A,
    PF_11 = 0x5B,
    PF_12 = 0x5C,
    PF_13 = 0x5D,
    PF_14 = 0x5E,
    PF_15 = 0x5F,

    PG_0  = 0x60,
    PG_1  = 0x61,
    PG_2  = 0x62,
    PG_3  = 0x63,
    PG_4  = 0x64,
    PG_5  = 0x65,
    PG_6  = 0x66,
    PG_7  = 0x67,
    PG_8  = 0x68,
    PG_9  = 0x69,
    PG_10 = 0x6A,
    PG_11 = 0x6B,
    PG_12 = 0x6C,
    PG_13 = 0x6D,
    PG_14 = 0x6E,
    PG_15 = 0x6F,

    PH_0  = 0x70,
    PH_1  = 0x71,
    PH_2  = 0x72,
    PH_3  = 0x73,
    PH_4  = 0x74,
    PH_5  = 0x75,
    PH_6  = 0x76,
    PH_7  = 0x77,
    PH_8  = 0x78,
    PH_9  = 0x79,
    PH_10 = 0x7A,
    PH_11 = 0x7B,
    PH_12 = 0x7C,
    PH_13 = 0x7D,
    PH_14 = 0x7E,
    PH_15 = 0x7F,

    PI_0  = 0x80,
    PI_1  = 0x81,
    PI_2  = 0x82,
    PI_3  = 0x83,
    PI_4  = 0x84,
    PI_5  = 0x85,
    PI_6  = 0x86,
    PI_7  = 0x87,
    PI_8  = 0x88,
    PI_9  = 0x89,
    PI_10 = 0x8A,
    PI_11 = 0x8B,
    PI_12 = 0x8C,
    PI_13 = 0x8D,
    PI_14 = 0x8E,
    PI_15 = 0x8F,

    // ADC internal channels
    ADC_TEMP = 0xF0,
    ADC_VREF = 0xF1,
    ADC_VBAT = 0xF2,

    /**** USB pins ****/
    USB_OTG_FS_DM = PA_11,
    USB_OTG_FS_DP = PA_12,

    /**** OSCILLATOR pins ****/
    RCC_OSC32_IN = PC_14,
    RCC_OSC32_OUT = PC_15,
    RCC_OSC_IN = PH_0,
    RCC_OSC_OUT = PH_1,

    /**** DEBUG pins ****/
    SYS_JTCK_SWCLK = PA_14,
    SYS_JTDI = PA_15,
    SYS_JTMS_SWDIO = PA_13,

    // STDIO for console print
#ifdef MBED_CONF_TARGET_STDIO_UART_TX
    CONSOLE_TX = MBED_CONF_TARGET_STDIO_UART_TX,
#else
    CONSOLE_TX = PB_10,
#endif
#ifdef MBED_CONF_TARGET_STDIO_UART_RX
    CONSOLE_RX = MBED_CONF_TARGET_STDIO_UART_RX,
#else
    CONSOLE_RX = PB_11,
#endif

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;

// Standardized LED and button names
#define LED1        PE_2  // [L1]
#define LED2        PE_3  // [L2]
#define LED3        PE_4  // [L3]
#define BUTTON1     PG_12 // [hBtn1]
#define BUTTON2     PG_13 // [hBtn2]

// hSensor1 port pins
#define SENS1_PIN1 PA_2
#define SENS1_PIN1_ALT0 PA_2_ALT0
#define SENS1_PIN1_ALT1 PA_2_ALT1
#define SENS1_PIN2 PG_3
#define SENS1_PIN3 PB_8
#define SENS1_PIN3_ALT0 PB_8_ALT0
#define SENS1_PIN3_ALT1 PB_8_ALT1
#define SENS1_PIN4 PB_9
#define SENS1_PIN4_ALT0 PB_9_ALT0
#define SENS1_PIN4_ALT1 PB_9_ALT1

// hSensor2 port pins
#define SENS2_PIN1 PA_6
#define SENS2_PIN1_ALT0 PA_6_ALT0
#define SENS2_PIN2 PC_8
#define SENS2_PIN2_ALT0 PC_8_ALT0
#define SENS2_PIN3 PA_8
#define SENS2_PIN4 PC_9
#define SENS2_PIN4_ALT0 PC_9_ALT0

// hSensor3 port pins
#define SENS3_PIN1 PC_4
#define SENS3_PIN1_ALT0 PC_4_ALT0
#define SENS3_PIN2 PG_2
#define SENS3_PIN3 PC_12         // UART_5_TX
#define SENS3_PIN3_UART_TX PC_12 // UART_5_TX
#define SENS3_PIN4 PD_2          // UART_5_RX
#define SENS3_PIN4_UART_RX PD_2  // UART_5_RX

// hSensor4 port pins
#define SENS4_PIN1 PC_5
#define SENS4_PIN1_ALT0 PC_5_ALT0
#define SENS4_PIN2 PD_15
#define SENS4_PIN3 PG_14         // USART_6_TX
#define SENS4_PIN3_UART_TX PG_14 // USART_6_TX
#define SENS4_PIN4 PG_9          // USART_6_RX
#define SENS4_PIN4_UART_RX PG_9  // USART_6_RX

// hSensor5 port pins
#define SENS5_PIN1 PB_0
#define SENS5_PIN1_ALT0 PB_0_ALT0
#define SENS5_PIN1_ALT1 PB_0_ALT1
#define SENS5_PIN2 PD_14
#define SENS5_PIN3 PD_13
#define SENS5_PIN4 PD_12

// hSensor6 port pins
#define SENS6_PIN1 PB_1
#define SENS6_PIN2 PD_8
#define SENS6_PIN3 PD_10
#define SENS6_PIN4 PD_9

#define SENS_POWER_ON PG_4 // SENSOR 5V REGULATOR TOGGLE

// hExt port pins
#define EXT_PIN1 PF_3
#define EXT_PIN2 PF_10
#define EXT_PIN3 PF_4
#define EXT_PIN4 PF_5
#define EXT_PIN5 PC_0
#define EXT_PIN5_ALT0 PC_0_ALT0
#define EXT_PIN5_ALT1 PC_0_ALT1
#define EXT_PIN6 PD_6  // USART_2_RX
#define EXT_PIN7 PD_5  // USART_2_TX
#define EXT_PIN8 PB_13 // SCK SPI
#define EXT_PIN9 PC_2  // MISO SPI
#define EXT_PIN9_ALT0 PC_2_ALT0
#define EXT_PIN9_ALT1 PC_2_ALT1
#define EXT_PIN10 PC_3 // MOSI SPI
#define EXT_PIN10_ALT0 PC_3_ALT0
#define EXT_PIN10_ATL1 PC_3_ALT1
#define EXT_PIN11 PF_0 // SDA I2C
#define EXT_PIN12 PF_1 // SCL I2C

// Legacy SPI aliases
#define I2C_SCL SENS1_PIN3
#define I2C_SDA SENS1_PIN4
#define SPI_MOSI EXT_PIN10
#define SPI_MISO EXT_PIN9
#define SPI_SCK  EXT_PIN8

// SBC port pins
#define SBC_SERIAL_TX PA_9
#define SBC_SERIAL_RX PA_10
#define SBC_CONSOLE PG_5
#define SBC_STATUS PG_6
#define SBC_BTN PG_7

// CAN pins
#define CAN_TX PD_1
#define CAN_RX PD_0
#define CAN_EN PA_15

// USB-B/USB-micro FTDI pins
#define FT_SERIAL_TX PB_10
#define FT_SERIAL_RX PB_11
#define FT_CBUS3 PD_11

// HOST USB pins
#define USB_DM PA_11
#define USB_DP PA_12
#define USB_CHARGE PE_8
#define USB_CHARGE_IND PE_7

// SD reader pins
#define SD_MOSI PB_5_ALT0
#define SD_MISO PC_11
#define SD_CLK PC_10
#define SD_CS PB_3_ALT0
#define SD_IN PG_15
#define SD_POWER_ON PD_7

// SERVO pins
#define SERVO1_PWM PE_9
#define SERVO2_PWM PE_11
#define SERVO3_PWM PE_13
#define SERVO4_PWM PE_14
#define SERVO5_PWM PB_15
#define SERVO5_PWM_ALT0 PB_15_ALT0
#define SERVO5_PWM_ALT1 PB_15_ALT1
#define SERVO6_PWM PB_14
#define SERVO6_PWM_ALT0 PB_14_ALT0
#define SERVO6_PWM_ALT1 PB_14_ALT1
#define SERVO_ADC PA_3
#define SERVO_ADC_ALT0 PA_3_ALT0
#define SERVO_ADC_ALT1 PA_3_ALT1
#define SERVO_SEL1 PE_10
#define SERVO_SEL2 PE_12
#define SERVO_POWER_ON PE_15

// Battery and BOOT pins
#define BAT_MEAS PA_5           //  VIN SUPPLY MEASURMENT

#define BAT_MEAS_ALT0 PA_5_ALT0 // UPPER_RESISTOR: 56kOhm
                                // LOWER_RESISTOR: 10kOhm
                                // Volts = ((2 * ADC_READ))/2520 * (UPPER_RESISTOR + LOWER_RESISTOR) / LOWER_RESISTOR; 
#define BOOT1 PB_2

// hMot1 port pins
#define MOT1_PWM PF_6
#define MOT1A_IN PG_10
#define MOT1B_IN PG_11
#define MOT1A_ENC PA_0
#define MOT1A_ENC_ALT0 PA_0_ALT0
#define MOT1A_ENC_ALT1 PA_0_ALT1
#define MOT1B_ENC PA_1

// hMot2 port pins
#define MOT2_PWM PF_7
#define MOT2A_IN PD_3
#define MOT2B_IN PD_4
#define MOT2A_ENC PC_6
#define MOT2A_ENC_ALT0 PC_6_ALT0
#define MOT2B_ENC PC_7
#define MOT2B_ENC_ALT0 PC_7_ALT0

// hMot3 port pins
#define MOT3_PWM PF_8
#define MOT3A_IN PC_15
#define MOT3B_IN PF_2
#define MOT3A_ENC PB_4
#define MOT3A_ENC_ALT0 PB_4_ALT0
#define MOT3A_ENC_ALT1 PB_4_ALT1
#define MOT3B_ENC PA_7
#define MOT3B_ENC_ALT0 PA_7_ALT0
#define MOT3B_ENC_ALT1 PA_7_ALT1
#define MOT3B_ENC_ALT2 PA_7_ALT2

// hMot4 port pins
#define MOT4_PWM PF_9
#define MOT4A_IN PE_5
#define MOT4B_IN PE_6
#define MOT4A_ENC PB_6
#define MOT4B_ENC PB_7

#define MOT12_SLEEP PC_13
#define MOT12_FAULT PE_0
#define MOT34_SLEEP PC_14
#define MOT34_FAULT PE_1

#ifdef __cplusplus
}
#endif

#endif
