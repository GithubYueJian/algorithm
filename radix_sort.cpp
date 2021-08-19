/***************************************************************
Program or Function Name: radix sort
Last Revised: 19/08/2021
Programmer: Jian Yue
Description: radix sort
***************************************************************/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;
#include<queue>

void radix_sort(vector<int>& arr)
{
	vector<queue<int>> container(10);
	for (int m = 0; m < 3; m++) {
		for (int i = 0; i < arr.size(); i++) {
			int temp = arr[i];
			for (int j = 0; j < m; j++) temp /= 10; 
			container[temp % 10].push(arr[i]); 
		}
		arr.clear();
		for (int i = 0; i < 10; i++) { 
			while (!container[i].empty()) {
				arr.push_back(container[i].front());
				container[i].pop();
			}
		}
	}
}
int main(void)
{
	vector<int> arr{ 421,240,115,532,305,430,124 };
	cout << "Org: " << std::endl;
	for (auto c : arr)
	{
		cout << c << " ";
	}
	cout << std::endl;
	cout << "Sorted: " << std::endl;
	radix_sort(arr);
	for (auto c : arr)
	{
		cout << c << " ";
	}
	cout << std::endl;

	return 0;
}
