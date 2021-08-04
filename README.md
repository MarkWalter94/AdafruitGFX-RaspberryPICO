# AdafruitGFX-RaspberryPICO
Porting of the [ADAFRUIT GFX library](https://github.com/adafruit/Adafruit-GFX-Library) for the [raspberry PICO](https://www.raspberrypi.org/products/raspberry-pi-pico/)

# How to use the library
1. Put the folder AdafruitGFX of this repository under your project
1. Add the library to your CMakeLists project with the [add_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html) command.
1. Use it.

See main.cpp in the root of the repo for an example of use.

# Supported and tested displays
1. SSD1306, SSD1309

# Roadmap
1. Enforce testing, add implementation for TFT and other displays.
