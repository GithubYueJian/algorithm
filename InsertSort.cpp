/*
* Purpose: insert sorting
* Author: Jian Yue
* Date:   2020/10/04 revised
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;

void insert_sort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		int j = i - 1,key = arr[i];
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
