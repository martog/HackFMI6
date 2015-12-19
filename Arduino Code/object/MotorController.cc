#include <MotorController.hh>

MotorController::MotorController(const uint8_t& left, const uint8_t& right, const uint8_t& forward, const uint8_t& backward)
: left_(left), right_(right), forward_(forward), backward_(backward) {}

void MotorController::setup(void) {
  left_.setup(OUTPUT);
  right_.setup(OUTPUT);
  forward_.setup(OUTPUT);
  backward_.setup(OUTPUT);
}

void MotorController::go_left(void) {
  left_.write(HIGH);
}

void MotorController::stop_left(void) {
  left_.write(LOW);
}

void MotorController::go_right(void) {
  right_.write(HIGH);
}

void MotorController::stop_right(void) {
  right_.write(LOW);
}

void MotorController::go_forward(void) {
  forward_.write(HIGH);
}

void MotorController::stop_forward(void) {
  forward_.write(LOW);
}

void MotorController::go_backward(void) {
  backward_.write(HIGH);
}

void MotorController::stop_backward(void) {
  backward_.write(LOW);
}
