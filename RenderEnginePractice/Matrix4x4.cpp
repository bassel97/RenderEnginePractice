#include "Matrix4x4.h"



Matrix4x4::Matrix4x4()
{
	matrixNumbers = new float*[4];

	for (int i = 0; i < 4; i++)
	{
		matrixNumbers[i] = new float[4];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixNumbers[i][j] = 0;
		}
	}
}

Matrix4x4::Matrix4x4(char _name):Matrix4x4()
{	
	name = _name;
}

Matrix4x4::Matrix4x4(const Matrix4x4& p) {

	name = p.name;

	matrixNumbers = new float*[4];

	for (int i = 0; i < 4; i++)
	{
		matrixNumbers[i] = new float[4];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixNumbers[i][j] = p.matrixNumbers[i][j];
		}
	}
}

Matrix4x4::~Matrix4x4()
{
	std::cout << name << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete matrixNumbers[i];
	}

	delete matrixNumbers;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &rhs)
{
	Matrix4x4 ans('Z');

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ans.matrixNumbers[i][j] = matrixNumbers[i][j] + rhs.matrixNumbers[i][j];
		}
	}

	return ans;
}

Matrix4x4 Matrix4x4::operator=(const Matrix4x4 &rhs)
{
	name = rhs.name;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrixNumbers[i][j] = rhs.matrixNumbers[i][j];
		}
	}

	return *this;
}

float*& Matrix4x4::operator[](const int i) const
{
	return matrixNumbers[i];
}

std::ostream& operator << (std::ostream &out, Matrix4x4 &matrix)
{
	out << "Matrix " << matrix.name << std::endl;
	for (int j = 0; j < 4; j++)
	{
		out << '[';
		for (int i = 0; i < 4; i++)
		{
			out << matrix[i][j];
			if (i != 3)out << "," << "\t";
		}
		out << ']';
		out << std::endl;
	}

	return out;
}