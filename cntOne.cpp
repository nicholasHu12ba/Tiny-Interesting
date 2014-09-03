#pragma warning(disable:4996)

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

/*
Author:     Chikun Hu, nicholas.hu.12ba@gmail.com
Date:       Sept 3, 2014
Problem:    count the number of 1 form 1 to N 
			e.g. 12 : 1,10,11,12 -> total 5 timest
			time complex: 2^log(lg(n)) = lg(n)
			
Difficulty: Easy
*/

long long cntOne(long long n) {
	if (n < 10) return 1;
	if (n == 0) return 0;

	long long tmp = n;
	int highbit = 0, bit = 0;
	while (tmp >= 10) {
		tmp /= 10;
		++bit;
	}
	highbit = tmp;
	long long base = (long long)pow(10, bit);
	if (highbit == 1)
		return highbit*cntOne(base - 1) + cntOne(n - highbit*base) + (n - base + 1);
	else
		return highbit*cntOne(base - 1) + cntOne(n - highbit*base) + base;
}