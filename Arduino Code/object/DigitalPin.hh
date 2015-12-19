#ifndef _DigitalPin_HH

#define _DigitalPin_HH

class DigitalPin {

public:

	DigitalPin(const uint8_t& pin);
  void setup(const uint8_t& mode);
  void write(const uint8_t& value);
  int read(void);

protected:

	uint8_t pin_;

};

#endif
