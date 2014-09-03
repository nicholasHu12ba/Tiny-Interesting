#pragma warning(disable:4996)

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Author:     Chikun Hu, nicholas.hu.12ba@gmail.com
Date:       Sept 3, 2014
Problem:    calculate the ratio of the sum of n dice.
			e.g. n = 3:
				sum =   3 : 0.004630
				sum =   4 : 0.013889
				sum =   5 : 0.027778
				sum =   6 : 0.046296
				sum =   7 : 0.069444
				sum =   8 : 0.097222
				sum =   9 : 0.115741
				sum =  10 : 0.125000
				sum =  11 : 0.125000
				sum =  12 : 0.115741
				sum =  13 : 0.097222
				sum =  14 : 0.069444
				sum =  15 : 0.046296
				sum =  16 : 0.027778
				sum =  17 : 0.013889
				sum =  18 : 0.004630
				ratio : 1
			
Difficulty: Easy
*/

void nDice(int n) {
	if (n < 1) return;
	vector<vector<int>> dp(2, vector<int>(6 * n + 1, 0));
	int flag = 0, total = pow(6, n);
	for (int i = 1; i <= 6; ++i)
		dp[flag][i] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int t = 0; t<i; ++t)
			dp[!flag][t] = 0;
		for (int j = i; j <= 6 * i; ++j) {
			dp[!flag][j] = 0;
			for (int k = 1; k <= 6; ++k) 
				if (j>k && dp[flag][j - k] > 0) dp[!flag][j] += dp[flag][j - k];
		}
		flag = !flag;
	}
	float ratio = 0;
	for (int i = n; i <= 6 * n; ++i) {
		printf("sum =%4d : %f\n", i, (float)dp[flag][i] / total);
		ratio += (float)dp[flag][i] / total;
	}
	// verify if ratio == 1.
	cout << "ratio : " << ratio << endl;
}