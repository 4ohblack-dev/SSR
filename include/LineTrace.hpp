#pragma once

#include<Arduino.h>
#include<SetUp.hpp>
#include<Move.hpp>

struct LineTrace{
    int inputpin;
    int val;

    void setup();
    void getval();
};

void linetrace();

void self();

extern LineTrace leftpho;
extern LineTrace centerpho;
extern LineTrace rightpho;
