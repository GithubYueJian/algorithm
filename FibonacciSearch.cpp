/*
* Purpose: fibonacci searching
* Author: Jian Yue
* Data:   2020/08/22
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;

int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
	{
		int s0 = 0;
		int s1 = 1;
		int s2 = 1;
		for (int i = 2; i <= n; ++i)
		{
			s2 = s1 + s0;
			s0 = s1;
			s1 = s2;
		}
		return s2;
	}
}
int fib_search(vector<int> &arr,int key)
{
	//find the largest index of fib arrary
	int i = 0;
	int org_length = arr.size();
	while (fib(i) < arr.size())
	{
		++i;
	}

	//fill the arr 
	while (arr.size() < fib(i))
	{
		arr.push_back(arr[arr.size()- 1]);
	}
	
	int left = 0, right = arr.size() - 1;

	while (left <= right)
	{
		int mid =left+fib(i - 1)-1;
		//cout << mid << endl;
		if (arr[mid] == key)
			return mid < org_length ? mid : org_length - 1;
		else if (arr[mid] < key)
		{
			left = mid + 1;
			i = i - 2;
		}
			
		else
		{
			right = mid - 1;
			i = i - 1;
		}
			
	}
	return -1;
}
int main()
{
	vector<int> arr{ 5,6,7,8,9, 10 , 11, 12 ,13, 14,150 };
	//int index = Interpolation_Search(a, 11, 13);
	cout <<fib_search(arr,15) << endl;
}
