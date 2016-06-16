#include <stdio.h>
#define MOD 10007

int dp[15000];

int main()
{
	int i, j, n, k, x;
	
	freopen("desc2.in", "r", stdin);
	freopen("desc2.out", "w", stdout);
	
	scanf("%d%d%d", &n, &k, &x);
	
	int sum = 1;
	for (i = 1; i <= k; i ++)
	{
		n = n - sum;
		sum = sum + x;
	}
	
	dp[0] = 1;
	for (i = 1; i <= k; i ++)
		for (j = 0; i + j <= n; j ++)
			dp[i + j] = (dp[i + j] + dp[j]) % MOD;
	
	printf("%d", dp[n]);
	return 0;
}
