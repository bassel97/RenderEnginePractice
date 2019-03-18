#pragma once
#include <iostream>
#include "Vector.h"

template<int rows, int cols>
class Matrix
{
	Vector<rows> vec[cols];

public:

	//==============================================Cons|Dest==============================================//
	Matrix()
	{
	}

	Matrix(const Matrix& m)
	{
		for (int i = 0; i < cols; i++)
		{
			vec[i] = m.vec[i];
		}
	}

	~Matrix()
	{
	}


	//==============================================Operators==============================================//
	Vector<rows>& operator[](const int i)
	{
		return vec[i];
	}

	Matrix operator=(const Matrix &rhs)
	{
		for (int i = 0; i < cols; i++)
		{
			vec[i] = rhs.vec[i];
		}

		return *this;
	}

	Matrix operator+(const Matrix &rhs)
	{
		Matrix ans;

		for (int i = 0; i < cols; i++)
		{
			ans[i] = vec[i] + rhs.vec[i];
		}

		return ans;
	}

	Matrix operator-(const Matrix &rhs)
	{
		Matrix ans;

		for (int i = 0; i < cols; i++)
		{
			ans[i] = vec[i] - rhs.vec[i];
		}

		return ans;
	}

	//==============================================friend funcs==============================================//
	friend std::ostream & operator<<(std::ostream & out, Matrix & matrix)
	{
		for (int i = 0; i < rows; i++)
		{
			out << "[";
			for (int j = 0; j < cols; j++)
			{
				out << matrix[j][i];
				if (j != cols - 1)out << "," << "\t";
			}
			out << "]" << std::endl;
		}

		return out;
	}
};