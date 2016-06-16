#include <stdio.h>

int H[69], dir[] = {-1, 0, 1};
long long dp[2][55][105][55];

int main()
{
	int i, j, k, good, d, N, D, K;
	
	freopen("munte.in", "r", stdin);
	freopen("munte.out", "w", stdout);
	
	scanf("%d%d%d", &N, &D, &K);
	for (i = 1; i <= K; i ++)
		scanf("%d", &H[i]);
	
	dp[0][0][0][0] = 1;
	for (j = 0; j < D; j ++)
		for (good = 0; good <= 1; good ++)
			for (i = 0; i <= N; i ++)
				for (k = 0; k <= K; k ++)
					for (d = 0; d < 3; d ++)
					{
						int h = i + dir[d], goals = k, ngood = good;
						
						if (h > N || h < 0 || (h == 0 && j != D - 1))
							continue;
						if (goals < K && h == H[goals + 1])
							goals ++;
						if (ngood == 0 && h == N)
							ngood = 1;
						
						dp[ngood][h][j + 1][goals] += dp[good][i][j][k];
					}
	
	printf("%lld", dp[1][0][D][K]);
	return 0;
}
