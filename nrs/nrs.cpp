#include <stdio.h>
#define LMAX 1000100
#define DIM 8192
#define VMAX 1000100

int x[LMAX], next[LMAX], st[LMAX]; 
long long cnt[VMAX], S[VMAX], grad[LMAX];

int main ()
{
	int i, N, M, lun, maxVal = -1, x0, y0;
	
	freopen ("nrsubsecv.in", "r", stdin);
	freopen ("nrsubsecv.out", "w", stdout);
	
	scanf ("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		scanf ("%d", &x[i]);
		if (x[i] > maxVal)
			maxVal = x[i];
	}
	
	int p, u; p = 1; u = 0;
	
	for (i = 1; i <= N; i ++)
	{
		while (p <= u && x[i] < x[st[u]])
		{
			next[st[u]] = i;
			u --;
		}
		st[++ u] = i;
	}
	for (i = 1; i <= N; i ++)
		if (next[i] == 0)
			next[i] = N + 1;
		
	for (i = 1; i <= N; i ++)
	{
		lun = next[i] - i;
		cnt[x[i]] += (long long)(grad[i] + 1) * lun;
		grad[next[i]] += grad[i] + 1;
	}
	
	for (i = 0; i <= maxVal + 10; i ++)
	{
		if (i > 0)
			S[i] = S[i - 1] + cnt[i];
		else
			S[i] = cnt[i];
	}
	
	for (i = 1; i <= M; i ++)
	{
		scanf ("%d%d", &x0, &y0);
		if (x0 > maxVal)
			x0 = maxVal + 10;
		if (y0 > maxVal)
			y0 = maxVal + 10;
		if (x0)
			x0 --;
		printf ("%lld\n", S[y0] - S[x0]);
	}
	
	return 0;
}
