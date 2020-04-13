from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
stepper = board.StepperMotor(MegaPiPro.PORT1)
while True:
    stepper.run(50)
    sleep(2)
    stepper.run(0)
    sleep(1)
    stepper.run(-50)
    sleep(2)
    stepper.run(0)
    sleep(1)