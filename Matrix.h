#include <complex>
#include <cassert>
#include <iostream>

#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix
{
    friend class MatrixThreading;

protected:
    std::complex<double> **matrix = nullptr;
    size_t _height = 0;
    size_t _width = 0;

public:
    // Getters
    inline size_t height() const { return _height; }
    inline size_t width() const { return _width; }
    inline std::complex<double> *operator[](size_t i) const
    {

        assert(i < _height);
        return matrix[i];
    };

    // Constructors

    Matrix(size_t a, size_t b, bool random_init = false);      // done
    Matrix(size_t a, size_t b, std::pair<double, double> **M); // done
    Matrix(std::string filename);                              // done
    Matrix(const Matrix &src);                                 // done
    Matrix(const Matrix &src, size_t x_skip, size_t y_skip);
    Matrix() = default;

    // Destructor
    ~Matrix();

    // Operators overload
    Matrix &operator=(const Matrix src);
    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;
    Matrix StrassenMultiply(Matrix a, Matrix b);

    // Other methods
    std::complex<double> D() const;
    std::complex<double> Dminor(size_t x_skip, size_t y_skip) const;
    Matrix SubMatrix(size_t r1, size_t c1, size_t r2, size_t c2);
    Matrix CombineSubMatrices(Matrix a11, Matrix a12, Matrix a21, Matrix a22);
    void DminorVoid(size_t x_skip, size_t y_skip, std::complex<double> &) const;

    // output
    void print() const;                                      // done
    std::string str() const;                                 // done
    void to_file(std::string filename = "matrix.txt") const; // done

    // transforamtions
    void to_triangle_form();
    void T();
};

#endif
