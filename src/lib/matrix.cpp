#include "matrix.h"
#include <math.h>
#include <iostream>
#define M_PRECISION 1.0e-6f

float precision(float n) {
    return n < M_PRECISION && n > -M_PRECISION ? 0 : n;
}

matrix::matrix(int n, int m)
{
	size_n = n;
	size_m = m;
	for (int a = 0; a < n; a++)
	{
		std::vector<float> data_row;
		for (int b = 0; b < m; b++)
		{
			data_row.push_back(0.0f);
		}
		data.push_back(data_row);
	}

}
matrix::matrix(std::vector<std::vector<float>> data)
{
	this->data = data;
	size_n = data.size();
	size_m = data[0].size();
}

vec3* matrix::toVec3() {
	return new vec3(this->data[0][0], this->data[1][0], this->data[2][0]);
}

matrix* matrix::multiply(matrix m_matrix)
{
	matrix *result = new matrix(this->size_n, m_matrix.size_m);
	for (int i = 0; i < result->size_n; i++)
	{
		for (int j = 0; j < result->size_m; j++)
		{
			float res = 0;
			for (int a = 0; a < this->size_m; a++)
			{
				res += this->data[i][a] * m_matrix.data[a][j];
			}
			result->data[i][j] = res;
		}
	}
	return result;
}

matrix* matrix::add(matrix m_matrix)
{
	matrix *result = new matrix(this->size_n, m_matrix.size_m);
	for (int i = 0; i < result->size_n; i++)
	{
		for (int j = 0; j < result->size_m; j++)
		{
			result->data[i][j] = this->data[i][j] + m_matrix.data[i][j];
		}
	}
	return result;
}
matrix* matrix::subtract(matrix m_matrix)
{
	matrix *result = new matrix(this->size_n, m_matrix.size_m);
	for (int i = 0; i < result->size_n; i++)
	{
		for (int j = 0; j < result->size_m; j++)
		{
			result->data[i][j] = this->data[i][j] - m_matrix.data[i][j];
		}
	}
	return result;
}

float det(std::vector<std::vector<float>> matrix) {
	return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] -
		(matrix[0][1] * matrix[1][1] * matrix[2][0] + matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][0] * matrix[2][1] * matrix[1][2]);
}

void matrix::display() {
	for (int i = 0; i < this->size_n; i++)
	{
		for (int j = 0; j < this->size_m; j++)
		{
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

matrix* matrix::transpose() {
	matrix* result = new matrix({
		{data[0][0], data[1][0], data[2][0], data[3][0]},
		{data[0][1], data[1][1], data[2][1], data[3][1]},
		{data[0][2], data[1][2], data[2][2], data[3][2]},
		{data[0][3], data[1][3], data[2][3], data[3][3]}
	});
	return result;
}

matrix* matrix::translate(float x, float y, float z) {
	matrix* m_translate = new matrix({
		{1, 0, 0, x},
		{0, 1, 0, y},
		{0, 0, 1, z},
		{0, 0, 0, 1}
	});
	return m_translate->multiply(*this);
}
matrix* matrix::scale(float x, float y, float z) {
	matrix* m_scale = new matrix({
		{x, 0, 0, 0},
		{0, y, 0, 0},
		{0, 0, z, 0},
		{0, 0, 0, 1}
	});
	return m_scale->multiply(*this);
}
matrix* matrix::rotate(float x, float y, float z) {
	matrix* m_Rx = new matrix({
		{1, 0, 0, 0},
		{0, cos(x), -sin(x), 0},
		{0, sin(x), cos(x), 0},
		{0, 0, 0, 1}
	});
	matrix* m_Ry = new matrix({
		{cos(y), 0, sin(y), 0},
		{0, 1, 0, 0},
		{-sin(y), 0, cos(y), 0},
		{0, 0, 0, 1}
	});
	matrix* m_Rz = new matrix({
		{precision(cosf(z)), precision(-sinf(z)), 0, 0},
		{precision(sinf(z)), precision(cosf(z)), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	});
	return m_Rx->multiply(*m_Ry->multiply(*m_Rz->multiply(*this)));
}

matrix* matrix::project(float aspect, float fov, float far, float near) {
	matrix* m_projection = new matrix({
		{1 / (aspect * tan(fov / 2.0f)), 0, 0, 0},
		{0, 1.0f / (tan(fov / 2.0f)), 0, 0},
		{0, 0, -((far + near) / (far - near)), -2.0f * far * near * (far - near)},
		{0, 0, -1, 0}
	});

	return m_projection->multiply(*this);
}

vec3::vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

matrix* vec3::toMatrix() {
    matrix* m_identity = new matrix({
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    });
    return this->multiply(*m_identity);
}
matrix* vec3::multiply(matrix m_matrix) {
    matrix* vec = new matrix({
        {x},
        {y},
        {z},
        {0}
    });
    matrix* result = m_matrix.multiply(*vec);
    float w = result->data[3][0];
    if (w != 0.0f)
    {
        std::cout << w << std::endl;
        result->data[0][0] /= w;
        result->data[1][0] /= w;
        result->data[2][0] /= w;
    }
    result->data[3][0] = 1;
    return result;
}

void vec3::display() {
    std::cout << x << " " << y << " " << z << std::endl;
}

float vec3::magnitude() {
	return sqrt(x * x + y * y + z * z);
}

vec3* vec3::normalize() {
	float length = this->magnitude();
	return new vec3(this->x / length, this->y / length, this->z / length);
}
vec3* vec3::dotProduct(vec3* v_vec) {
	return new vec3(x * v_vec->x, y * v_vec->y, z * v_vec->z);
}