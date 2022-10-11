#include <complex>

class Matrix {
private:
    std::complex<double> **matrix;
    int height;
    int width;

public:
    std::complex<double>* operator[](int i);
    Matrix(int a, int b);
    ~Matrix();
};

