#include <stdio.h>
#include <string.h>
#define NMAX 50500

int x[2][NMAX];

int Solve (int type, int dist, int N)
{
	int i, sum[NMAX], num[NMAX], now, best = 1 << 30;
	
	memset (sum, 0, sizeof (sum));
	memset (num, 0, sizeof (num));
	
	for (i = 1; i <= N; i ++)
	{
		sum[x[type][i]] += x[type][i];
		num[x[type][i]] ++;
	}
	
	for (i = 1; i <= 50100; i ++)
		sum[i] = sum[i] + sum[i - 1], num[i] = num[i] + num[i - 1];
	
	for (i = 0; i <= 50100 - dist; i ++)
	{
		now = 0;
		if (i > 0)
			now = i * num[i - 1] - sum[i - 1];
		now = now + sum[50100] - sum[i + dist];
		now = now - (i + dist) * (num[50100] - num[i + dist]);
		if (now < best)
			best = now;
	}
	
	return best;
}

int main ()
{
	int i, N, DX, DY;
	
	freopen ("tribute.in", "r", stdin);
	freopen ("tribute.out", "w", stdout);
	
	scanf ("%d%d%d", &N, &DX, &DY);
	for (i = 1; i <= N; i ++)
		scanf ("%d%d", &x[0][i], &x[1][i]);
	
	printf ("%d", Solve (0, DX, N) + Solve (1, DY, N));
	return 0;
}
