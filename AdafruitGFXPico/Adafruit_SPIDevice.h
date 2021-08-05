#include "hardware/spi.h"

#ifndef Adafruit_SPIDevice_h
#define Adafruit_SPIDevice_h

typedef enum _BitOrder {
  SPI_BITORDER_MSBFIRST = SPI_MSB_FIRST,
  SPI_BITORDER_LSBFIRST = SPI_LSB_FIRST,
} BusIOBitOrder;

#undef BUSIO_USE_FAST_PINIO


/**! The class which defines how we will talk to this device over SPI **/
class Adafruit_SPIDevice {
public:
  Adafruit_SPIDevice(int8_t cspin, int8_t sck, int8_t miso, int8_t mosi,
                     uint32_t freq = 1000000,
                     BusIOBitOrder dataOrder = SPI_BITORDER_MSBFIRST,
                     uint8_t dataMode = 0, spi_inst_t *theSPI = spi_default);
  ~Adafruit_SPIDevice();
  void setSpeed(uint32_t newSpeed);
  bool begin(void);
  bool read(uint8_t *buffer, size_t len, uint8_t sendvalue = 0xFF);
  bool write(uint8_t *buffer, size_t len, uint8_t *prefix_buffer = NULL,
             size_t prefix_len = 0);
  bool write_then_read(uint8_t *write_buffer, size_t write_len,
                       uint8_t *read_buffer, size_t read_len,
                       uint8_t sendvalue = 0xFF);

  uint8_t transfer(uint8_t send);
  void transfer(uint8_t *buffer, size_t len);
  void beginTransaction(void);
  void endTransaction(void);

private:
  spi_inst_t *_spi;
  uint32_t _freq;
  BusIOBitOrder _dataOrder;
  uint8_t _dataMode;

  int8_t _cs, _sck, _mosi, _miso;
  bool _begun;
};

#endif // Adafruit_SPIDevice_h
