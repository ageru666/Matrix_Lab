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
    Matrix strassenMultiplication(const Matrix &);
    std::complex<double> determinant();

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
    Matrix(Matrix &src);                                       // done

    // Destructor
    ~Matrix();

    // Operators overload
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const Matrix &);

    // Other methods
    std::complex<double> D(size_t x_skip = -1, size_t y_skip = -1) const;

    // output
    void print();                                      // done
    std::string str();                                 // done
    void to_file(std::string filename = "matrix.txt"); // done

    // inverse
    // later to be implemented in separate class
    static Matrix GaussianInverse(Matrix mat);
};

#endif
