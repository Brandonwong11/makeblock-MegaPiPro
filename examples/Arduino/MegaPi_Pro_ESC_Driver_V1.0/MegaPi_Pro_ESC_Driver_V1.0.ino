#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMegaPiPro.h>
MeMegaPiProESCMotor bldcmotor_1(1);

void setup(){
    TCCR1A = _BV(WGM10);//PIN12
    TCCR1B = _BV(CS11) | _BV(CS10) | _BV(WGM12);
    bldcmotor_1.init();
}

void loop(){
    bldcmotor_1.run(abs(50));
    delay(2);
    bldcmotor_1.run(abs(0));
    delay(2);
    loop();
}
