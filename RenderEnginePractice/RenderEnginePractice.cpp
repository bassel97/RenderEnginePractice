// RenderEnginePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Math/Matrix.h"
#include "Math/Vector.h"

using namespace std;

int main()
{

	Vector<3> vec3;
	vec3[0] = 1;
	vec3[1] = 2;
	vec3[2] = 3;
	cout << vec3 << endl;

	Matrix<3,3> mat3x3 = vec3 * vec3;

	cout << mat3x3;



	return 1;
}
