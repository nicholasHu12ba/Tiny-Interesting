#pragma warning(disable:4996)

#include <cstdio>
#include <tchar.h>
#include <iostream>
using namespace std;

/*
Author:     Chikun Hu, nicholas.hu.12ba@gmail.com
Date:       Aug 25, 2014
Problem:    zigzag matrix
Difficulty: Easy

11
	0   2   3   9   10  20  21  35  36  54  55
	1   4   8   11  19  22  34  37  53  56  75
	5   7   12  18  23  33  38  52  57  74  76
	6   13  17  24  32  39  51  58  73  77  92
	14  16  25  31  40  50  59  72  78  91  93
	15  26  30  41  49  60  71  79  90  94 105
	27  29  42  48  61  70  80  89  95 104 106
	28  43  47  62  69  81  88  96 103 107 114
	44  46  63  68  82  87  97 102 108 113 115
	45  64  67  83  86  98 101 109 112 116 119
	65  66  84  85  99 100 110 111 117 118 120
*/

int _tmain(int argc, _TCHAR* argv[]) {
	int N;
	int s, i, j;
	int squa;
	scanf("%d", &N);
	int** matrix = new int*[N];
	for (i = 0; i < N; ++i)
		matrix[i] = new int[N];
	squa = N*N;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			s = i + j;
			if (s < N) 
				matrix[i][j] = s*(s + 1) / 2 + ((i + j) % 2 == 0 ? i : j);
			else {
				s = 2 * (N - 1) - s;
				matrix[i][j] = squa - s*(s + 1) / 2 - (N - ((i + j) % 2 == 0 ? i : j));
			}
		}
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) 
			printf("%4d", matrix[i][j]);
		printf("\n");
	}
	for (i = 0; i < N; ++i)
		delete[] matrix[i];
	delete[] matrix;

	system("pause");
	return 0;
}