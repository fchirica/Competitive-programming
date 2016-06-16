#include <stdio.h>

int x[50100];

int main()
{
	int N, K, i, sum = 0, sum2 = 0, min = 1 << 30, idx;
	int sol = (1 << 30) * (-1), first, last;
	
	freopen("secv2.in", "r", stdin);
	freopen("secv2.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		
		sum += x[i];
		if (i >= K)
		{
			sum2 = sum2 + x[i - K];
			if (sum2 < min)
				min = sum2, idx = i - K + 1;
			if (sum - min > sol)
				sol = sum - min, first = idx, last = i;
		}
	}
	
	printf("%d %d %d", first, last, sol);
	return 0;
}
