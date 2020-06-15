#include "VectorF.h"

VectorF::VectorF()
{
    Set1(0.0);
}

void VectorF::Set1(float v)
{
    for (int i = 0; i < Len; i++) E[i] = v;
}

void VectorF::Print()
{
    cout << "F: [";
    for (int i = 0; i < Len; i++) cout << E[i] << ((i < Len - 1) ? ", " : "");
    cout << "]" << endl;
}

// Arith 1.
void VectorF::Arith1(VectorF *src,
                     Mask16 *mask,
                     VectorF *a,
                     function<float (float)> f,
                     VectorF *dst)
{
    for (int i = 0; i < Len; i++)
    {
        if ((mask == nullptr) || mask->E[i])
        {
            // Perform operation.
            dst->E[i] = f(src->E[i]);
        }
        else
        {
            // Copy from src or zero element.
            dst->E[i] = (src != nullptr) ? src->E[i] : 0.0;
        }
    }
}

// Arithmetic function with 2 arguments.
void VectorF::Arith2(VectorF *src,
                     Mask16 *mask,
                     VectorF *a,
                     VectorF *b,
                     function<float (float, float)> f,
                     VectorF *dst)
{
    for (int i = 0; i < Len; i++)
    {
        if ((mask == nullptr) || mask->E[i])
        {
            // Perform operation.
            dst->E[i] = f(a->E[i], b->E[i]);
        }
        else
        {
            // Copy from src or zero element.
            dst->E[i] = (src != nullptr) ? src->E[i] : 0.0;
        }
    }
}

// FMAdd.
void VectorF::FMAdd(VectorF *src,
                    Mask16 *mask,
                    VectorF *a,
                    VectorF *b,
                    VectorF *c,
                    VectorF *dst)
{
    for (int i = 0; i < Len; i++)
    {
        if ((mask == nullptr) || mask->E[i])
        {
            // Perform operation.
            dst->E[i] = a->E[i] * b->E[i] + c->E[i];
        }
        else
        {
            // Copy from src or zero element.
            dst->E[i] = (src != nullptr) ? src->E[i] : 0.0;
        }
    }
}

// Cmp.
void VectorF::Cmp(Mask16 *mask,
                  VectorF *a,
                  VectorF *b,
                  function<bool (float, float)> f,
                  Mask16 *res)
{
    for (int i = 0; i < Len; i++)
    {
        if ((mask == nullptr) || mask->E[i])
        {
            // Perform operation.
            res->E[i] = f(a->E[i], b->E[i]);
        }
        else
        {
            // Zero mask element.
            res->E[i] = false;
        }
    }
}
