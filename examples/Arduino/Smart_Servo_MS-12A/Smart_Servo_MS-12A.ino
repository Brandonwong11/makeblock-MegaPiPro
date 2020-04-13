#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMegaPiPro.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);
MeEncoderOnBoard Encoder_3(SLOT3);
MeEncoderOnBoard Encoder_4(SLOT4);
void isr_process_encoder1(void)
{
    if(digitalRead(Encoder_1.getPortB()) == 0){
        Encoder_1.pulsePosMinus();
    }else{
        Encoder_1.pulsePosPlus();
    }
}
void isr_process_encoder2(void)
{
    if(digitalRead(Encoder_2.getPortB()) == 0){
        Encoder_2.pulsePosMinus();
    }else{
        Encoder_2.pulsePosPlus();
    }
}
void isr_process_encoder3(void)
{
    if(digitalRead(Encoder_3.getPortB()) == 0){
        Encoder_3.pulsePosMinus();
    }else{
        Encoder_3.pulsePosPlus();
    }
}
void isr_process_encoder4(void)
{
    if(digitalRead(Encoder_4.getPortB()) == 0){
        Encoder_4.pulsePosMinus();
    }else{
        Encoder_4.pulsePosPlus();
    }
}
MeSmartServo mysmartservo(PORT5);



void setup(){
    TCCR1A = _BV(WGM10);//PIN12
    TCCR1B = _BV(CS11) | _BV(CS10) | _BV(WGM12);
    
    TCCR2A = _BV(WGM21) | _BV(WGM20);//PIN8
    TCCR2B = _BV(CS22);
    
    TCCR3A = _BV(WGM30);//PIN9
    TCCR3B = _BV(CS31) | _BV(CS30) | _BV(WGM32);
    
    TCCR4A = _BV(WGM40);//PIN5
    TCCR4B = _BV(CS41) | _BV(CS40) | _BV(WGM42);
    
    mysmartservo.begin(115200);
    mysmartservo.assignDevIdRequest();
    delay(50);
    mysmartservo.begin(115200);
    mysmartservo.assignDevIdRequest();
    mysmartservo.setInitAngle(1);
    _delay(1);
    
}

void loop(){
    
    mysmartservo.moveTo(1,30,30);
    delay(1);
    mysmartservo.moveTo(1,120,30);
    delay(1);
    
    loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

