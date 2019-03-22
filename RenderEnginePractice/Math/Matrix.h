#pragma once
#include <iostream>
#include "Vector.h"

/*	Matrix class with all its member variables	*/

template<int rows, int cols>
class Matrix
{

public:

	Vector<rows> vec[cols];

	const int rowSize = rows, columnSize = cols;

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

	const Vector<rows>& operator[](const int i) const
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

	template<int cols2>
	Matrix<rows, cols2> operator*(const Matrix<cols, cols2> &rhs) {
		Matrix<rows, cols2> ans;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols2; j++)
			{
				float val = 0;

				for (int k = 0; k < cols; k++)
				{
					val += vec[k][i] * rhs.vec[j][k];
				}

				ans.vec[j][i] = val;
			}
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