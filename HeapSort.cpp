/*
* Purpose: Heap sorting
* Author: Jian Yue
* Data:   2020/08/20
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;

void heapify(int tree[], int n, int i)
{
	if (i >= n)
	{
		return;
	}
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if (c1<n && tree[c1]>tree[max])
	{
		max = c1;
	}
	if (c2<n && tree[c2]>tree[max])
	{
		max = c2;
	}
	if (max != i)
	{
		swap(tree[max], tree[i]);
		heapify(tree, n, max);
	}

}
void BuildHeap(int tree[], int n)
{
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	for (int i = parent; i >= 0; i--)
	{
		heapify(tree, n, i);

	}
}
void HeapSort(int tree[], int n)
{
	BuildHeap(tree, n);
	for (int i = n - 1; n >= 0; i--)
	{
		swap(tree[i], tree[0]);
		heapify(tree, i, 0);
		if (i == 0)
			break;
	}

}

int main()
{
	int tree[] = { 2,5,3,1,10,16,0,-5,8,73,6,27,-31,14 };
	int n = 14;
	HeapSort(tree, n);

	for (int i = 0; i < n; i++)
		printf("%d ", tree[i]);

	return 0;
}
