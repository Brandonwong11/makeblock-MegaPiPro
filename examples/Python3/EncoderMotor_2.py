from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
encoder = board.EncoderMotor(MegaPiPro.PORT1)
position = 0
def on_finished(value):
    position = 5000 - position
    encoder.move_to(position,100,on_finished)

on_finished(position)