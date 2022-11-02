#include "Matrix.h"
#include <iostream>
#include "test.hpp"
#include "GaussianInversion.h"
#include "MinorInversion.hpp"

int main()
{
    Test T;
    GaussianInversion G;
    MinorInversion M;

    // Matrix mm(3, 3, true);

    // std::cout << (M.inverse(mm, true) * mm).str() << std::endl;

    T.test_and_write(G, "out.txt", true);

    /*
    Matrix a("C:\\Users\\spery\\CLionProjects\\Matrix_Lab\\inverse_test_data\\test1.txt");
    Matrix b("C:\\\\Users\\\\spery\\\\CLionProjects\\\\Matrix_Lab\\\\inverse_test_data\\\\test2.txt");

    Matrix c = a*b;

    for (int i=0; i<c.height(); i++)
        for (int j=0; j<c.width(); j++)
            std::cout<<c[i][j];
    */
}