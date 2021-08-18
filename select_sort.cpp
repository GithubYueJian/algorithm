/*
* Purpose: select_sort
* Author: Jian Yue
* Data:   2020/08/18
*/

#include <iostream>
using namespace std;
#include<vector>

void select_sort(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		int index_min = i;
		for (int j = i; j < arr.size(); ++j)
		{
			
			if (arr[j]< arr[index_min])
			{
				index_min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index_min];
		arr[index_min] = temp;
	}
}
