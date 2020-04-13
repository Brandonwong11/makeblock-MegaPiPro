from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
encoder = board.EncoderMotor(MegaPiPro.PORT1)
while True:
    encoder.run(50)
    sleep(2)
    encoder.run(0)
    sleep(1)
    encoder.run(-50)
    sleep(2)
    encoder.run(0)
    sleep(1)