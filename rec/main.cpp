#include <stdio.h>
#define MOD 666013

int dp[15000];

int main()
{
	int i, j, N, F, S;
	
	freopen("rec.in", "r", stdin);
	freopen("rec.out", "w", stdout);
	
	scanf("%d%d%d", &S, &N, &F);
	S = S - F * N;
	
	dp[0] = 1;
	for (i = 1; i <= N; i ++)
		for (j = 0; i + j <= S; j ++)
			dp[i + j] = (dp[i + j] + dp[j]) % MOD;

	printf("%d", dp[S]);
	return 0;
}
