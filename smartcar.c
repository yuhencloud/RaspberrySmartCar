#include <stdio.h>
#include <wiringPi.h>

#include "engine.h"
#include "servo.h"
#include "ultrasonic.h"

#define SAFE_DISTANCE 50

int main() {
    
    wiringPiSetup();
    InitLeftFrontWheel();
    InitLeftBackWheel();
    InitRightFrontWheel();
    InitRightBackWheel();
    InitServo();
    InitUltrasonic();
    
    RotateServoAngle(0);
    float distance = GetUltrasonicDistance();
    MoveForward();
    
    while (1) {
        if (distance > SAFE_DISTANCE) {
            distance = GetUltrasonicDistance();
            continue;
        }
        MoveBreak();
        
        float left_distance = 0.f;
        float right_distance = 0.f;
        RotateServoAngle(-90);
        left_distance = GetUltrasonicDistance();
        RotateServoAngle(90);
        right_distance = GetUltrasonicDistance();
        RotateServoAngle(0);
        
        if (left_distance < SAFE_DISTANCE && right_distance < SAFE_DISTANCE) {
            MoveLeft();
            delay(600);
            distance = GetUltrasonicDistance();
            MoveForward();
            continue;
        }
        if (left_distance > right_distance) {
            MoveLeft();
            delay(300);
            distance = GetUltrasonicDistance();
            MoveForward();
            continue;
        }
        if (left_distance <= right_distance) {
            MoveRight();
            delay(300);
            distance = GetUltrasonicDistance();
            MoveForward();
            continue;
        }
    }
    return 0;
}
