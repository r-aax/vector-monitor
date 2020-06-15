#include "VectorF.h"
#include "Mask16.h"

int main()
{
    VectorF a;
    VectorF b;
    VectorF c;
    Mask16 m;

    a.Set1(1.0);
    b.Set1(2.0);
    VectorF::Add(nullptr, nullptr, &a, &b, &c);
    c.Print();
    m.Print();

    return 0;
}
