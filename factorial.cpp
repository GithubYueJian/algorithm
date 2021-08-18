/*
* Purpose: get n!;
* Author: Jian Yue
* Data:   2020/08/18
*/

#include <iostream>
using namespace std;
int factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}
