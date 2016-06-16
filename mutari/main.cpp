#include <stdio.h>

int st[2000000];
int x[100100];

int main()
{
	int i, j, N, moves = 0;
	
	freopen("mutari.in", "r", stdin);
	freopen("mutari.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		if (i != 1)
		{
			if (x[i] % x[1])
			{
				printf("-1");
				return 0;
			}
			moves += x[i] / x[1];
		}
	}
	
	printf("%d\n", moves);
	for (i = 2; i <= N; i ++)
		x[i] -= x[1];
	for (i = 2; i <= N; i ++)
		while (x[i])
		{
			printf("%d\n", i - 1);
			x[i] = x[i] - x[1];
		}
	for (i = N - 1; i >= 1; i --)
		printf("%d\n", i);
	
	return 0;
}
