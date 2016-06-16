#include <stdio.h>

int dp[2][215][1024], tmp[1024];

void inm(int X[], int num)
{
	int i, tr = 0;
	
	for (i = 0; i <= X[0]; i ++)
		tmp[i] = X[i];
	
	for (i = 1; i <= X[0]; i ++)
	{
		tmp[i] = tmp[i] * num + tr;
		tr = tmp[i] / 10;
		tmp[i] = tmp[i] % 10;
	}
	
	while (tr)
	{
		tmp[++ tmp[0]] = tr % 10;
		tr = tr / 10;
	}
}

void baga(int A[], int B[], int C[])
{
	int i, tr = 0;
	
	C[0] = A[0];
	if (B[0] > A[0])
		C[0] = B[0];
	
	for (i = 1; i <= C[0]; i ++)
	{
		int a = 0, b = 0;
		
		if (i <= A[0])
			a = A[i];
		if (i <= B[0])
			b = B[i];
		
		C[i] = a + b + tr;
		tr = C[i] / 10;
		C[i] = C[i] % 10;
	}
	
	if (tr)
		C[++ C[0]] = 1;
}

int main()
{
	int i, j, N, K;
	
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	dp[1][1][0] = dp[1][1][1] = 1;
	
	for (i = 2; i <= N; i ++)
		for (j = 1; j <= i; j ++)
		{			
			inm(dp[(i - 1) & 1][j], i - 1);
			baga(dp[(i - 1) & 1][j - 1], tmp, dp[i & 1][j]);
		}
	
	for (i = dp[N & 1][K][0]; i >= 1; i --)
		printf("%d", dp[N & 1][K][i]);
	return 0;
}
