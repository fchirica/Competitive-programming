#include <stdio.h>
#define MOD 1000000007

int x[112], dp[100100];

int main()
{
	int i, j, N, S, sum = 0;
	
	freopen("pokemon2.in", "r", stdin);
	freopen("pokemon2.out", "w", stdout);
	
	scanf("%d%d", &N, &S);
	for (i = 1; i <= N; i ++)
		scanf("%d", &x[i]);
	
	for (i = N - 1; i >= 1; i --)
	{
		sum += x[i];
		S = S - sum;
	}
	
	dp[0] = 1;
	for (i = 1; i <= N; i ++)
		for (j = 0; j + i <= S; j ++)
			dp[i + j] = (dp[i + j] + dp[j]) % MOD;
	
	printf("%d", dp[S]);
	return 0;
}
