#include <complex>
#include <cassert>

#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix
{
protected:
    std::complex<double> **matrix;
    size_t _height;
    size_t _width;

public:
    inline std::complex<double> *operator[](size_t i)
    {
        assert(i < _height);
        return matrix[i];
    };
    inline size_t height() { return _height; }
    inline size_t width() { return _width; }

    Matrix(size_t a, size_t b);
    ~Matrix();
};

#endif
