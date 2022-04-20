# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(mbed-rak3172-breakout INTERFACE)

target_include_directories(mbed-rak3172-breakout
    INTERFACE
        .
)

target_link_libraries(mbed-rak3172-breakout INTERFACE
    mbed-stm32wle5xc
    mbed-rak3172
)
