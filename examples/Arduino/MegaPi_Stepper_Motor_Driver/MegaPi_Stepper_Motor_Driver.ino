#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMegaPiPro.h>
MeStepperOnBoard stepper_1(1);

void setup(){
    TCCR1A = _BV(WGM10);//PIN12
    TCCR1B = _BV(CS11) | _BV(CS10) | _BV(WGM12);
    stepper_1.setMicroStep(16);
    stepper_1.enableOutputs();
}

void loop(){
    stepper_1.move(1000);
    stepper_1.setMaxSpeed(3000);
    stepper_1.setSpeed(3000);
    delay(1);
    stepper_1.move(0);
    stepper_1.setMaxSpeed(0);
    stepper_1.setSpeed(0);
    delay(1);
    loop();
}
