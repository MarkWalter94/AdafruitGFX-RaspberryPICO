cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(AdafruitGFXPico C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_library(AdafruitGFXPico
    Adafruit_I2CDevice.cpp
    Adafruit_SPIDevice.cpp
    Print.cpp
    Adafruit_GFX.cpp    
    Adafruit_SSD1306.cpp
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(AdafruitGFXPico pico_stdlib hardware_spi hardware_i2c)

target_include_directories(AdafruitGFXPico PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(AdafruitGFXPico PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}\\Fonts)
