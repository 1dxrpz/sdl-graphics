#include <vector>
#include <cmath>
#ifndef matrix4_h
#define matrix4_h

class matrix4
{
private:
    std::vector<std::vector<float>> data = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

public:
    matrix4();
    matrix4(std::vector<std::vector<float>> data);
    //~matrix4();
    matrix4* multiply(matrix4 matrix);
    matrix4* add(matrix4 matrix);
    matrix4* subtract(matrix4 matrix);
    matrix4* transpose();
    matrix4* rotate(float x, float y, float z);
    matrix4* scale(float x, float y, float z);
    matrix4* translate(float x, float y, float z);
    matrix4* project(float aspect, float fov, float far, float near);
    void display();
};

#endif