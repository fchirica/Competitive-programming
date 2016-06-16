#include <stdio.h>

long long dp[310][160];

int main()
{
	int N, D, i, j, k;
	
	freopen("problem3.in", "r", stdin);
	freopen("problem3.out", "w", stdout);
	
	for (i = 1; i <= 150; i ++)
		dp[0][i] = 1;

	for (i = 1; i <= 150; i ++)
	{
		dp[i][1] = 1;
		for (j = 2; j <= i; j ++)
		{
			dp[i][j] = dp[i][j - 1];
			for (k = 0; k < i; k ++)
				dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j];
		}
	}
	
	while (scanf("%d%d", &N, &D) != EOF)
	{
		if (N % 2)
			printf("0\n");
		else
			printf("%d\n", dp[N / 2][D] - dp[N / 2][D - 1]);
	}
	
	return 0;
}
