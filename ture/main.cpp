#include <stdio.h>

int blocked[300][300], numTure;
long long dp[2][70000];

inline int cnt(int X)
{
	int num = 0;
	
	while (X)
	{
		num ++;
		X = X & (X - 1);
	}
	
	return num;
}

void solve1(int N, int M)
{
	int i, conf, j;
	
	dp[0][0] = 1;
	
	for (j = 1; j <= M; j ++)
	{
		for (conf = 0; conf < (1 << N); conf ++)
			dp[j & 1][conf] = dp[(j - 1) & 1][conf];
		for (i = 1; i <= N; i ++)
			if (!blocked[i][j])
			{
				for (conf = 0; conf < (1 << N); conf ++)
					if (((1 << (i - 1)) & conf) == 0)
						dp[j & 1][conf | (1 << (i - 1))] += dp[(j - 1) & 1][conf];
			}
	}
	
	long long ans = 0;
	
	for (i = 0; i < (1 << N); i ++)
		if (cnt(i) == numTure)
			ans += dp[M & 1][i];
	printf("%lld", ans);
}

void solve2(int N, int M)
{
	int i, j, conf;
	
	dp[0][0] = 1;
	
	for (i = 1; i <= N; i ++)
	{
		for (j = 0; j < (1 << M); j ++)
			dp[i & 1][j] = dp[(i - 1) & 1][j];
		for (j = 1; j <= M; j ++)
			if (!blocked[i][j])
				for (conf = 0; conf < (1 << M); conf ++)
					if (((1 << (j - 1)) & conf) == 0)
						dp[i & 1][conf | (1 << (j - 1))] += dp[(i - 1) & 1][conf];
	}
	
	long long ans = 0;
	
	for (i = 0; i < (1 << M); i ++)
		if (cnt(i) == numTure)
			ans += dp[N & 1][i];
	printf("%lld", ans);
}

int main()
{
	int N, M, K, x, y, i;
	
	freopen("ture.in", "r", stdin);
	freopen("ture.out", "w", stdout);
	
	scanf("%d%d%d%d", &N, &M, &numTure, &K);
	for (i = 1; i <= K; i ++)
	{
		scanf("%d%d", &x, &y);
		blocked[x][y] = 1;
	}
	
	if (N < M)
		solve1(N, M);
	else
		solve2(N, M);
	
	return 0;
}
