#include <stdio.h>
#include <string.h>

int supply[20], x[20][20];
int dp[10][1000000], sol[20][20];

void recon(int i, int j)
{
	if (j == 0)
		return ;
	sol[1][i] = dp[i][j];
	
	recon(i - 1, j - dp[i][j] * supply[i]);
}

int main()
{
	int N, S, i, j, k;
	
	freopen("triunghi.in", "r", stdin);
	freopen("triunghi.out", "w", stdout);
	
	scanf("%d%d", &N, &S);
	for (i = 1; i <= N; i ++)
	{
		memset(x, 0, sizeof(x));
		x[1][i] = 1; supply[i] = 1;
		
		for (j = 2; j <= N; j ++)
			for (k = 1; k <= N - j + 1; k ++)
			{
				x[j][k] = x[j - 1][k] + x[j - 1][k + 1];
				supply[i] += x[j][k];
			}
	}
	
	for (i = 1; i <= N; i ++)
		S = S - supply[i];
	int n = (N + 1) / 2;

	for (i = 1; i * supply[1] <= S; i ++)
		dp[1][i * supply[1]] = i;
	for (i = 2; i <= n; i ++)
		for (j = 0; j <= S; j ++)
		{
			if (j + supply[i] > S)
				break;
			if (dp[i][j] || dp[i - 1][j] || j == 0)
				dp[i][j + supply[i]] = dp[i][j] + 1;
		}
		
	if (dp[n][S] == 0 && S)
	{
		printf("imposibil");
		return 0;
	}
		
	recon(n, S);
	
	for (i = 1; i <= N; i ++)
		sol[1][i] ++;
	for (i = 2; i <= N; i ++)
		for (j = 1; j <= N - i + 1; j ++)
			sol[i][j] = sol[i - 1][j] + sol[i - 1][j + 1];
	
	for (i = N; i >= 1; i --, printf("\n"))
		for (j = 1; j <= N - i + 1; j ++)
			printf("%d ", sol[i][j]);
		
	return 0;
}
