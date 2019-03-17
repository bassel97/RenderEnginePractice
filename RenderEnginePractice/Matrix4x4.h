#pragma once
#include <iostream>

class Matrix4x4
{
	float** matrixNumbers;

	char name;
public:
	Matrix4x4();
	Matrix4x4(char _name);
	Matrix4x4(const Matrix4x4& p);
	~Matrix4x4();

	Matrix4x4 operator=(const Matrix4x4 &rhs);
	Matrix4x4 operator+(const Matrix4x4 &rhs);

	float *& operator[](const int i) const;

	friend std::ostream & operator<<(std::ostream & out, Matrix4x4 & matrix);
};

