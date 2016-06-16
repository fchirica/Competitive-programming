#include <stdio.h>

int x[100100];

int main()
{
	int i, N, K;
	long long sum = 0;
	
	freopen("grupuri.in", "r", stdin);
	freopen("grupuri.out", "w", stdout);
	
	scanf("%d%d", &K, &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		sum += x[i];
	}
	
	for (i = N; i >= 1; i --)
	{
		if (x[i] <= sum / K)
		{
			printf("%d", sum / K);
			return 0;
		}
		sum = sum - x[i];
		K --;
	}
	
	return 0;
}
