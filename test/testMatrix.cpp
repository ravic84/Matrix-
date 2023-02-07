#include <gtest/gtest.h>
#include <matrix/matrix.hpp>

TEST(testMatrixConstructor, testCopyConstructor)
{
    myMatrix::Matrix<int> mat1(3, 3);
    const myMatrix::Matrix<int> &mat2(mat1);

    const auto exp1 = mat1.getRows();
    const auto res1 = mat2.getRows();

    const auto exp2 = mat1.getCols();
    const auto res2 = mat2.getCols();

    ASSERT_EQ(exp1, res1);
    ASSERT_EQ(exp2, res2);
}

TEST(testMatrixConstructor, testCopyAssignment)
{
    myMatrix::Matrix<int> mat1(3, 3);
    myMatrix::Matrix<int> mat2(2, 2);

    mat2 = mat1;

    const auto exp1 = mat1.getRows();
    const auto res1 = mat2.getRows();

    const auto exp2 = mat1.getCols();
    const auto res2 = mat2.getCols();

    ASSERT_EQ(exp1, res1);
    ASSERT_EQ(exp2, res2);
}

TEST(testMatrixConstructor, testMoveConstructor)
{
    myMatrix::Matrix<int> mat1(3, 3);
    myMatrix::Matrix<int> mat2(std::move(mat1));

    const auto exp = mat2.getCols();

    ASSERT_EQ(exp, 3);
}

TEST(testMatrixConstructor, testMoveAssigment)
{
    myMatrix::Matrix<int> mat1(3, 3);
    myMatrix::Matrix<int> mat2;

    mat2 = std::move(mat1);

    const auto exp = mat2.getCols();

    ASSERT_EQ(exp, 3);
}

TEST(testMatrixCalculations, testMultiplication)
{
    myMatrix::Matrix<int> mat1(3, 3);
    myMatrix::Matrix<int> mat2(3, 3);

    for (auto &it: mat1)
    {
        it = 3;
    }

    for (auto &it : mat2)
    {
        it = 3;
    }

    myMatrix::Matrix<int> mat3 = mat1 * mat2;

    for (auto it : mat3)
    {
        ASSERT_EQ(it, 27);
    }
}

TEST(testMatrixCalculations, testAddition)
{

    myMatrix::Matrix<int> mat1(3, 3);
    myMatrix::Matrix<int> mat2(3, 3);

    for (auto &it : mat1)
    {
        it = 3;
    }

    for (auto &it : mat2)
    {
        it = 3;
    }

    myMatrix::Matrix<int> mat3 = mat1 + mat2;

    for (auto it : mat3)
    {
        ASSERT_EQ(it, 6);
    }
}

TEST(testMatrixCalculations, testDifference)
{

    myMatrix::Matrix<int> mat1(3, 3);
    myMatrix::Matrix<int> mat2(3, 3);

    for (auto &it : mat1)
    {
        it = 3;
    }

    for (auto &it : mat2)
    {
        it = 2;
    }

    myMatrix::Matrix<int> mat3 = mat1 - mat2;

    for (auto it : mat3)
    {
        ASSERT_EQ(it, 1);
    }
}