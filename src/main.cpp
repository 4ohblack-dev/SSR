#include<Arduino.h>
#include<DabbleESP32.h>
#include<LineTrace.hpp>
#include<MotorDriver.hpp>
#include<Move.hpp>
#include<SetUp.hpp>

void calcpwm(){
  int xval = 252 * GamePad.getXaxisData() / 7;
  int yval = 252 * GamePad.getYaxisData() / 7;

  motorAinput = xval;
  motorBinput = xval * cosf(thetaB) + yval * sinf(thetaB);
  motorCinput = xval * cosf(thetaC) + yval * sinf(thetaC);
}

void setup(){
  Serial.begin(9600);
  Dabble.begin("Bluth");

  state = 0;

  power1 = 0;
  power2 = 0;

  motorA.setup();
  motorB.setup();
  motorC.setup();
  ArmMotor.setup_();
  CrawlerMotor.setup_();

  motorA.DRIVE(0);
  motorB.DRIVE(0);
  motorC.DRIVE(0);
  ArmMotor.DRIVE_(0);
  CrawlerMotor.DRIVE_(0);

  leftpho.setup();
  centerpho.setup();
  rightpho.setup();
}

void self(){
  int time_ = 0;
  while(time_ < 150){
    if(time_ < 30){
      MoveStraight();
    }
    else if(time_ < 60){
      RightRotate();
    }
    else if(time_ < 90){
      MoveStraight();
    }
    else if(time_ < 120){
      RightRotate();
    }
    else if(time_ < 150){
      MoveStraight();
    }
    time_++;
    delay(100);
  }
}



void loop(){
  Dabble.processInput();

  if(GamePad.isCrossPressed()){
    state = 0;
    motorAinput = 0;
    motorBinput = 0;
    motorCinput = 0;
    Serial.println("stop");
  }
  else if(GamePad.isUpPressed()){
    if(power1 < 250){
      power1 = power1 + 50;
    }
    else{
      power1 = 250;
    }
    ArmMotor.DRIVE_(power1);
  }
  else if(GamePad.isDownPressed()){
    if(power1 > -250){
      power1 = power1 - 50;
    }
    else{
      power1 = -250;
    }
    ArmMotor.DRIVE_(power1);
  }
  else if(GamePad.isRightPressed()){
    if(power2 < 250){
      power2 = power2 + 50;
    }
    else{
      power2 = 250;
    }
    CrawlerMotor.DRIVE_(power2);
  }
  else if(GamePad.isLeftPressed()){
    if(power2 > -250){
      power2 = power2 - 50;
    }
    else{
      power2 = -250;
    }
    CrawlerMotor.DRIVE_(power2);
  }
  else if(GamePad.isSquarePressed()){
    power1 = 0;
    power2 = 0;
    ArmMotor.DRIVE_(power1);
    CrawlerMotor.DRIVE_(power2);
  }
  else if(GamePad.isCirclePressed()){
    LeftRotate();
  }
  else if(GamePad.isTrianglePressed()){
    RightRotate();
  }
  else if(GamePad.isStartPressed()){
    self();
    if(GamePad.isCrossPressed()){
      state = 0;
      motorAinput = 0;
      motorBinput = 0;
      motorCinput = 0;
    }
  }
  else{
    calcpwm();
    motorA.DRIVE(motorAinput);
    motorB.DRIVE(motorBinput);
    motorC.DRIVE(motorCinput);
  }
  delay(80);
}