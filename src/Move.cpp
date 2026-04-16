#include <Move.hpp>

void MoveStraight(){
    motorA.DRIVE(0);
    motorB.DRIVE(200);
    motorC.DRIVE(-200);
}

void RightRotate(){
    motorA.DRIVE(200);
    motorB.DRIVE(200);
    motorC.DRIVE(200);
}

void LeftRotate(){
    motorA.DRIVE(-200);
    motorB.DRIVE(-200);
    motorC.DRIVE(-200);
}
