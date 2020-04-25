#include <stdio.h>
#include <wiringPi.h>

#include "ultrasonic.h"

void InitUltrasonic(){
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

float GetUltrasonicDistance(
) {
    digitalWrite(TRIG_PIN, LOW);
    delay(10);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    unsigned int start_time = 0;
    unsigned int end_time = 0;
    
    while(digitalRead(ECHO_PIN) != HIGH) {
         start_time = micros();
    }
    while(digitalRead(ECHO_PIN) != LOW) {
        end_time = micros();
    }
    
    float distance = ((float)end_time - (float)start_time) / 2 / 1000000 * 34000;
    
    printf("dis is %0.2f cm\r\n", distance);
    
    delay(80);
    
    return distance;
}
