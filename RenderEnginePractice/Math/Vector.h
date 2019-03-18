#pragma once
#include <iostream>

template<int rows, int cols>
class Matrix;

template<int rows>
class Vector
{
	float vec[rows];

public:

	//==============================================Cons|Dest==============================================//
	Vector()
	{
		for (int i = 0; i < rows; i++)
		{
			vec[i] = 0;
		}
	}

	Vector(const Vector& v)
	{
		for (int i = 0; i < rows; i++)
		{
			vec[i] = v.vec[i];
		}
	}

	~Vector()
	{
	}


	//==============================================Operators==============================================//
	float& operator[](const int i)
	{
		return vec[i];
	}

	Vector operator=(const Vector &rhs)
	{
		for (int i = 0; i < rows; i++)
		{
			vec[i] = rhs.vec[i];
		}

		return *this;
	}

	Vector operator+(const Vector &rhs)
	{
		Vector ans;

		for (int i = 0; i < rows; i++)
		{
			ans[i] = vec[i] + rhs.vec[i];
		}

		return ans;
	}

	Vector operator-(const Vector &rhs)
	{
		Vector ans;

		for (int i = 0; i < rows; i++)
		{
			ans[i] = vec[i] - rhs.vec[i];
		}

		return ans;
	}

	Matrix<rows, rows> operator*(const Vector &rhs)
	{
		Matrix<rows, rows> ans;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				ans[i][j] = vec[i] * rhs.vec[j];
			}
		}

		return ans;
	}

	//==============================================friend funcs==============================================//
	friend std::ostream & operator<<(std::ostream & out, Vector & vector)
	{
		for (int i = 0; i < rows; i++)
		{
			out << '[' << vector[i] << ']';
			out << std::endl;
		}

		return out;
	}
};