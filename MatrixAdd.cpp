/*
* Purpose: Matrix addition
* Author: Jian Yue
* Data:   2020/08/22
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;
const int Rows = 2, Cols = 3;

void MatrixDesplay(int* A, int Rows, int Cols)
{
	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Cols; ++j)
		{
			cout<<A[i*Cols + j]<<" ";
		}
		cout << endl;
	}
}

void MatrixAdd(int* A, int *B, int *C, int Rows, int Cols)
{
	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Cols; ++j)
		{
			C[i*Cols + j] = A[i*Cols + j] + B[i*Cols + j];
		}
	}
}

int main()
{
	int A[Rows][Cols] = { {1,3,5},
	{7,9,11} };
	int B[Rows][Cols] = { {2,4,6},
	{8,10,12} };
	int C[Rows][Cols] = {0};
	MatrixAdd(A[0], B[0], C[0], Rows, Cols);
	MatrixDesplay(C[0], Rows, Cols);
}
