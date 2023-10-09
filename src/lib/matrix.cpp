#include "matrix.h"
#include <iostream>

matrix4::matrix4(/* args */)
{
    int a = data[0][0];
}
matrix4::matrix4(std::vector<std::vector<float>> data)
{
    this->data = data;
}

matrix4* matrix4::multiply(matrix4 matrix)
{
    matrix4 *result = new matrix4();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            float res = 0;
            for (int a = 0; a < 4; a++)
            {
                res += this->data[i][a] * matrix.data[a][j];
            }
            result->data[i][j] = res;
        }
    }
    return result;
}

matrix4* matrix4::add(matrix4 matrix)
{
    matrix4 *result = new matrix4();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result->data[i][j] = this->data[i][j] + matrix.data[i][j];
        }
    }
    return result;
}
matrix4* matrix4::subtract(matrix4 matrix)
{
    matrix4 *result = new matrix4();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result->data[i][j] = this->data[i][j] - matrix.data[i][j];
        }
    }
    return result;
}

float det(std::vector<std::vector<float>> matrix) {
    return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] -
        (matrix[0][1] * matrix[1][1] * matrix[2][0] + matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][0] * matrix[2][1] * matrix[1][2]);
}

void matrix4::display() {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

matrix4* matrix4::transpose() {
    matrix4* result = new matrix4({
        {data[0][0], data[1][0], data[2][0], data[3][0]},
        {data[0][1], data[1][1], data[2][1], data[3][1]},
        {data[0][2], data[1][2], data[2][2], data[3][2]},
        {data[0][3], data[1][3], data[2][3], data[3][3]}
    });
    return result;
}