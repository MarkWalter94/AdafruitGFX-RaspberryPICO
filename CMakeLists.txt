cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(AdafruitGFXPicoTest C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(AdafruitGFXPico)

add_executable(AdafruitGFXPicoTest
    main.cpp
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(AdafruitGFXPicoTest pico_stdlib hardware_spi AdafruitGFXPico)

# enable usb output, disable uart output
pico_enable_stdio_usb(AdafruitGFXPicoTest 1)
pico_enable_stdio_uart(AdafruitGFXPicoTest 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(AdafruitGFXPicoTest)
