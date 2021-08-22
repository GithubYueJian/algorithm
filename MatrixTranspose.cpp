/*
* Purpose: Matrix Transpose
* Author: Jian Yue
* Data:   2020/08/22
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;
const int Rows = 4, Cols = 3;

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

void MatrixTranspose(int* A, int *B, int Rows_A, int Cols_A)
{
	
	for (int i = 0; i < Cols_A; ++i)
	{
		for (int j = 0; j < Rows_A; ++j)
			B[i*Rows_A + j] = A[j*Cols_A + i];
		
	}
}

int main()
{
	int A[Rows][Cols] = { {1,1,1},
	{2,2,2} , {3,3,3}, {4,4,4} };
	int B[Cols][Rows] = { 0 };
	MatrixTranspose(A[0], B[0], Rows, Cols);
	MatrixDesplay(A[0], Rows, Cols);
	MatrixDesplay(B[0], Cols, Rows);
}
