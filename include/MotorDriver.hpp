#pragma once

#include<Arduino.h>

struct MotorDrive{
    int dirpin;
    int motorpwm;
    int pwmch;

    void setup();

    void DRIVE(int pwmvalue);
};



struct MotorDrive2{
    int inputpin1;
    int inputpin2;
    int motorpwm;
    int pwmch;

    void setup_();

    void DRIVE_(int pwmvalue);
};