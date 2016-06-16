//Am piramide. Faraonu, faraonu, cine este faraonu? 

#include <stdio.h>
#define MOD 10000

int comb[20][20], dp[600000];

int main()
{
	int i, j, S, N;
	
	freopen("piramida.in", "r", stdin);
	freopen("piramida.out", "w", stdout);
	
	scanf("%d", &S);
	for (N = 0; (1 << N) <= S; N ++);
	
	comb[1][1] = 1;
	for (i = 2; i <= N; i ++)
		for (j = 1; j <= i; j ++)
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
	
	S = S - (1 << (N - 1));
	dp[0] = 1;
	
	for (i = 1; i <= N; i ++)
		for (j = 0; j + comb[N][i] <= S; j ++)
			if (dp[j])
			{
				dp[j + comb[N][i]] += dp[j];
				dp[j + comb[N][i]] %= MOD;
			}
			
	printf("%d", dp[S]);
	return 0;
}
