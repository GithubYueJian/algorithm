#include<iostream>
using namespace std;
int binarySearch(int *arr, int low, int high, int target)//递归实现
{
	int middle = (low + high) / 2;
	if (low > high)
		return -1;
	if (arr[middle] == target)
		return middle;
	if (arr[middle] > target)
		return binarySearch(arr, low, middle - 1, target);
	if (arr[middle] < target)
		return binarySearch(arr, middle + 1, high, target);

};

int main()
{
	int a[10] = { 5,6,7,8,9, 10 , 11, 12 ,13, 14 };
	int index = binarySearch(a, 0, 9, 12);
	cout << index << endl;
	system("pause");
}
