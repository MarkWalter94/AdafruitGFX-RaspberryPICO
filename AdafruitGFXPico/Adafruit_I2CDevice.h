#ifndef Adafruit_I2CDevice_h
#define Adafruit_I2CDevice_h
#include "hardware/i2c.h"


///< The class which defines how we will talk to this device over I2C
class Adafruit_I2CDevice {
public:
  Adafruit_I2CDevice(uint8_t addr, uint8_t sdaPin, uint8_t sclPin, i2c_inst_t *theWire = i2c_default, uint32_t speed = 500000);
  uint8_t address(void);
  bool begin(uint8_t addr, bool addr_detect = true);
  bool detected(void);

  bool read(uint8_t *buffer, size_t len, bool stop = true);
  bool write(const uint8_t *buffer, size_t len, bool stop = true,
             const uint8_t *prefix_buffer = NULL, size_t prefix_len = 0);
  bool writeRaw(const uint8_t *buffer, size_t len, bool stop = true);
  bool write_then_read(const uint8_t *write_buffer, size_t write_len,
                       uint8_t *read_buffer, size_t read_len,
                       bool stop = false);
  bool setSpeed(uint32_t desiredclk);

  /*!   @brief  How many bytes we can read in a transaction
   *    @return The size of the Wire receive/transmit buffer */
  size_t maxBufferSize() { return _maxBufferSize; }

private:
  uint8_t _addr, _sdaPin, _sclPin;
  i2c_inst_t *_wire;
  bool _begun;
  size_t _maxBufferSize;
  uint32_t _speed;
};

#endif // Adafruit_I2CDevice_h
