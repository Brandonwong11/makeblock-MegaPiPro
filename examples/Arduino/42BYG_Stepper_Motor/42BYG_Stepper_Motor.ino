#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMegaPiPro.h>
MeDCMotor dcfourmotor_1(1);

void loop(){
    dcfourmotor_1.run(255);
    delay(1);
    dcfourmotor_1.run(0);
    delay(1);
    loop();
}
