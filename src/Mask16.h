#ifndef MASK_16_H
#define MASK_16_H

#include <iostream>

using namespace std;

class Mask16
{
    static const int Len = 16;

public:

    bool E[Len];

    Mask16();
    void Reset();
    void Print();
};

#endif
