#include <stdio.h>

int SP[500500], now[100100];

int main()
{
	int i, N, K, A, B;
	
	freopen("divk.in", "r", stdin);
	freopen("divk.out", "w", stdout);
	
	scanf("%d%d%d%d", &N, &K, &A, &B);
	for (i = 1; i <= N; i ++)
	{
		int x;
		scanf("%d", &x);
		SP[i] = (SP[i - 1] + x) % K;
	}
	
	long long sol = 0;
	for (i = A; i <= N; i ++)
	{
		now[SP[i - A]] ++;
		sol += now[SP[i]];
		if (i >= B)
			now[SP[i - B]] --;
	}
	
	printf("%lld", sol);
	return 0;
}

	