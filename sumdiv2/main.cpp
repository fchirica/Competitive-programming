#include <stdio.h>

int stieve[1000100];
long long SP[1000100];

void makeStieve()
{
	int i, j;
	
	for (i = 1; i <= 1000000; i ++)
		for (j = i; j <= 1000000; j += i)
			stieve[j] += i;
		
	for (i = 1; i <= 1000000; i ++)
		SP[i] = SP[i - 1] + stieve[i];
}

int main()
{
	int i, x, y, N;
	
	freopen("sumdiv2.in", "r", stdin);
	freopen("sumdiv2.out", "w", stdout);
	
	makeStieve();
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d", &x, &y);
		printf("%lld\n", SP[y] - SP[x - 1]);
	}
	
	return 0;
}
