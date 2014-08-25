#pragma warning(disable:4996)

#include <cstdio>
#include <tchar.h>
#include <algorithm>
using namespace std;

/*
Author:     Chikun Hu, nicholas.hu.12ba@gmail.com
Date:       Aug 25, 2014
Problem:    spiral matrix
Difficulty: Easy

	73   74   75   76   77   78   79   80   81
	72   43   44   45   46   47   48   49   50
	71   42   21   22   23   24   25   26   51
	70   41   20    7    8    9   10   27   52
	69   40   19    6    1    2   11   28   53
	68   39   18    5    4    3   12   29   54
	67   38   17   16   15   14   13   30   55
	66   37   36   35   34   33   32   31   56
	65   64   63   62   61   60   59   58   57
*/

int foo(int x, int y) {
	int deep = max(abs(x), abs(y));
	int v = (2 * deep - 1)*(2 * deep - 1);
	if (y == -deep)
		v += 7 * deep + x;
	else if (x == deep)
		v += 1 * deep + y;
	else if (y == deep)
		v += 3 * deep - x;
	else
		v += 5 * deep - y;
	return v;
}

int _tmain(int argc, _TCHAR* argv[]) {
	int x, y;

	for (y = -4; y <= 4; ++y) {
		for (x = -4; x <= 4; ++x)
			printf("%5d", foo(x, y));
		printf("\n");
	}
	while (scanf("%d%d", &x, &y) == 2) 
		printf("%d\n", foo(x, y));

	system("pause");
	return 0;
}