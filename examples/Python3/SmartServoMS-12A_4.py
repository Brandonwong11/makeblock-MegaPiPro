from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
smartservo = board.SmartServo()
while True:
    smartservo.set_led(1,50,0,0)
    sleep(0.5)
    smartservo.set_led(1,0,50,0)
    sleep(0.5)
    smartservo.set_led(1,0,0,50)
    sleep(0.5)
