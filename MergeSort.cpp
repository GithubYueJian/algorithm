/*
* Purpose: merge sorting
* Author: Jian Yue
* Date:   2020/10/04 revised
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;

void merge(vector<int> &arr,int p,int q,int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int>L(n1+1);
	vector<int>R(n2+1);
	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int i = 0; i < n2; i++)
		R[i] = arr[q + i + 1];
	L[n1] = INT16_MAX;
	R[n2] = INT16_MAX;
	int i = 0, j = 0;
	for (int k = p; k < r + 1; k++)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
}
void merge_sort(vector<int> &arr, int p, int r)
{
	if (p == r)
		return;
	int q = (p + r) / 2;
	merge_sort(arr, p, q);
	merge_sort(arr, q + 1, r);
	merge(arr, p, q, r);
}

int main()
{
	vector<int> arr {5, 2, 4, 7, 1, 3, 2, 6};
	merge_sort(arr, 0, 7);

	return 0;
}
