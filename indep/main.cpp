#include <stdio.h>
#define BASE 1000000000

int dp[1024][150];
int x[512], unu[500];

void baga(int A[], int B[])
{
	if (B[0] > A[0])
		A[0] = B[0];
	
	int i, tr = 0;
	
	for (i = 1; i <= A[0]; i ++)
	{
		tr = tr + A[i] + B[i];
		A[i] = tr % BASE;
		tr = tr / BASE;
	}
	
	while (tr)
	{
		A[++ A[0]] = tr % BASE;
		tr = tr / BASE;
	}
}

inline int gcd(int a, int b)
{
	int r;
	
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int main()
{
	int N, i, j, vmax = -1;
	
	freopen("indep.in", "r", stdin);
	freopen("indep.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		if (x[i] > vmax)
			vmax = x[i];
	}
	
	unu[0] = unu[1] = 1;
	for (i = 1; i <= N; i ++)
	{
		for (j = 1; j <= vmax; j ++)
			baga(dp[gcd(x[i], j)], dp[j]);
		baga(dp[x[i]], unu);
	}

	printf("%d", dp[1][dp[1][0]]);
	for (i = dp[1][0] - 1; i >= 1; i --)
		printf("%09d", dp[1][i]);
	return 0;
}
