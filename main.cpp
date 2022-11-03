#include "Matrix.h"
#include <iostream>
#include "test.hpp"
#include "GaussianInversion.h"
#include "MinorInversion.hpp"

int main()
{
    Matrix m("C:\\Users\\spery\\CLionProjects\\Matrix_Lab\\inverse_test_data\\test1.txt");
    GaussianInversion G;

   Matrix r =  G.inverse(m);

   Matrix e = m*r;

    for (int i=0; i<e.height() ; i++) {
        for (int j = 0; j < e.width(); j++)
            std::cout << e[i][j] << ' ';
        std::cout<<std::endl;
    }

}