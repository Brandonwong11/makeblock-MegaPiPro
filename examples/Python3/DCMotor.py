from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
motor = board.DCMotor(MegaPiPro.PORT1,MegaPiPro.SLOT1)
while True:
    motor.run(50)
    sleep(2)
    motor.run(0)
    sleep(1)
    motor.run(-50)
    sleep(2)
    motor.run(0)
    sleep(1)