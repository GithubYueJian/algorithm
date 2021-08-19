/*
* Purpose: shell sorting
* Author: Jian Yue
* Data:   2020/08/19
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;

void shell_sort(vector<int> &arr)
{
	int base = 0;
	int gap = arr.size() / 2;
	while (gap)
	{
		for (int i = gap; i < arr.size(); ++i)
		{
			base = arr[i];
			int j = i;
			while (j >= gap && arr[j-gap] > base)
			{
				arr[j] = arr[j-gap];
				j-=gap;
			}
			arr[j] = base;
		}
		gap /= 2;
	}
	
}
