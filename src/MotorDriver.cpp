#include<MotorDriver.hpp>

void MotorDrive::setup(){
    pinMode(dirpin,OUTPUT);
    pinMode(motorpwm,OUTPUT);
    ledcAttachPin(motorpwm,pwmch);
    ledcSetup(pwmch,12800,8);
}

void MotorDrive::DRIVE(int pwmvalue){
    if (pwmvalue < 0) {
        digitalWrite(dirpin, HIGH);
        ledcWrite(pwmch, -pwmvalue);
    }
    else if(pwmvalue > 0) {
        digitalWrite(dirpin, LOW);
        ledcWrite(pwmch, pwmvalue);
    }
    else{
        digitalWrite(dirpin,LOW);
        ledcWrite(pwmch,0);
    }
}

void MotorDrive2::setup_(){
    pinMode(inputpin1,OUTPUT);
    pinMode(inputpin2,OUTPUT);
    pinMode(motorpwm,OUTPUT);
    ledcAttachPin(motorpwm,pwmch);
    ledcSetup(pwmch,12800,8);
}

void MotorDrive2::DRIVE_(int pwmvalue){
    if (pwmvalue > 0) {
        digitalWrite(inputpin1, HIGH);
        digitalWrite(inputpin2,LOW);
        ledcWrite(pwmch, pwmvalue);
    }
    else if (pwmvalue < 0) {
        digitalWrite(inputpin1, LOW);
        digitalWrite(inputpin2,HIGH);
        ledcWrite(pwmch, -pwmvalue);
    }
    else{
        digitalWrite(inputpin1,LOW);
        digitalWrite(inputpin2,LOW);
        ledcWrite(pwmch,0);
    }
}