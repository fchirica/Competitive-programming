#include <stdio.h>

int main()
{
	int i, N, col;
	
	freopen("regine.in", "r", stdin);
	freopen("regine.out", "w", stdout);
	
	scanf("%d", &N);
	
	int ans = (2 * N + 1) / 3;
	printf("%d\n", ans);
	
	for (i = N - ans + 1, col = 1; i <= N; i = i + 2, col ++)
		printf("%d %d\n", i, col);
	for (i = N - ans + 2, col = N - ans + 2; i <= N; i = i + 2, col ++)
		printf("%d %d\n", i, col);
	
	return 0;
}
