#include <complex>
#include <cassert>

#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix
{
private:
    std::complex<double> **matrix;
    int height;
    int width;

public:
    inline std::complex<double> *operator[](int i)
    {
        assert(i < height);
        return matrix[i];
    };

    Matrix(int a, int b);
    ~Matrix();
};

#endif
