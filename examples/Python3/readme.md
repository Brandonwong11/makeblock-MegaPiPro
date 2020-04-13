MegaPi Pro主控板Python接口<br>
====
准备工作  
----
第1步：安装最新的makeblock库，"pip3 install makeblock --upgrade"  
第2步：使用 usb 数据线，连接光环板到电脑设备。  
第3步： 将如下代码复制到代码编辑中，点击运行  
from makeblock import MegaPiPro  
board = MegaPiPro.create()  
API 列表  
----
舵机<br>
----
Servo(port,slot)<br>
创建舵机对象。<br>
参数：<br>
• port: MegaPiPro.PORT5 ~ MegaPiPro.PORT8<br>
• slot: MegaPiPro.SLOT1 ~ MegaPiPro.SLOT2<br>
set_angle(angle)<br>
设置舵机旋转角度<br>
参数：<br>
• angle:旋转角度，范围：0 ~ 180°<br>
程序示例<br>
from time import sleep<br>
from makeblock import MegaPiPro <br>
board = MegaPiPro.create()<br>
servo = board.Servo(MegaPiPro.PORT6,MegaPiPro.SLOT1)<br>
while True:<br>
    servo.set_angle(30)<br>
    sleep(1)<br>
    servo.set_angle(120)<br>
    sleep(1)<br>
直流电机<br>
----
DCMotor(port,slot)<br>
创建直流电机对象。<br>
参数：<br>
• port: MegaPiPro.PORT1 ~ MegaPiPro.PORT4<br>
• slot: MegaPiPro.SLOT1 ~ MegaPiPro.SLOT2<br>
run(speed)<br>
以百分比速度旋转<br>
参数：<br>
• speed:速度百分比，范围：-100 ~ 100<br>
程序示例<br>
from time import sleep<br>
from makeblock import MegaPiPro <br>
board = MegaPiPro.create()<br>
motor = board.DCMotor(MegaPiPro.PORT1,MegaPiPro.SLOT1)<br>
while True:<br>
    motor.run(50)<br>
    sleep(2)<br>
    motor.run(0)<br>
    sleep(1)<br>
    motor.run(-50)<br>
    sleep(2)<br>
    motor.run(0)<br>
    sleep(1)<br>
直流编码电机<br>
----
EncoderMotor(port)<br>
创建直流编码电机对象。<br>
参数：<br>
• port: MegaPiPro.PORT1 ~ MegaPiPro.PORT4<br>
run(speed)<br>
以指定速度旋转<br>
参数：<br>
• speed:转速，单位？<br>
程序示例<br>
from time import sleep<br>
from makeblock import MegaPiPro <br>
board = MegaPiPro.create()
encoder = board.EncoderMotor(MegaPiPro.PORT1)<br>
while True:<br>
    encoder.run(50)<br>
    sleep(2)<br>
    encoder.run(0)<br>
    sleep(1)<br>
    encoder.run(-50)<br>
    sleep(2)<br>
    encoder.run(0)<br>
    sleep(1)<br>
move_to(position,speed,callback)<br>
以指定速度旋转到指定位置<br>
参数：<br>
• position:目标位置<br>
• speed:转速，单位？<br>
• callback:达到目标位置时触发回调<br>
程序示例<br>
from time import sleep<br>
from makeblock import MegaPiPro <br>
board = MegaPiPro.create()<br>
encoder = board.EncoderMotor(MegaPiPro.PORT1)<br>
position = 0<br>
def on_finished(value):<br>
    position = 5000 - position<br>
    encoder.move_to(position,100,on_finished)<br>
on_finished(position)<br>
set_home()<br>
设置当前位置为原点<br>
步进电机<br>
----
StepperMotor(port)<br>
创建步进电机对象。<br>
参数：
• port: MegaPiPro.PORT1 ~ MegaPiPro.PORT4
run(speed)
以指定速度旋转
参数：
• speed:转速，单位？
程序示例
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
move_to(position,speed,callback)
以指定速度旋转到指定位置
参数：
• position:目标位置
• speed:转速，单位？
• callback:达到目标位置时触发回调
程序示例
from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
stepper = board.StepperMotor(MegaPiPro.PORT1)
position = 0
def on_finished(value):
    position = 5000 - position
    stepper.move_to(position,100,on_finished)
on_finished(position)
set_home()
设置当前位置为原点
智能舵机
----
SmartServo(port)
创建智能舵机对象。
参数：
• port: 接口，默认MegaPiPro.PORT5
run(index,pwm)
设置动力大小
参数：
• index:舵机序号
• pwm:PWM占空比，范围-100～100
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
move_to(index,position,speed)
按指定速度移动到绝对角度
参数：
• index:舵机序号
• position:目标角度
• speed:转速，范围1～50，单位rpm
from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
smartservo = board.SmartServo()
while True:
    smartservo.move_to(1,720,50)
    sleep(4)
    smartservo.move_to(1,0,50)
    sleep(4)
move(index,position,speed)
按指定速度移动相对角度
参数：
• index:舵机序号
• position:目标角度
• speed:转速，范围1～50，单位rpm
from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
smartservo = board.SmartServo()
while True:
    smartservo.move(1,720,50)
    sleep(4)
    smartservo.move(1,-720,50)
    sleep(4)
set_zero(index)
设置当前位置为原点
参数：
• index:舵机序号
set_led(index,red,green,blue)
设置led颜色
参数：
• index:舵机序号
• red:红
• green:绿
• blue:蓝
from time import sleep
from makeblock import MegaPiPro 
board = MegaPiPro.create()
smartservo = board.SmartServo()
while True:
    smartservo.set_led(1,50,0,0)
    sleep(0.5)
    smartservo.set_led(1,0,50,0)
    sleep(0.5)
    smartservo.set_led(1,0,0,50)
    sleep(0.5)
无刷电机
----
BLDCMotor(port)
创建无刷电机对象。
参数：
• port: MegaPiPro.PORT1 ~ MegaPiPro.PORT4
run(speed)
以指定速度旋转
参数：
• speed:转速，单位？
程序示例
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
