#include "Matrix.h"

#ifndef _INVERSION_H
#define _INVERSION_H
class Inversion
{
public:
    virtual Matrix inverse(const Matrix &A) { return Matrix(1, 1, true); } // DA FAQ?
};

#endif
