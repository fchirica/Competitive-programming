#include <stdio.h>

int A[200100], B[200100];

long long cnt(long long maxPrice, int N)
{
	int i;
	long long ans = 0;
	
	for (i = 1; i <= N; i ++)
	{
		if (maxPrice - A[i] < 0)
			continue;
		ans = ans + (maxPrice - A[i]) / B[i] + 1;
	}
	
	return ans;
}

long long calc(long long maxPrice, int N, int K)
{
	int i;
	long long ans = 0, products;
	
	for (i = 1; i <= N; i ++)
	{
		if (maxPrice - A[i] < 0)
			continue;
		products = (maxPrice - A[i]) / B[i] + 1;
		ans = ans + products * A[i] + products * (products - 1) / 2 * B[i];
	}
	
	ans = ans - (cnt(maxPrice, N) - K) * maxPrice;
	return ans;
}

int main()
{
	int i, N, K;
	
	freopen("tarabe.in", "r", stdin);
	freopen("tarabe.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; i ++)
		scanf("%d%d", &B[i], &A[i]);
	
	long long st = 1, dr = 1LL << 35, med, best;
	
	while (st <= dr)
	{
		med = (st + dr) / 2;
		
		if (cnt(med, N) >= K)
			best = med, dr = med - 1;
		else
			st = med + 1;
	}
		
	printf("%lld", calc(best, N, K));
	return 0;
}
