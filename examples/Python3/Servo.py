from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
servo = board.Servo(MegaPiPro.PORT6,MegaPiPro.SLOT1)
while True:
    servo.set_angle(30)
    sleep(1)
    servo.set_angle(120)
    sleep(1)