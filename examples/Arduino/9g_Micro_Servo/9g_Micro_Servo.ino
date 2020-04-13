#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "analog_servo.h"
#include <MeMegaPiPro.h>

Servo servo_6_1;

void setup(){
    servo_6_1.attach(port_pro(6,1)+A0);}

void loop(){
    servo_6_1.write(30);    _delay(1);
    servo_6_1.write(120);    _delay(1);
    _loop();
}
