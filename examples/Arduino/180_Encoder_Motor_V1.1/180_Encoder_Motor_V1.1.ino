#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMegaPiPro.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);
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

void setup(){
    TCCR1A = _BV(WGM10);//PIN12
    TCCR1B = _BV(CS11) | _BV(CS10) | _BV(WGM12);
    TCCR2A = _BV(WGM21) | _BV(WGM20);//PIN8
    TCCR2B = _BV(CS22);
    attachInterrupt(Encoder_1.getIntNum(), isr_process_encoder1, RISING);
    attachInterrupt(Encoder_2.getIntNum(), isr_process_encoder2, RISING);
}

void loop(){
    Encoder_1.setTarPWM(100);
    Encoder_2.setTarPWM(100);
    delay(1);
    Encoder_1.setTarPWM(0);
    Encoder_2.setTarPWM(0);
    delay(1);
    loop();
}
