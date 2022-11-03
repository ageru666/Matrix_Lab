#include "Matrix.h"
#include <iostream>
#include "test.hpp"
#include "GaussianInversion.h"
#include "MinorInversion.hpp"

int main()
{
    Matrix m(3, 3, true);
    GaussianInversion G;

   Matrix r =  G.inverse(m);

   Matrix e = m*r;

    for (int i=0; i<e.height() ; i++) {
        for (int j = 0; j < e.width(); j++)
            std::cout << e[i][j] << ' ';
        std::cout<<std::endl;
    }

}