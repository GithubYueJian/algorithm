/*
* Purpose: Interpolation Searching
* Author: Jian Yue
* Date:   2020/08/20
*/
#include<iostream>
using namespace std;
int Interpolation_Search(int *arr, int length, int target)
{
	int left = 0;
	int right = length - 1;
	int mid=0;

	while (left <= right)
	{
		mid = left+(right - left)*(target - arr[left]) / (arr[right] - arr[left]);
		if (target < arr[mid])
			right = mid - 1;
		else if (target > arr[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;

}
int main()
{
	int a[11] = { 5,6,7,8,9, 10 , 11, 12 ,13, 14,150 };
	int index = Interpolation_Search(a, 11, 13);
	cout << index << endl;
}
