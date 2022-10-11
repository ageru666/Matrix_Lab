#include <complex>
#include <cassert>

#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix
{
private:
    std::complex<double> **matrix;
    size_t height;
    size_t width;

public:
    inline std::complex<double> *operator[](size_t i)
    {
        assert(i < height);
        return matrix[i];
    };

    Matrix(size_t a, size_t b);
    ~Matrix();
};

#endif
