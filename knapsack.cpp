/*
* Purpose: knapsack problem
* Author: Jian Yue
* Data:   2020/09/15
*/

#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include "ListNode.h"

vector<vector<int>> f(5, vector<int>(9,0));
vector<int> w{ 0,2,3,4,5 };
vector<int> v{ 0,3,4,5,8 };


int main() {
	int i, j;
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 9; j++)
		{
			if (w[i] > j)
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
		}
		
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
			printf("f[%d][%d]=%d\n", i, j, f[i][j]);
	
	return 0;
}

// reference
// https://www.bilibili.com/video/BV1g7411B7SP?from=search&seid=13054477600005210869&spm_id_from=333.337.0.0
