#pragma once

#include<Arduino.h>
#include<MotorDriver.hpp>
#include<LineTrace.hpp>

//theta
constexpr float thetaA = 0;
constexpr float thetaB = 2 * PI / 3.0;
constexpr float thetaC = - 2 * PI / 3.0;

//Motor,MotorDrive
constexpr int motorpinA = 12;
constexpr int motorAp = 14;
constexpr int pwmch_A = 0;

constexpr int motorpinB = 27;
constexpr int motorBp = 26;
constexpr int pwmch_B = 1;

constexpr int motorpinC = 25;
constexpr int motorCp = 33;
constexpr int pwmch_C = 2;

constexpr int armmotorpin1 = 17;
constexpr int armmotorpin2 = 16;
constexpr int armmotorpwm = 4;
constexpr int pwmch = 3;

constexpr int crawlermotor1 = 15;
constexpr int crawlermotor2 = 2;
constexpr int crawlerpwm = 0;
constexpr int pwmch_cr = 4;


constexpr int leftphoto = 32;
constexpr int centerphoto = 35;
constexpr int rightphoto = 34;


extern int leftphotoval;
extern int centerphotoval;
extern int rightphotoval;

extern int motorAinput;
extern int motorBinput;
extern int motorCinput;

extern int state;

extern int power1;
extern int power2;

extern MotorDrive motorA;
extern MotorDrive motorB;
extern MotorDrive motorC;

extern MotorDrive2 ArmMotor;
extern MotorDrive2 CrawlerMotor;
