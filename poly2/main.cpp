#include <stdio.h>
#define MOD 30103

int sol[512];

int main()
{
	int i, j, N;
	
	freopen("poly2.in", "r", stdin);
	freopen("poly2.out", "w", stdout);
	
	scanf("%d", &N);
	
	sol[0] = 1;
	for (i = 1; i <= N; i ++)
		for (j = 0; j < i; j ++)
			sol[i] = (sol[i] + sol[j] * sol[i - j - 1]) % MOD;
	
	printf("%d", sol[N]);
	return 0;
}
