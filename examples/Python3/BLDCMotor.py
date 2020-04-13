from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
bldc = board.BLDCMotor(MegaPiPro.PORT1)
while True:
    bldc.run(50)
    sleep(2)
    bldc.run(0)
    sleep(1)
    bldc.run(-50)
    sleep(2)
    bldc.run(0)
    sleep(1)