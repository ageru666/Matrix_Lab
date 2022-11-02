#include "Inversion.hpp"
#include "Matrix.h"

#ifndef _MINORINVERSION_H
#define _MINORINVERSION_H
class MinorInversion : Inversion
{
private:
    std::complex<double> findMinor(const Matrix &, size_t, size_t);
    Matrix inverse_no_threading(const Matrix &);
    Matrix inverse_with_threading(const Matrix &);

public:
    Matrix inverse(const Matrix &) override;
};

#endif
