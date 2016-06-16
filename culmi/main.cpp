#include <stdio.h>
#define NMAX 112
#define CMAX 10000

int comb[3][NMAX][CMAX];
int sol[CMAX];

inline int max(int x, int y)
{
	return x > y ? x : y;
}

void getComb(int N, int K)
{
	int i, j, k, tr;
	
	for (i = 0; i <= N; i ++)
	{
		comb[i & 1][0][0] = comb[i & 1][0][1] = 1;
		
		for (j = 1; j <= K && j <= i; j ++)
		{
			comb[i & 1][j][0] = max(comb[(i - 1) & 1][j][0], comb[(i - 1) & 1][j - 1][0]);
			for (k = 1, tr = 0; k <= comb[i & 1][j][0]; k ++)
			{
				comb[i & 1][j][k] = comb[(i - 1) & 1][j][k] + comb[(i - 1) & 1][j - 1][k] + tr;
				tr = comb[i & 1][j][k] / 10;
				comb[i & 1][j][k] = comb[i & 1][j][k] % 10;
			}
			if (tr)
				comb[i & 1][j][++ comb[i & 1][j][0]] = 1;
		}
	}
}

void makeProd(int N, int K)
{
	int i, j, tr = 0;
	
	sol[0] = comb[N & 1][K][0] + comb[N & 1][K - 1][0] - 1;
	
	for (i = 1; i <= comb[N & 1][K][0]; i ++)
		for (j = 1; j <= comb[N & 1][K - 1][0]; j ++)
			sol[i + j - 1] += comb[N & 1][K][i] * comb[N & 1][K - 1][j];
		
	for (i = 1; i <= sol[0]; i ++)
	{
		sol[i] = sol[i] + tr;
		tr = sol[i] / 10;
		sol[i] = sol[i] % 10;
	}
	
	while (tr)
	{
		sol[++ sol[0]] = tr % 10;
		tr = tr / 10;
	}
	
	int st = 1, dr = sol[0], aux;
	
	while (st <= dr)
	{
		aux = sol[st];
		sol[st] = sol[dr];
		sol[dr] = aux;
		st ++;
		dr --;
	}
}

void divide(int N)
{
	int i, r = 0;
	
	for (i = 1; ; i ++)
	{
		if (r * 10 + sol[i] >= N)
			break;
		r = r * 10 + sol[i];
	}
	
	for (; i <= sol[0]; i ++)
	{
		r = r * 10 + sol[i];
		printf("%d", r / N);
		r = r % N;
	}
}

int main()
{
	int N, K;
	
	freopen("culmi1.in", "r", stdin);
	freopen("culmi1.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	getComb(N, K);
	
	makeProd(N, K);
	divide(N);
	
	return 0;
}
