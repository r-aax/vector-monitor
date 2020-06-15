#ifndef VECTOR_F_H
#define VECTOR_F_H

#include <iostream>
#include <functional>
#include "Mask16.h"

using namespace std;

class VectorF
{
    static const int Len = 16;

public:

    float E[Len];

    VectorF();
    void Set1(float v);
    void Print();

    // Arith 1.
    static void Arith1(VectorF *src,
                       Mask16 *mask,
                       VectorF *a,
                       function<float (float)> f,
                       VectorF *dst);
    static void Abs(VectorF *src, Mask16 *mask, VectorF *a, VectorF *dst)
    {
        Arith1(src, mask, a, [](float x) -> float { return abs(x); }, dst);
    }

    // Arith 2.
    static void Arith2(VectorF *src,
                       Mask16 *mask,
                       VectorF *a,
                       VectorF *b,
                       function<float (float, float)> f,
                       VectorF *dst);
    static void Add(VectorF *src, Mask16 *mask, VectorF *a, VectorF *b, VectorF *dst)
    {
        Arith2(src, mask, a, b, [](float x, float y) -> float { return x + y; }, dst);
    }
    static void Sub(VectorF *src, Mask16 *mask, VectorF *a, VectorF *b, VectorF *dst)
    {
        Arith2(src, mask, a, b, [](float x, float y) -> float { return x - y; }, dst);
    }
    static void Mul(VectorF *src, Mask16 *mask, VectorF *a, VectorF *b, VectorF *dst)
    {
        Arith2(src, mask, a, b, [](float x, float y) -> float { return x * y; }, dst);
    }
    static void Div(VectorF *src, Mask16 *mask, VectorF *a, VectorF *b, VectorF *dst)
    {
        Arith2(src, mask, a, b, [](float x, float y) -> float { return x / y; }, dst);
    }

    // FMAdd.
    static void FMAdd(VectorF *src,
                      Mask16 *mask,
                      VectorF *a,
                      VectorF *b,
                      VectorF *c,
                      VectorF *dst);

    // Cmp.
    static void Cmp(Mask16 *mask,
                    VectorF *a,
                    VectorF *b,
                    function<bool (float, float)> f,
                    Mask16 *res);
    static void CmpEQ(Mask16 *mask, VectorF *a, VectorF *b, Mask16 *res)
    {
        Cmp(mask, a, b, [](float x, float y) -> float { return x == y; }, res);
    }
    static void CmpNE(Mask16 *mask, VectorF *a, VectorF *b, Mask16 *res)
    {
        Cmp(mask, a, b, [](float x, float y) -> float { return x != y; }, res);
    }
    static void CmpLT(Mask16 *mask, VectorF *a, VectorF *b, Mask16 *res)
    {
        Cmp(mask, a, b, [](float x, float y) -> float { return x < y; }, res);
    }
    static void CmpLE(Mask16 *mask, VectorF *a, VectorF *b, Mask16 *res)
    {
        Cmp(mask, a, b, [](float x, float y) -> float { return x <= y; }, res);
    }
    static void CmpGT(Mask16 *mask, VectorF *a, VectorF *b, Mask16 *res)
    {
        Cmp(mask, a, b, [](float x, float y) -> float { return x > y; }, res);
    }
    static void CmpGE(Mask16 *mask, VectorF *a, VectorF *b, Mask16 *res)
    {
        Cmp(mask, a, b, [](float x, float y) -> float { return x >= y; }, res);
    }
};

#endif
