/* mbed Microcontroller Library
 * SPDX-License-Identifier: BSD-3-Clause
 ******************************************************************************
 *
 * Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "STM32WL_radio_driver.h"
#include "drivers/DigitalOut.h"


/* Sets up radio switch position according to the radio mode */
/* This configuration is for LORA-E5 */
void set_antenna_switch(RBI_Switch_TypeDef state)
{

    // Radio specific controls (TX/RX duplexer switch control)
    mbed::DigitalOut _rf_switch_ctrl1(PA_4);
    mbed::DigitalOut _rf_switch_ctrl2(PA_5);

    switch (state) {
        case RBI_SWITCH_OFF: {
            /* Turn off switch */
            _rf_switch_ctrl1 = 0;
            _rf_switch_ctrl2 = 0;
            break;
        }
        case RBI_SWITCH_RX: {
            /*Turns On in Rx Mode the RF Switch */
            _rf_switch_ctrl1 = 1;
            _rf_switch_ctrl2 = 0;
            break;
        }
        case RBI_SWITCH_RFO_LP: {
            /* This mode does not exists on this target  */
            /* so configure as HP only */
            /*Turns On in Tx High Power the RF Switch */
            _rf_switch_ctrl1 = 0;
            _rf_switch_ctrl2 = 1;
            break;
        }
        case RBI_SWITCH_RFO_HP: {
            /*Turns On in Tx High Power the RF Switch */
            _rf_switch_ctrl1 = 0;
            _rf_switch_ctrl2 = 1;
            break;
        }
        default:
            break;
    }
}

