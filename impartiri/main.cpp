#include <stdio.h>
#include <string.h>
#define MOD 2113

int OX[3100], dp[3100], OY[3100], SP[3100];

int main()
{
	int i, j, N, M, K;
	
	freopen("impartiri.in", "r", stdin);
	freopen("impartiri.out", "w", stdout);
	
	scanf("%d%d%d", &N, &M, &K);
	
	int lim = N;
	if (M > lim)
		lim = M;
	
	for (j = 1; j <= lim; j ++)
	{
		memset(dp, 0, sizeof(dp));
		memset(SP, 0, sizeof(SP));
		
		dp[0] = SP[0] = 1;
		for (i = 1; i <= lim; i ++)
		{
			dp[i] = SP[i - 1];
			if (i - j - 1 >= 0)
			{
				dp[i] = dp[i] - SP[i - j - 1];
				while (dp[i] < 0)
					dp[i] += MOD;
			}
			SP[i] = (SP[i - 1] + dp[i]) % MOD;
			if (i == N)
				OX[j] = dp[i];
			if (i == M)
				OY[j] = dp[i];
		}
	}
	
	int sol = 0;
	for (i = 1; i <= N; i ++)
	{
		int distx = OX[i] - OX[i - 1];
		while (distx < 0)
			distx += MOD;
		int disty = K / i;
		if (disty > M)
			disty = M;
		sol = sol + distx * OY[disty];
		sol = sol % MOD;
	}
	
	printf("%d", sol);
	return 0;
}
