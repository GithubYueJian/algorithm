/*
* Purpose: Bubble sorting
* Author: Jian Yue
* Data:   2020/08/19
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;

void insert_sort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); ++i)
	{
		int base = arr[i];
		int j = i - 1;
		while (j>=0&& arr[j]>base)
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = base;
	}
}
