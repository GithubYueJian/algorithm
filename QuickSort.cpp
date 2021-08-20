/*
* Purpose: quick sorting
* Author: Jian Yue
* Data:   2020/08/06
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;

void quicksort(int left, int right, vector<int> &arr)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	int temp = 0;
	int base = arr[left];
	while (i < j)
	{
		while (i<j&&arr[j]>=base)
			j--;
		while (i < j&&arr[i] <= base)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}

	}
	arr[left] = arr[i];
	arr[i] = base;
	quicksort(left, i - 1, arr);
	quicksort(i + i, right, arr);

}
int main(void)
{
	vector<int> arr{ 5,3,70,-12,-9,100,8,-3,50,300,6 };
	cout << "Org: " << std::endl;
	for (auto c : arr)
	{
		cout << c << " ";
	}
	cout << std::endl;
	cout << "Sorted: " << std::endl;
	quicksort(0, 10, arr);
	for (auto c : arr)
	{
		cout << c << " ";
	}
	cout << std::endl;

	return 0;
}
