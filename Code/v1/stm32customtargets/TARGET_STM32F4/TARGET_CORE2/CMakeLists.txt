add_library(mbed-core2 INTERFACE)

target_sources(mbed-core2
    INTERFACE
        PeripheralPins.c
        system_clock.c
)

target_include_directories(mbed-core2
    INTERFACE
        .
)

target_link_libraries(mbed-core2 INTERFACE mbed-stm32f407xg)
