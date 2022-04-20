# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(mbed-lora-e5-breakout INTERFACE)

target_include_directories(mbed-lora-e5-breakout
    INTERFACE
        .
)

target_link_libraries(mbed-lora-e5-breakout INTERFACE
    mbed-stm32wle5xc
    mbed-lora-e5
)
