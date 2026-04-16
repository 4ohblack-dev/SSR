#include<LineTrace.hpp>

void LineTrace::setup(){
    pinMode(inputpin,INPUT);
}

void LineTrace::getval(){
    val = 255 * analogRead(inputpin);
};

