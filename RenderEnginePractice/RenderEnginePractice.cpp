// RenderEnginePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Math/EngineMathHeader.h"

using namespace std;

int main()
{

	// Test Ops

	mat3x3 matA;
	cout << matA;

	
	Matrix<1, 3> mat1x3;

	cout << mat1x3.rowSize << endl;

	for (int i = 0; i < mat1x3.rowSize; i++)
	{
		for (int j = 0; j < mat1x3.columnSize; j++)
		{
			mat1x3[j][i] = rand() % 20;
		}
	}
	cout << mat1x3 << endl;

	Matrix<3, 2> mat3x2;
	for (int i = 0; i < mat3x2.rowSize; i++)
	{
		for (int j = 0; j < mat3x2.columnSize; j++)
		{
			mat3x2[j][i] = rand() % 20;
			mat3x2[j][i] = rand() % 20;
		}
	}
	cout << mat3x2 << endl;

	Matrix<1, 2> mat1x2;
	mat1x2 = mat1x3 * mat3x2;
	cout << mat1x2 << endl;

	Vector<3> vec3;
	for (int i = 0; i < vec3.rowSize; i++)
	{
		vec3[i] = rand() % 20;
	}
	cout << vec3 << endl;

	mat1x3 = vec3.transpose();
	cout << mat1x3 << endl;

	return 1;
}
