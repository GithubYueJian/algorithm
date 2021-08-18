/*
* Purpose: get fibonacci sequence;
* Author: Jian Yue
* Data:   2020/08/18
*/

#include <iostream>
using namespace std;
int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int fib1(int n)
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

		for(int i = 2; i <= n; ++i)
		{
			s2 = s1 + s0;
			s0 = s1;
			s1 = s2;
		}
		return s2;

	}
		
}
