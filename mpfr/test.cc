/***************************************************************************
 *   Copyright (C) 2008 by Jeff Hammond                                    *
 *   jeff.science@gmail.com                                                *
 ***************************************************************************/

#include "SuperFloat.h"

int main(int argc, char **argv)
{
    SuperFloat::Number a(1.0);
    SuperFloat::Number b(7L);
    SuperFloat::Number c;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    c=a;
    std::cout << c << std::endl;
    c+=b;
    std::cout << c << std::endl;
    c-=b;
    std::cout << c << std::endl;
    c*=b;
    std::cout << c << std::endl;
    c/=b;
    std::cout << c << std::endl;
    c*=2;
    std::cout << c << std::endl;
    c=98.17;
    std::cout << c << std::endl;
    return(0);
}
