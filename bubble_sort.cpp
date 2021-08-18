/*
* Purpose: Bubble sorting
* Author: Jian Yue
* Data:   2020/08/18
*/

#include <iostream>
using namespace std;
#include<vector>

void bubble_sort(vector<int> &arr)
{
	for (int i = 0; i < arr.size()-1; ++i)
	{
		for (int j = 0; j < arr.size()-1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;

			}
		}
	}
}
