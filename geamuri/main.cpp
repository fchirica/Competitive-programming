#include <stdio.h>
#define NMAX 2000

int x[NMAX][NMAX], sol[55000];

void Mars2D(int x0, int y0, int x1, int y1)
{
	x[x0][y0] ++;
	x[x0][y1 + 1] --;
	x[x1 + 1][y0] --;
	x[x1 + 1][y1 + 1] ++;
}

int main()
{
	int i, j, C, N, Q, x0, y0, x1, y1;
	
	freopen("geamuri.in", "r", stdin);
	freopen("geamuri.out", "w", stdout);
	
	scanf("%d%d", &C, &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d%d%d", &y0, &x0, &y1, &x1);
		Mars2D(x0, y0, x1, y1);
	}
	
	for (i = 1; i <= C; i ++)
		for (j = 1; j <= C; j ++)
		{
			x[i][j] += x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1];
			sol[x[i][j]] ++;
		}
		
	scanf("%d", &Q);
	while (Q --)
	{
		scanf("%d", &N);
		printf("%d\n", sol[N]);
	}
	
	return 0;
}
