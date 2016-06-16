#include <stdio.h>
#define MOD 9973

int dp[1024][1024];

int mod(int X)
{
	return X % MOD;
}

int sol[1024];

int main()
{
	int i, j, N, K;
	
	freopen("stiva2.in", "r", stdin);
	freopen("stiva2.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	dp[1][1] = 2;
	for (i = 2; i <= K + 1; i ++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = dp[i - 1][2];
		for (j = 2; j <= K + 1; j ++)
			dp[i][j] = mod(dp[i - 1][j - 1] + dp[i - 1][j + 1]);
	}
	
	sol[0] = 1;
	for (i = 1; i <= N; i ++)
		for (j = i; i - j <= K && j >= 0; j --)
			sol[i] = mod(sol[i] + mod(sol[j - 1] * dp[i - j + 1][0]));
		
	printf("%d", sol[N]);
	return 0;
}
