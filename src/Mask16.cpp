#include "Mask16.h"

Mask16::Mask16()
{
    Reset();
}

void Mask16::Reset()
{
    for (int i = 0; i < Len; i++) E[i] = false;
}

void Mask16::Print()
{
    cout << "M16: [";
    for (int i = 0; i < Len; i++) cout << E[i] << ((i < Len - 1) ? ", " : "");
    cout << "]" << endl;
}
