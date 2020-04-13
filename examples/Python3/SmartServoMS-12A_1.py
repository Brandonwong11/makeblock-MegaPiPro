from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
smartservo = board.SmartServo()
while True:
    smartservo.run(1,10)
    sleep(2)
    smartservo.run(1,0)
    sleep(1)
    smartservo.run(1,-10)
    sleep(2)
    smartservo.run(1,0)
    sleep(1)
