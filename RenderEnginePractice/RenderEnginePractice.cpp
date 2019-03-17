// RenderEnginePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Matrix4x4.h"

using namespace std;

int main()
{
	cout << "Hello Render Engine!\n";

	Matrix4x4 matA('A');

	matA[2][3] = 30;

	Matrix4x4 matZ('Z');
	matZ = matA;

	cout << matZ;

	cout << matA[2][3] << endl;

	cout << matA << endl;

	Matrix4x4 matC;
	matC = matA + matZ;

	//matA = matC;

	cout << matC << endl;


	return 1;
}
