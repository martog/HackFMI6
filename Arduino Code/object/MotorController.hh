#ifndef _MotorController_HH

#define _MotorController_HH

#include <DigitalPin.hh>

class MotorController {

public:

	MotorController(const uint8_t& left, const uint8_t& right, const uint8_t& forward, const uint8_t& backward);
  void setup(void);
  void go_left(void);
  void stop_left(void);
  void go_right(void);
  void stop_right(void);
  void go_forward(void);
  void stop_forward(void);
  void go_backward(void);
  void stop_backward(void);

protected:

	DigitalPin left_;
  DigitalPin right_;
  DigitalPin forward_;
  DigitalPin backward_;

};

#endif
