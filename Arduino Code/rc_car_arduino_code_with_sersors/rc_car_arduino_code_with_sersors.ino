
#include <RBL_services.h>
#include <SPI.h>
#include <EEPROM.h>
#include <boards.h>
#include <RBL_nRF8001.h>
#include <Thread.h>
#include <ThreadController.h>

#define forward 6  // Pin 6 - Forward
#define backward 5 	// Pin 5 - Backward
#define right 4 //Pin 4 - Right
#define left 3 //Pin 3 - Left
#define trigPin 7 //sensor
#define echoPin 2 //sensor



unsigned char val;

// ThreadController that will controll all threads
ThreadController controll = ThreadController();
Thread distanceThread = Thread();

void setup()
{
    
  ble_set_name("My RC Car"); // The name have to be under 10 letters

  Serial.begin(9600);
  
  pinMode(echoPin,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);

  distanceThread.onRun(distance_sensor);
  distanceThread.setInterval(500);
  controll.add(&distanceThread);
  
  ble_begin();
}

void go_forward() {
  digitalWrite(forward, HIGH);
}

void go_backward(){
  digitalWrite(backward, HIGH);
}

void go_right(){
  digitalWrite(right, HIGH);
}

void go_left(){
  digitalWrite(left, HIGH);
}

void stop_right() {
  digitalWrite(right, LOW);
}

void stop_left() {
  digitalWrite(left, LOW);
}

void stop_forward() {
  digitalWrite(forward, LOW);
}

void stop_backward() {
  digitalWrite(backward, LOW);
}

void distance_sensor() {
  int duration, distance;
  unsigned char bytes[4];
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000); //pauses the program for 1 millisecond
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print('\n');
  //ble_write(distance); 
 // ble_write_bytes(bytes,5);
}

void loop()
{
  
  if (ble_available())
  {
    val = ble_read(); //receives data from android device
    //ble_write(val); //sends data to android device
    if(val == 'f'){
      go_forward();
    }else if(val == 'b'){
      go_backward();
    }else if(val == 'r'){
      go_right();
    }else if(val == 'l'){
      go_left();
    }else if(val == 'k'){
      stop_forward();
    }else if(val == 'j'){
      stop_right();
    }else if(val == 'h'){
      stop_left();
    }else if(val == 'g'){
      stop_backward();
    } 
  }
  
  ble_do_events();
  
  controll.run();
}
