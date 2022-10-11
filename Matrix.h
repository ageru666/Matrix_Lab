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

    // methods

public:
    // Getters
    inline size_t height() { return _height; }
    inline size_t width() { return _width; }
    inline std::complex<double> *operator[](size_t i)
    {
        assert(i < _height);
        return matrix[i];
    };

    // Constructors
    Matrix(size_t a, size_t b);
    Matrix(size_t a, size_t b, bool random_init);
    Matrix(size_t a, size_t b, std::pair<double, double> **M);
    Matrix(std::string filename);

    // Destructor
    ~Matrix();

    // Operators overload
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const Matrix &);

    // Other methods
    std::complex<double> D();
};

#endif
