# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(mbed-stwin INTERFACE)

target_sources(mbed-stwin
    INTERFACE
        PeripheralPins.c
)

target_include_directories(mbed-stwin
    INTERFACE
        .
)

target_link_libraries(mbed-stwin INTERFACE mbed-stm32l4r9xi)
