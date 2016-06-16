#include <stdio.h>
#define MOD 666013

int dp[1024][1024];

int fastpow(int A, int B)
{
	if (B == 0)
		return 1;
	
	int ret = fastpow(A, B / 2);
	
	ret = 1LL * ret * ret % MOD;
	if (B & 1)
		ret = 1LL * ret * A % MOD;
	return ret;
}

int main()
{
	int i, j, N, M;
	
	freopen("retea3.in", "r", stdin);
	freopen("retea3.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	
	dp[0][1] = 1;
	for (i = 1; i <= M; i ++)
		dp[i][1] = dp[1][i] = dp[i - 1][1] * 2 % MOD;
	
	for (i = 2; i <= M; i ++)
        for (j = 1; j <= M; j ++)
		{
			dp[i][j] = 2 * (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD;
			while (dp[i][j] < 0)
				dp[i][j] += MOD;
		}

	
	printf("%d", fastpow(dp[M][M], N - 1));
    return 0;
}
