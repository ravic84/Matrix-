#include <iostream>
#include <matrix/matrix.hpp>

using namespace std;
using namespace myMatrix;

myMatrix::Matrix<int> mat1(3, 3);
myMatrix::Matrix<int> mat2(2, 2);

int main()
{
    for (auto &it : mat1)
    {
        it = 3;
    }

    for (auto &it : mat2)
    {
        it = 3;
    }

    myMatrix::Matrix<int> mat3 = mat1 + mat2;
    mat3.printMatrix();

    return 0;
}