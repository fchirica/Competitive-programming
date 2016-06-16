#include <stdio.h>

int sol[300][300], used[300];

int main()
{
	int i, j, N, now = 0;
	
	freopen("lacate.in", "r", stdin);
	freopen("lacate.out", "w", stdout);
	
	scanf("%d", &N);
	
	printf("%d %d\n", N * (N - 1) / 2, N - 1);
	for (i = 1; i < N; i ++)
		for (j = i + 1; j <= N; j ++)
		{
			++ now;
			sol[i][++ used[i]] = now;
			sol[j][++ used[j]] = now;
		}
	
	for (i = 1; i <= N; i ++, printf("\n"))
		for (j = 1; j < N; j ++)
			printf("%d ", sol[i][j]);
		
	return 0;
}
