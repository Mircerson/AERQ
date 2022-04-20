# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(mbed-gnat INTERFACE)

target_include_directories(mbed-gnat
    INTERFACE
        .
)

target_link_libraries(mbed-gnat INTERFACE 
    mbed-stm32l082xz
    mbed-mtb-murata-abz
)
