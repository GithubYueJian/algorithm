/*
* Purpose: merge sorting
* Author: Jian Yue
* Data:   2020/08/19
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;

void merge(vector<int> &arr, int L, int M, int R)
{
	int left_size = M - L;
	int right_size = R - M + 1;
	vector<int> left_arr(left_size);
	vector<int> right_arr(right_size);
	int i, j, k;
	//fill the left array
	for (int i = L; i < M; i++)
	{
		left_arr[i - L] = arr[i];
	}

	//fill the right array
	for (int i = M; i <= R; i++)
	{
		right_arr[i - M] = arr[i];
	}

	//merge into the original arr
	i = 0, j = 0, k = L;
	while (i < left_size && j < right_size)
	{
		if (left_arr[i] < right_arr[j])
		{
			arr[k] = left_arr[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = right_arr[j];
			j++;
			k++;
		}

	}
	while (i < left_size)
	{
		arr[k] = left_arr[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		arr[k] = right_arr[j];
		j++;
		k++;
	}
}
void MergeSort(vector<int> &arr, int L, int R)
{
	if (L == R)
	{
		return;
	}
	else
	{
		int M = (L + R) / 2;
		MergeSort(arr, L, M);
		MergeSort(arr, M + 1, R);
		merge(arr, L, M + 1, R);
	}

}
