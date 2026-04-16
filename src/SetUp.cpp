#include<SetUp.hpp>

int leftphotoval = 0;
int centerphotoval = 0;
int rightphotoval = 0;

int motorAinput = 0;
int motorBinput = 0;
int motorCinput = 0;

int state = 0;

int power1 = 0;
int power2 = 0;

MotorDrive motorA{motorpinA,motorAp,pwmch_A};
MotorDrive motorB{motorpinB,motorBp,pwmch_B};
MotorDrive motorC{motorpinC,motorCp,pwmch_C};

MotorDrive2 ArmMotor{armmotorpin1,armmotorpin2,armmotorpwm,pwmch};
MotorDrive2 CrawlerMotor{crawlermotor1,crawlermotor2,crawlerpwm,pwmch_cr};

LineTrace leftpho{leftphoto,leftphotoval};
LineTrace centerpho{centerphoto,centerphotoval};
LineTrace rightpho{rightphoto,rightphotoval};
