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
Servo(port,slot)
----
         创建舵机对象。
         参数：
         • port: MegaPiPro.PORT5 ~ MegaPiPro.PORT8
         • slot: MegaPiPro.SLOT1 ~ MegaPiPro.SLOT2
         set_angle(angle)
         设置舵机旋转角度
         参数：
         • angle:旋转角度，范围：0 ~ 180°
         程序示例
         from time import sleep
         from makeblock import MegaPiPro
         board = MegaPiPro.create()
         servo = board.Servo(MegaPiPro.PORT6,MegaPiPro.SLOT1)
         while True:
                servo.set_angle(30)
                sleep(1)
                servo.set_angle(120)
                sleep(1)
直流电机
----
DCMotor(port,slot)
----
        创建直流电机对象。
        参数：
        • port: MegaPiPro.PORT1 ~ MegaPiPro.PORT4
        • slot: MegaPiPro.SLOT1 ~ MegaPiPro.SLOT2
        run(speed)
        以百分比速度旋转<br>
        参数：
        • speed:速度百分比，范围：-100 ~ 100
        程序示例
        from time import sleep<br>
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
直流编码电机
----
EncoderMotor(port)
----
        创建直流编码电机对象。
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
        encoder = board.EncoderMotor(MegaPiPro.PORT1)
        position = 0
        def on_finished(value):
                position = 5000 - position
                encoder.move_to(position,100,on_finished)
                on_finished(position)
        set_home()
        设置当前位置为原点
步进电机
----
StepperMotor(port)
----
        创建步进电机对象。
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
----
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
----
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
