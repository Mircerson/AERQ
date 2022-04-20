# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(mbed-mtb-murata-abz INTERFACE)

target_sources(mbed-mtb-murata-abz
    INTERFACE
        PeripheralPins.c
        system_clock.c
)

target_include_directories(mbed-mtb-murata-abz
    INTERFACE
        .
)

target_link_libraries(mbed-mtb-murata-abz INTERFACE mbed-stm32l082xz)
