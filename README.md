# RaspberrySmartCar
树莓派4B控制的智能避障小车，包括驱动电机，舵机和超声测距

## 电机驱动模块engine.c
> 由两块L298N电机驱动模块驱动4电机，通过高低电平的控制，实现单个轮子的正向和反向旋转

> 定义枚举类型，区分轮子状态
```
typedef enum {
    e_free = 0,
    e_break = e_free + 1,
    e_forward = e_break + 1,
    e_backward = e_forward + 1
}WheelStatus;
```
> 单轮子控制函数
> + void LeftFrontWheel(WheelStatus wheel_status);
> + void LeftBackWheel(WheelStatus wheel_status);
> + void RightFrontWheel(WheelStatus wheel_status);
> + void RightBackWheel(WheelStatus wheel_status);

> 前进和转向(转向采用小车双侧轮反方向旋转进行转向，转向角度可以通过时间控制)
> + void MoveForward();
> + void MoveBackward();
> + void MoveLeft();
> + void MoveRight();

## 舵机驱动模块servo.c
> 采用sg90舵机，0~180度旋转，通过PWM信号控制转向角度，转向后需预留舵机转向时间，再进行测距
```
void RotateServoAngle(
    int angle
);
```

## 超声测距模块ultrasonic.c
> 采用HC-SR04超声波测距模块，测距精度精准，缺点是倾斜测距效果不好，前端测距物体要达到一定面积，通过发射超声波，测量高低电平的变化间隔，进而测量距离
```
float GetUltrasonicDistance(
);
```

[点我观看](https://www.bilibili.com/video/BV1xK4y1b7W6/ "点我观看")


