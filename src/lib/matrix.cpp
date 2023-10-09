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

matrix4* matrix4::translate(float x, float y, float z) {
	matrix4* m_translate = new matrix4({
		{1, 0, 0, x},
		{0, 1, 0, y},
		{0, 0, 1, z},
		{0, 0, 0, 1}
	});
	return m_translate->multiply(*this);
}
matrix4* matrix4::scale(float x, float y, float z) {
	matrix4* m_scale = new matrix4({
		{x, 0, 0, 0},
		{0, y, 0, 0},
		{0, 0, z, 0},
		{0, 0, 0, 1}
	});
	return m_scale->multiply(*this);
}
matrix4* matrix4::rotate(float x, float y, float z) {
	matrix4* result = this;
	if (x != 0)
	{
		matrix4* m_Rx = new matrix4({
			{1, 0, 0, 0},
			{0, std::cos(x), std::sin(x), 0},
			{0, -std::sin(x), std::cos(x), 0},
			{0, 0, 0, 1}
		});
		result = m_Rx->multiply(*result);
	}
	if (y != 0)
	{
		matrix4* m_Ry = new matrix4({
			{std::cos(y), 0, std::sin(y), 0},
			{0, 1, 0, 0},
			{-std::sin(y), 0, std::cos(y), 0},
			{0, 0, 0, 1}
		});
		result = m_Ry->multiply(*result);
	}
	if (z != 0)
	{
		matrix4* m_Rz = new matrix4({
			{std::cos(z), -std::sin(z), 0, 0},
			{std::sin(z), std::cos(z), 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
		});
		result = m_Rz->multiply(*result);
	}
	return result;
}

matrix4* matrix4::project(float aspect, float fov, float far, float near) {
	matrix4* m_projection = new matrix4({
		{1 / (aspect * std::tan(fov / 2)), 0, 0, 0},
		{0, 1 / (std::tan(fov / 2)), 0, 0},
		{0, 0, -((far + near) / (far - near)), 0},
		{0, 0, 0, 0}
	});
}