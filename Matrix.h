#include <complex>
#include <cassert>
#include <iostream>

#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix
{
protected:
    std::complex<double> **matrix;
    size_t _height;
    size_t _width;

    // methods
    Matrix strassenMultiplication(const Matrix &);

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

    // Destructor
    ~Matrix();

    // Operators overload
    Matrix operator=(const Matrix &) const;
    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;

    // Other methods
    std::complex<double> D() const;
    std::complex<double> Dminor(size_t x_skip, size_t y_skip) const;
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
