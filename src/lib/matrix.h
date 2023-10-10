#include <vector>

class matrix;
class vec3;

#ifndef matrix_h
#define matrix_h

class matrix
{
private:
    int size_n, size_m;
public:
    std::vector<std::vector<float>> data = {};
    matrix(int n, int m);
    matrix(std::vector<std::vector<float>> data);
    //~matrix();
    vec3* toVec3();
    matrix* multiply(matrix matrix);
    matrix* add(matrix matrix);
    matrix* subtract(matrix matrix);
    matrix* transpose();
    matrix* rotate(float x, float y, float z);
    matrix* scale(float x, float y, float z);
    matrix* translate(float x, float y, float z);
    matrix* project(float aspect, float fov, float far, float near);
    void display();
};

#endif

#ifndef vec3_h
#define vec3_h

class vec3
{
private:
    float x, y, z;
public:
    
    vec3();
    vec3(float x, float y, float z);
    matrix* multiply(matrix m_matrix);
    //~matrix4();
    matrix* toMatrix();
    void display();
};

#endif