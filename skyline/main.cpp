#include <stdio.h>
#define NMAX 40100

int H[NMAX], L[NMAX], SP[NMAX], st[NMAX], left[NMAX], right[NMAX];

int main()
{
	int i, N;
	
	freopen("skyline.in", "r", stdin);
	freopen("skyline.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d", &H[i], &L[i]);
		SP[i] = SP[i - 1] + L[i];
	}
	
	int u = 0;
	for (i = 1; i <= N; i ++)
	{
		while (u > 0 && H[st[u]] >= H[i])
			u --;
		if (u == 0)
			left[i] = 0;
		else
			left[i] = st[u];
		st[++ u] = i;
	}
	
	u = 0;
	for (i = N; i >= 1; i --)
	{
		while (u > 0 && H[st[u]] >= H[i])
			u --;
		if (u == 0)
			right[i] = N + 1;
		else
			right[i] = st[u];
		st[++ u] = i;
	}
	
	long long sol = 0;
	for (i = 1; i <= N; i ++)
	{
		long long now = SP[right[i] - 1] - SP[left[i]];
		now = now * H[i];
		if (now > sol)
			sol = now;
	}
	
	printf("%lld", sol);
	return 0;
}
