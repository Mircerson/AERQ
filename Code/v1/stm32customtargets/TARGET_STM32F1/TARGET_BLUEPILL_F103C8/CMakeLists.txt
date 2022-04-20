# Copyright (c) 2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(mbed-bluepill-f103c8 INTERFACE)

target_sources(mbed-bluepill-f103c8
    INTERFACE
        PeripheralPins.c
)

target_include_directories(mbed-bluepill-f103c8
    INTERFACE
        .
)

target_link_libraries(mbed-bluepill-f103c8 INTERFACE mbed-stm32f103x8)
