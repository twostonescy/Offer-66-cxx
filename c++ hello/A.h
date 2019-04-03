#pragma once
#include "head.h"

class A
{
public:
    A();
    A(char l);
    ~A();
    //virtual void foo();
    char ka;

};

class C
{
public:
    C();
    ~C();
     void c1() {
    }
     void c2() {
    }
    char kc;

};

class B:public A,public C
{
public:
    B();
    ~B();
     void b1() {
    }
     void b2() {
    }
    char kb;

};



class D :public A
{
public:
    D();
    ~D();
    //virtual void foo();

private:

};

