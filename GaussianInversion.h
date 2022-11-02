#include "Inversion.hpp"
#include "Matrix.h"
#ifndef MATRIX_LAB_GAUSSIANINVERSION_H
#define MATRIX_LAB_GAUSSIANINVERSION_H

class GaussianInversion : Inversion
{
public:
    Matrix inverse(const Matrix &, bool) override;
};

#endif // MATRIX_LAB_GAUSSIANINVERSION_H
