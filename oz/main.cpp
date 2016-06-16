#include <stdio.h>

long long sol[10100];
int x[100100], y[100100], d[100100];

inline long long gcd(long long X, long long Y)
{
	long long r;
	
	while (Y)
	{
		r = X % Y;
		X = Y;
		Y = r;
	}
	
	return X;
}

inline long long lcm(long long X, long long Y)
{
	return X * Y / gcd(X, Y);
}

int main()
{
	int i, N, M;
	
	freopen("oz.in", "r", stdin);
	freopen("oz.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
		scanf("%d%d%d", &x[i], &y[i], &d[i]);
	for (i = 1; i <= N; i ++)
		sol[i] = 1;
	
	for (i = 1; i <= M; i ++)
	{
		int X = x[i], Y = y[i];
		
		sol[X] = lcm(sol[X], d[i]);
		sol[Y] = lcm(sol[Y], d[i]);
	}
	
	bool isSolution = true;
	
	for (i = 1; i <= M; i ++)
		if (gcd(sol[x[i]], sol[y[i]]) != d[i])
			isSolution = false;
	
	if (isSolution)
		for (i = 1; i <= N; i ++)
			printf("%lld ", sol[i]);
	else
		printf("-1");
	
	return 0;
}
