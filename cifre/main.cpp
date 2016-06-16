#include <stdio.h>
#include <string.h>

int dp[15][15][2][2], dig[15], N;

int solve(int X, int C, int K)
{
	int i, j, k, l, c;
	
	N = 0;
	do
	{
		dig[++ N] = X % 10;
		X = X / 10;
	}
	while (X);
	
	int st = 1, dr = N, aux;
	
	while (st <= dr)
	{
		aux = dig[st];
		dig[st] = dig[dr];
		dig[dr] = aux;
		st ++;
		dr --;
	}
	
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;
	
	for (i = 0; i < N; i ++)
		for (j = 0; j <= K; j ++)
			for (k = 0; k <= 1; k ++)
				for (l = 0; l <= 1; l ++)
					for (c = 0; c <= 9; c ++)
					{
						int cnt, add, zero;
						
						cnt = j;
						if (c == C)
						{
							cnt ++;
							if (c == 0 && l == 0)
								cnt --;
						}
						if (cnt > K)
							cnt = K;
						
						if (k == 0 && c > dig[i + 1])
							continue;
						add = k;
						if (c < dig[i + 1])
							add = 1;
						
						zero = l;
						if (c)
							zero = 1;
						
						dp[i + 1][cnt][add][zero] += dp[i][j][k][l];
					}
	
	return dp[N][K][0][1] + dp[N][K][1][1];
}

int main()
{
	int A, B, C, K;
	
	freopen("cifre.in", "r", stdin);
	freopen("cifre.out", "w", stdout);
	
	scanf("%d%d%d%d", &A, &B, &C, &K);
	
	double prob = solve(B, C, K) - solve(A - 1, C, K);
	prob = (double)prob / (B - A + 1);
	
	printf("%lf", prob);
	return 0;
}
