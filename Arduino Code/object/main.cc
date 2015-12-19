#include <RBL_services.h>
#include <SPI.h>
#include <EEPROM.h>
#include <boards.h>
#include <RBL_nRF8001.h>
#include <Thread.h>
#include <ThreadController.h>
#include <DigitalPin.hh>
#include <MotorController.hh>

#define echoPin 2

ThreadController controll = ThreadController();
Thread distanceThread = Thread();
MotorController motor = MotorController(3, 4, 6, 5);
DigitalPin trigPin = DigitalPin(7);

void setup(void) {
  motor.setup();
  trigPin.setup(OUTPUT);
  distanceThread.onRun(distance_sensor);
  distanceThread.setInterval(500);
  controll.add(&distanceThread);
  ble_begin();
}

void distance_sensor() {
  int duration, distance;
  unsigned char bytes[4];
  trigPin.write(HIGH);
  delayMicroseconds(1000); //pauses the program for 1 millisecond
  trigPin.write(LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print('\n');
  for(int i = 3;i >= 0;--i)
		bytes[3 - i] = (distance >> i * 8) & 255;
  //ble_write(distance);
 // ble_write_bytes(bytes,5);
}

void loop(void) {
  if(ble_available())
    switch(ble_read())
      case "l": motor.go_left();
      break;
      case "h": motor.stop_left();
      break;
      case "r": motor.go_right();
      break;
      case "j": motor.stop_right();
      break;
      case "f": motor.go_forward();
      break;
      case "k": motor.stop_forward();
      break;
      case "b": motor.go_backward();
      break;
      case "g": motor.stop_backward();
      break;
}
