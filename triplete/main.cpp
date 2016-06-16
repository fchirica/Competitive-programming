#include <stdio.h>
#define BASE 60

int x0[70000], y0[70000];
long long mat[5000][5000 / BASE];

int cnt(long long x)
{
	int ans = 0;
	
	while (x)
	{
		ans ++;
		x = x & (x - 1);
	}
	
	return ans;
}

int main()
{
	int i, j, N, M;
	
	freopen("triplete.in", "r", stdin);
	freopen("triplete.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		scanf("%d%d", &x0[i], &y0[i]);
		mat[x0[i]][y0[i] / BASE] |= 1LL << (y0[i] % BASE);
		mat[y0[i]][x0[i] / BASE] |= 1LL << (x0[i] % BASE);
	}
	
	int sol = 0;
	for (i = 1; i <= M; i ++)
		for (j = 0; j <= N / BASE; j ++)
			sol += cnt(mat[x0[i]][j] & mat[y0[i]][j]);
	
	printf("%d", sol / 3);
	return 0;
}
