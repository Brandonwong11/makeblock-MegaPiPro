from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
smartservo = board.SmartServo()
while True:
    smartservo.move(1,720,50)
    sleep(4)
    smartservo.move(1,-720,50)
    sleep(4)
