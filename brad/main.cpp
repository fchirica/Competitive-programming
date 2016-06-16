#include <stdio.h>

int x[2][10000];

int main()
{
	int i, j, N, sol = 0;
	
	freopen("brad.in", "r", stdin);
	freopen("brad.out", "w", stdout);
	
	scanf("%d", &N);
	x[1][1] = 1;
	
	for (i = 2; i <= N; i ++)
	{
		sol = 0;
		for (j = 1; j <= N; j ++)
			if (x[(i - 1) & 1][j - 1] + x[(i - 1) & 1][j + 1] == 1)
				x[i & 1][j] = 1;
			else
				x[i & 1][j] = 0;
		for (j = 1; j <= N; j ++)
			if (x[i & 1][j])
				sol ++;
		printf("%d, ", sol);
	}
	
	return 0;
}
