#include <stdio.h>

char line[112];
int x[112][112], dp[112][112];

int main()
{
	int test, i, j, N, T;
	
	scanf("%d\n", &T);
	for (test = 1; test <= T; test ++)
	{
		scanf("%d\n", &N);
		for (i = 1; i <= N; i ++)
		{
			gets(line + 1);
			for (j = 1; j <= N; j ++)
			{
				if (line[j] == '.')
					x[i][j] = 0;
				if (line[j] == 'W')
					x[i][j] = 1;
				if (line[j] == 'B')
					x[i][j] = -1;
				dp[i][j] = 0;
			}
		}
		
		for (i = N; i >= 1; i --)
			for (j = N; j >= 1; j --)
			{
				if (x[i][j] == 1)
					dp[i][j] = 1;
				if (x[i][j] == -1)
					dp[i][j] = 0;
				if (x[i][j] == 0)
				{
					if (i == N)
						continue;
					if (x[i + 1][j - 1] != -1 && j > 1)
						dp[i][j] += dp[i + 1][j - 1];
					if (j > 2 && i + 2 <= N && x[i + 1][j - 1] == -1 && x[i + 2][j - 2] != -1)
						dp[i][j] += dp[i + 2][j - 2];
					if (x[i + 1][j + 1] != -1 && j < N)
						dp[i][j] += dp[i + 1][j + 1];
					if (j + 2 <= N && i + 2 <= N && x[i + 1][j + 1] == -1 && x[i + 2][j + 2] != -1)
						dp[i][j] += dp[i + 2][j + 2];
					dp[i][j] = dp[i][j] % 1000007;
				}
			}
				
		int tot = 0;
		for (i = 1; i <= N; i ++)
		{
			tot += dp[1][i];
			tot = tot % 1000007;
		}
		printf("Case %d: %d\n", test, tot);
	}
	
	return 0;
}
