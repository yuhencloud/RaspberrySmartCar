#ifndef ENGINE_H
#define ENGINE_H

////////////////////////////////
#define LEFT_FRONT_ENABLEA 0
#define LEFT_FRONT_IN1 2
#define LEFT_FRONT_IN2 3

#define LEFT_BACK_ENABLEB 25
#define LEFT_BACK_IN3 24
#define LEFT_BACK_IN4 23

#define RIGHT_FRONT_ENABLEB 29
#define RIGHT_FRONT_IN3 28
#define RIGHT_FRONT_IN4 27

#define RIGHT_BACK_ENABLEA 4
#define RIGHT_BACK_IN1 5
#define RIGHT_BACK_IN2 6

typedef enum {
    e_free = 0,
    e_break = e_free + 1,
    e_forward = e_break + 1,
    e_backward = e_forward + 1
}WheelStatus;

void InitLeftFrontWheel();
void InitLeftBackWheel();
void InitRightFrontWheel();
void InitRightBackWheel();

void LeftFrontWheel(
    WheelStatus wheel_status
);
void LeftBackWheel(
    WheelStatus wheel_status
);
void RightFrontWheel(
    WheelStatus wheel_status
);
void RightBackWheel(
    WheelStatus wheel_status
);

void MoveFree();
void MoveBreak();
void MoveForward();
void MoveBackward();
void MoveLeft();
void MoveRight();

#endif
