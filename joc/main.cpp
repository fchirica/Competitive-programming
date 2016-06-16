#include <stdio.h>

int a[1024][1024], best[1024][1024], dp[1024][1024];

int main()
{
	int i, j, N, M;
	
	freopen("joc.in", "r", stdin);
	freopen("joc.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			scanf("%d", &a[i][j]);
		
	for (i = 0; i <= M || i <= N; i ++)
	{
		dp[0][i] = best[0][i] = (1 << 30) * (-1);
		dp[i][0] = best[i][0] = (1 << 30) * (-1);
	}
	
	int sol = (-1) * (1 << 30), idx1, idx2;
	bool valid;
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
		{
			int ret; 
			
			valid = true;
			ret = best[i - 1][j];
			if (best[i][j - 1] > ret)
				ret = best[i][j - 1];
			if (ret == (1 << 30) * (-1))
				ret = 0, valid = false;
			
			dp[i][j] = a[i][j] - ret;
			if (dp[i][j] > sol)
				sol = dp[i][j], idx1 = i, idx2 = j;
			
			best[i][j] = dp[i][j];
			if (ret > best[i][j] && valid)
				best[i][j] = ret;
		}
		
	printf("%d %d %d", sol, idx1, idx2);
	return 0;
}
