#include "pico/stdlib.h"

#define LOW 0
#define HIGH 1
#define OUTPUT GPIO_OUT
#define INPUT GPIO_IN

#define digitalRead(pin) gpio_get(pin)?HIGH:LOW
#define digitalWrite(pin, value) gpio_put(pin, value)
#define pinMode(pin, mode) gpio_set_dir(pin, mode)
#define delay(time) sleep_ms(time)
#define delayMicroseconds(time) sleep_us(time)

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C