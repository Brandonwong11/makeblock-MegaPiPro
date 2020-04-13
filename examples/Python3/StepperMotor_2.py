from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
stepper = board.StepperMotor(MegaPiPro.PORT1)
position = 0
def on_finished(value):
    position = 5000 - position
    stepper.move_to(position,100,on_finished)

on_finished(position)