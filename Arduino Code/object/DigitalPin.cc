#include <DigitalPin.hh>

DigitalPin::DigitalPin(const uint8_t& pin)
: pin_(pin) {}

void DigitalPin::setup(const uint8_t& mode) const {
  pinMode(pin_, mode);
}

void DigitalPin::write(const uint8_t& value) const {
	digitalWrite(pin_, value);
}

auto DigitalPin::read(void) const {
	return digitalRead(pin_);
}
