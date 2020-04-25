#include <stdio.h>
#include <wiringPi.h>

#include "servo.h"

void InitServo(){
    pinMode(SERVO_PIN, PWM_OUTPUT); 
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(2000);
    pwmSetClock(192);
}

void RotateServoAngle(
    int angle
) {
    if (0 == angle) {
        pwmWrite(SERVO_PIN, 400);
    } else if (-90 == angle) {
        pwmWrite(SERVO_PIN, 700);
    } else if (90 == angle) {
        pwmWrite(SERVO_PIN, 100);
    } else {
    }
    delay(300);
}
