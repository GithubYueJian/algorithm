/*
* Purpose: Matrix MatrixMultiply
* Author: Jian Yue
* Data:   2020/08/22
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;
const int Rows_A = 2, Cols_A = 3, Rows_B = 3, Cols_B = 4;

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

void MatrixMultiply(int* A, int *B, int *C, int Rows_A, int Cols_A, int Rows_B, int Cols_B)
{
	if (Cols_A != Rows_B)
	{
		cout << "error Cols_A != Rows_B" << endl;
		return;
	}
	for (int i = 0; i < Rows_A; ++i)
	{
		for (int j = 0; j < Cols_B; ++j)
		{
			for (int k = 0; k < Cols_A; ++k)
			{
				C[i*Cols_B + j] += (A[i*Cols_A + k] * B[k*Cols_B + j]);
			}
			
		}
	}
}

int main()
{
	int A[Rows_A][Cols_A] = { {1,1,1},
	{2,2,2} };
	int B[Rows_B][Cols_B] = { {3,4,5,6},
	{3,4,5,6},{3,4, 5,6} };
	int C[Rows_A][Cols_B] = {0};
	MatrixMultiply(A[0], B[0], C[0], Rows_A, Cols_A,  Rows_B,  Cols_B);
	MatrixDesplay(C[0], Rows_A, Cols_B);
}
