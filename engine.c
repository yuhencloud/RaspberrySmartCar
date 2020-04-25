#include <stdio.h>
#include <wiringPi.h>

#include "engine.h"

void InitLeftFrontWheel(){
    pinMode(LEFT_FRONT_ENABLEA, OUTPUT);
    pinMode(LEFT_FRONT_IN1, OUTPUT);
    pinMode(LEFT_FRONT_IN2, OUTPUT);
}

void InitLeftBackWheel(){
    pinMode(LEFT_BACK_ENABLEB, OUTPUT);
    pinMode(LEFT_BACK_IN3, OUTPUT);
    pinMode(LEFT_BACK_IN4, OUTPUT);
}

void InitRightFrontWheel(){
    pinMode(RIGHT_FRONT_ENABLEB, OUTPUT);
    pinMode(RIGHT_FRONT_IN3, OUTPUT);
    pinMode(RIGHT_FRONT_IN4, OUTPUT);
}

void InitRightBackWheel(){
    pinMode(RIGHT_BACK_ENABLEA, OUTPUT);
    pinMode(RIGHT_BACK_IN1, OUTPUT);
    pinMode(RIGHT_BACK_IN2, OUTPUT);
}

void LeftFrontWheel(
    WheelStatus wheel_status
) {
    digitalWrite(LEFT_FRONT_ENABLEA, HIGH);
    switch (wheel_status) {
        case e_free: {
            digitalWrite(LEFT_FRONT_ENABLEA, LOW);
            break;
        }
        case e_break: {
            digitalWrite(LEFT_FRONT_IN1, HIGH);
            digitalWrite(LEFT_FRONT_IN2, HIGH);
            break;
        }
        case e_forward: {
            digitalWrite(LEFT_FRONT_IN1, HIGH);
            digitalWrite(LEFT_FRONT_IN2, LOW);
            break;
        }
        case e_backward: {
            digitalWrite(LEFT_FRONT_IN1, LOW);
            digitalWrite(LEFT_FRONT_IN2, HIGH);
            break;
        }
    }
}

void LeftBackWheel(
    WheelStatus wheel_status
) {
    digitalWrite(LEFT_BACK_ENABLEB, HIGH);
    switch (wheel_status) {
        case e_free: {
            digitalWrite(LEFT_BACK_ENABLEB, LOW);
            break;
        }
        case e_break: {
            digitalWrite(LEFT_BACK_IN3, HIGH);
            digitalWrite(LEFT_BACK_IN4, HIGH);
            break;
        }
        case e_forward: {
            digitalWrite(LEFT_BACK_IN3, LOW);
            digitalWrite(LEFT_BACK_IN4, HIGH);
            break;
        }
        case e_backward: {
            digitalWrite(LEFT_BACK_IN3, HIGH);
            digitalWrite(LEFT_BACK_IN4, LOW);
            break;
        }
    }
}

void RightFrontWheel(
    WheelStatus wheel_status
) {
    digitalWrite(RIGHT_FRONT_ENABLEB, HIGH);
    switch (wheel_status) {
        case e_free: {
            digitalWrite(RIGHT_FRONT_ENABLEB, LOW);
            break;
        }
        case e_break: {
            digitalWrite(RIGHT_FRONT_IN3, HIGH);
            digitalWrite(RIGHT_FRONT_IN4, HIGH);
            break;
        }
        case e_forward: {
            digitalWrite(RIGHT_FRONT_IN3, HIGH);
            digitalWrite(RIGHT_FRONT_IN4, LOW);
            break;
        }
        case e_backward: {
            digitalWrite(RIGHT_FRONT_IN3, LOW);
            digitalWrite(RIGHT_FRONT_IN4, HIGH);
            break;
        }
    }
}

void RightBackWheel(
    WheelStatus wheel_status
) {
    digitalWrite(RIGHT_BACK_ENABLEA, HIGH);
    switch (wheel_status) {
        case e_free: {
            digitalWrite(RIGHT_BACK_ENABLEA, LOW);
            break;
        }
        case e_break: {
            digitalWrite(RIGHT_BACK_IN1, HIGH);
            digitalWrite(RIGHT_BACK_IN2, HIGH);
            break;
        }
        case e_forward: {
            digitalWrite(RIGHT_BACK_IN1, LOW);
            digitalWrite(RIGHT_BACK_IN2, HIGH);
            break;
        }
        case e_backward: {
            digitalWrite(RIGHT_BACK_IN1, HIGH);
            digitalWrite(RIGHT_BACK_IN2, LOW);
            break;
        }
    }
}

void MoveFree(
) {
    LeftFrontWheel(e_free);
    LeftBackWheel(e_free);
    RightFrontWheel(e_free);
    RightBackWheel(e_free);
}

void MoveBreak(
) {
    LeftFrontWheel(e_break);
    LeftBackWheel(e_break);
    RightFrontWheel(e_break);
    RightBackWheel(e_break);
}

void MoveForward(
) {
    LeftFrontWheel(e_forward);
    LeftBackWheel(e_forward);
    RightFrontWheel(e_forward);
    RightBackWheel(e_forward);
}

void MoveBackward(
) {
    LeftFrontWheel(e_backward);
    LeftBackWheel(e_backward);
    RightFrontWheel(e_backward);
    RightBackWheel(e_backward);
}

void MoveLeft(
) {
    LeftFrontWheel(e_backward);
    LeftBackWheel(e_backward);
    RightFrontWheel(e_forward);
    RightBackWheel(e_forward);
}

void MoveRight(
) {
    LeftFrontWheel(e_forward);
    LeftBackWheel(e_forward);
    RightFrontWheel(e_backward);
    RightBackWheel(e_backward);
}
