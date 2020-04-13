from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
smartservo = board.SmartServo()
while True:
    smartservo.move_to(1,720,50)
    sleep(4)
    smartservo.move_to(1,0,50)
    sleep(4)
