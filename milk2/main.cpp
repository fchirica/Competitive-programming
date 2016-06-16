/*
ID: nmalina1
PROG: milk2
LANG: C++
*/

#include <stdio.h>

int f[1000100];

int main()
{
	int i, x, y, N, ymax = 0, xmin = 1000000000;
	
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d", &x, &y);
		f[x] ++;
		f[y] --;
		if (x < xmin)
			xmin = x;
		if (y > ymax)
			ymax = y;
	}
	
	for (i = 1; i <= ymax; i ++)
		f[i] = f[i] + f[i - 1];
	
	int solmax = 0, now = 0;
	for (i = xmin; i <= ymax; i ++)
		if (f[i])
			now ++;
		else
		{
			if (solmax < now)
				solmax = now;
			now = 0;
		}
	printf("%d ", solmax);
	
	solmax = 0, now = 0;
	for (i = xmin; i <= ymax; i ++)
		if (f[i] == 0)
			now ++;
		else
		{
			if (solmax < now)
				solmax = now;
			now = 0;
		}
	printf("%d\n", solmax);
	
	return 0;
}
