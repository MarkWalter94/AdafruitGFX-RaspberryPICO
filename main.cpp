#include "pico/stdlib.h"
#include "hardware/spi.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_SPIDevice.h>
#define CS 17
#define DC 20
#define RST 21
#define MISO PICO_DEFAULT_SPI_RX_PIN
#define MOSI PICO_DEFAULT_SPI_TX_PIN
#define SCLK PICO_DEFAULT_SPI_SCK_PIN
#define SDA 18
// #define SCL 19
#define BITRATE 1000 * 1000 //1 MHz
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64


//Adafruit_I2CDevice _i2cdev(0x3C, SDA, SCL, &i2c1_inst, BITRATE);
Adafruit_SPIDevice _spidev(CS, SCLK, MISO, MOSI, BITRATE);
Adafruit_SSD1306 _display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &_spidev, DC, RST, CS);
int main()
{
    stdio_init_all();
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    _display.begin();
    //Shows splash screen
    _display.display();
    sleep_ms(10000);

    _display.clearDisplay();
    _display.setTextColor(WHITE);
    _display.print("Henlo doggo");
    _display.display();

    uint32_t cnt = 0;
    uint8_t dec = 56;
    while (dec--)
    {
        gpio_put(25, 1);
        _display.print(cnt++);
        _display.print(" ");
        _display.display();
    }
    gpio_put(25, 0);
    while (2 > 1)
    {
        for (uint8_t i = 0; i < DISPLAY_WIDTH/2; ++i)
        {
            _display.fillCircle(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, i, WHITE);
            _display.display();
        }
        _display.clearDisplay();

        for (uint8_t i = DISPLAY_WIDTH/2; i > 0; --i)
        {
            _display.clearDisplay();
            _display.fillCircle(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, i, WHITE);
            _display.display();
        }
        _display.clearDisplay();
        _display.display();
    }
}