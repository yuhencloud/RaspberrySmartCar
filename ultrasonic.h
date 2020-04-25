#ifndef ULTRASONIC_H
#define ULTRASONIC_H

////////////////////////////////
#define TRIG_PIN 22
#define ECHO_PIN 21

void InitUltrasonic();

float GetUltrasonicDistance();

#endif
