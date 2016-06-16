#include <stdio.h>

int f[1000000];

void desc(int x)
{
	int d;
	
	for (d = 2; d * d <= x; d ++)
	{
		bool is = false;
		
		while (x % d == 0)
			is = true, x = x / d;
		
		if (is)
			f[d] ++;
	}
	
	if (x > 1)
		f[x] ++;
}

int main()
{
	int i, N, x;
	
	freopen("pcost.in", "r", stdin);
	freopen("pcost.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x);
		desc(x);
	}
	
	long long sol = 0;
	
	for (i = 2; i <= 1000000; i ++)
		if (f[i] > 1)
			sol = sol + 1LL * f[i] * (f[i] - 1) / 2 * i * i;
		
	printf("%lld", sol);
	return 0;
}
