#include <stdio.h>

long long dp[200][200];

int main()
{
	int i, j, N;
	long long pos;
	
	freopen("arbsort.in", "r", stdin);
	freopen("arbsort.out", "w", stdout);
	
	scanf("%d%lld", &N, &pos);
	N --; printf("0 ");
	
	for (i = 1; i <= N; i ++)
		dp[N][i] = 1;
	
	for (i = N - 1; i >= 1; i --)
	{
		dp[i][i] = dp[i + 1][i] + dp[i + 1][i + 1];
		
		for (j = i - 1; j >= 1; j --)
			dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
	}
	
	int last = 1;
	
	for (i = 1; i <= N; i ++)
		if (pos <= dp[i][last])
			printf("%d ", last);
		else
			pos = pos - dp[i][last ++], i --;
		
	return 0;
}
