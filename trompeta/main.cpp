#include <stdio.h>
#define NMAX 1000100

char x[NMAX], st[NMAX];

int main()
{
	int i, N, M, u = 0, needed;

	freopen("trompeta.in", "r", stdin);
	freopen("trompeta.out", "w", stdout);

	scanf("%d%d\n", &N, &needed);
	gets(x + 1);

    needed = N - needed;
	for (i = 1; i <= N; i ++)
	{
		while (u > 0 && needed > 0 && st[u] < x[i])
			u --, needed --;
		st[++ u] = x[i];
	}

	if (needed)
		u = u - needed;

	st[u + 1] = 0;
	printf("%s", st + 1);

	return 0;
}

