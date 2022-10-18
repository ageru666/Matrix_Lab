#include <iostream>
#include "Matrix.h"

int main()
{

    Matrix m(4,4, true);

    m.print();
    std::cout<<'\n';
    std::cout<<m.D();
}
