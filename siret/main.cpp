#include <stdio.h>

int G[315][315], G2[315][315], Q[315], pred[315], perm[315], dp[315], next[315];

int main()
{
	int i, j, N, M;
	
	freopen("siret.in", "r", stdin);
	freopen("siret.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y)
		{	int aux = x; x = y; y = aux;	}
		G[x][y] = 1;
	}
	
	for (i = 1; i <= N; i ++)
		for (j = i + 1; j <= N; j ++)
			if (G[i][j])
			{
				G2[j][i] = 1;
				pred[i] ++;
			}
			else
			{
				G2[i][j] = 1;
				pred[j] ++;
			}
			
	int p = 1, u = 0;
	for (i = 1; i <= N; i ++)
		if (pred[i] == 0)
			Q[++ u] = i;

	while (p <= u)
	{
		for (i = 1; i <= N; i ++)
			if (G2[Q[p]][i])
			{
				pred[i] --;
				if (pred[i] == 0)
					Q[++ u] = i;
			}
		p ++;
	}
	
	for (i = 1; i <= N; i ++)
		perm[Q[i]] = i;
	
	int sol = 0, idx;

	for (i = N; i >= 1; i --)
	{
		for (j = i + 1; j <= N; j ++)
			if (dp[j] > dp[i] && perm[i] > perm[j])
			{
				dp[i] = dp[j];
				next[i] = j;
			}
		dp[i] ++;
		if (dp[i] > sol)
		{
			sol = dp[i];
			idx = i;
		}
	}
	
	printf("%d\n", sol);
	while (idx)
	{
		printf("%d ", idx);
		idx = next[idx];
	}
	
	return 0;
}
