#include "Matrix.h"
#include <iostream>

int main()
{
    Matrix a("C:\\Users\\spery\\CLionProjects\\Matrix_Lab\\inverse_test_data\\test1.txt");
    Matrix b("C:\\\\Users\\\\spery\\\\CLionProjects\\\\Matrix_Lab\\\\inverse_test_data\\\\test2.txt");

    Matrix c = a*b;

    for (int i=0; i<c.height(); i++)
        for (int j=0; j<c.width(); j++)
            std::cout<<c[i][j];
}