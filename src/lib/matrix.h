#include <vector>
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
    matrix4(/* args */);
    matrix4(std::vector<std::vector<float>> data);
    //~matrix4();
    matrix4* multiply(matrix4 matrix);
    matrix4* add(matrix4 matrix);
    matrix4* subtract(matrix4 matrix);
    matrix4* transpose();
    void display();
};

#endif