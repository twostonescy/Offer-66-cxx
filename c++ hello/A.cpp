#include "pch.h"
#include "A.h"


A::A()
{
    C* k = new C();
    ka = 'a';
}

A::A(char l)
{
    ka = 'a';
    C* k = new C();
}


A::~A()
{
}



B::B()
{
    ka = 'a';
    kb = 'b';
    kc = 'c';
}

B::~B()
{
}

C::C()
{
    kc = 'c';

}

C::~C()
{
}

D::D()
{
}

D::~D()
{
}
