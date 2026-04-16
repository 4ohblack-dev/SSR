#include <Arduino.h>
#include<ESP32Servo.h>

//X軸のモータ(dir 32,pwm 33)
const int motorpinX = 32;
const int motorXp = 33;
const int pwmchX = 0;
//Y軸のモータ(dir 25,pwm 26)
const int motorpinY  = 25;
const int motorYp = 26;
const int pwmchY = 1;
//坂用のモータ(dir 27,pwm 14)
const int motorpinS = 27;
const int motorSp = 14;
const int pwmchS = 2;
//サーボのピン(13)
const int servoZ = 13
;
//各ボタン(X:19,18 ; Y:5,17 ; Z:16,4)
const int pinXf = 19;
const int pinXd = 18;
const int pinYf = 5;
const int pinYd = 17;
const int pinZf = 16;
const int pinZd = 4;
//0,2は変えれるなら22,23に変えて
const int pinSf = 22;
const int pinSd = 23;

int pins[] = {pinXf, pinXd, pinYf, pinYd, pinZf, pinZd,pinSf,pinSd};

Servo Z_servo;

struct MotorDrive{
  int dirpin;
  int motorpwm;
  int pwmch;

  void setup(){
    pinMode(dirpin,OUTPUT);
    pinMode(motorpwm,OUTPUT);
    ledcSetup(pwmch,12800,8);
    ledcAttachPin(motorpwm,pwmch);
  }

  void DRIVE(int pwmvalue){
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
};

MotorDrive motorX{motorpinX,motorXp,pwmchX};
MotorDrive motorY{motorpinY,motorYp,pwmchY};
MotorDrive motorS{motorpinS,motorSp,pwmchS};

//モータをコントロールする
//ボタンを押してる間はモータが回転する
void ControllMotor(struct MotorDrive &motor,int btn1,int btn2){
  int forward = digitalRead(btn1);
  int backward = digitalRead(btn2);

  if(forward ==LOW && backward ==HIGH){
    motor.DRIVE(100);
  }
  else if(forward == HIGH && backward == LOW){
    motor.DRIVE(-100);
  }
  else if(forward == HIGH && backward == HIGH){
    motor.DRIVE(0);
  }
  else if(forward == LOW && backward == LOW){
    motor.DRIVE(0);
  }
}
//ボタンを押してる間はz軸のサーボモータが回転する
void Controll_Z_axis(struct Servo &servo,int btn1,int btn2){
  int forward = digitalRead(btn1);
  int backward = digitalRead(btn2);

  if(forward == LOW && backward == HIGH){
    servo.write(120);
  }
  else if(forward == HIGH && backward == LOW){
    servo.write(60);
  }
  else{
    servo.write(95);
  }
}
//2.5回転させるとき用（使うときはここの下のコメントアウト外して、上のControll_Z_axis()をコメントアウトして）
//1回転する時間を測って、10000のとこに入れて欲しい

/*
const int rotationtime = 1680; // 1回転するのに必要な時間（ms）
unsigned long startTime = 0;
bool rotating = false;

void Controll_Z_axis(struct Servo &servo,int btn1,int btn2){
  int upward = digitalRead(pinZf);
  int downward = digitalRead(pinZd);

  if (!rotating) {
    if (upward == LOW && downward == HIGH) {
      servo.write(120); // forward          逆回転だったら、この120と下の60を交換して
      startTime = millis();
      rotating = true;

    }
    else if (upward == HIGH && downward == LOW) {
      servo.write(60); // reverse
      startTime = millis();
      rotating = true;
    }
    else {
      servo.write(90); // stop
    }
  } else {
    if (millis() - startTime >= (unsigned long)(rotationtime)) {
      servo.write(91); // stop
      rotating = false;
    }
  }
}
*/

void PrintButtonStates() {
  int states[] = {
    digitalRead(pinXf), digitalRead(pinXd),
    digitalRead(pinYf), digitalRead(pinYd),
    digitalRead(pinZf), digitalRead(pinZd),
    digitalRead(pinSf), digitalRead(pinSd)
  };

  const char* names[] = {
    "X forward", "X backward",
    "Y forward", "Y backward",
    "Z forward", "Z backward",
    "S forward", "S backward"
  };

  for (int i = 0; i < 8; i++) {
    if (states[i] == HIGH) {  // INPUT_PULLUPなので押したらLOW
      Serial.print(names[i]);
      Serial.print(" pressed | ");
    }
  }
  Serial.println();
}


void setup(){
  Serial.begin(9600);
  motorX.setup();
  motorY.setup();
  motorS.setup();
  Z_servo.attach(servoZ);
  motorX.DRIVE(0);
  motorY.DRIVE(0);
  motorS.DRIVE(0);
  Z_servo.write(90);
  delay(500);
  
  for (int i = 0; i < sizeof(pins)/sizeof(pins[0]); i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void loop(){
  ControllMotor(motorX,pinXf,pinXd);
  ControllMotor(motorY,pinYf,pinYd);  
  ControllMotor(motorS,pinSf,pinSd);
  Controll_Z_axis(Z_servo,pinZf,pinZd);
  PrintButtonStates();
  //それぞれのモーターは独立で動くはずだから、x、ｙ同時に動かしたりはできると思う
  //ｘ軸の二つのボタンを同時に押すと、処理としては停止になる。
  //今のコードでは、Ｚ軸はボタンを押してる時だけ回転する
  //2.5回転でＺ軸を動かしたいときは、Controll_Z_axisの関数を入れ替えて
  //（入れ替えたときは、2.5回転し終わるまでサーボの動きは変更できない。x、ｙ、坂は動かせる）
}