#include "Inversion.hpp"
#include "Matrix.h"

#ifndef _MINORINVERSION_H
#define _MINORINVERSION_H
class MinorInversion : Inversion
{
private:
    std::complex<double> findMinor(const Matrix &, size_t, size_t);

public:
    Matrix inverse(const Matrix &) override;
};

#endif
