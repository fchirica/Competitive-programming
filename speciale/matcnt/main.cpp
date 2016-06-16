#include <stdio.h>
#define MOD 200003

int sol[100100];

int main()
{
	int i, N;
	
	freopen("matcnt.in", "r", stdin);
	freopen("matcnt.out", "w", stdout);
	
	scanf("%d", &N);
	
	sol[3] = 1;
	for (i = 4; i <= N; i ++)
	{
		sol[i] = (1LL * (i - 1) * (i - 2) / 2) % MOD;
		sol[i] = 1LL * sol[i] * sol[i - 3] % MOD;
		sol[i] = (sol[i] + 1LL * sol[i - 1] * (i - 1) % MOD) % MOD;
	}
	
	int fact = 1;
	
	for (i = 2; i <= N; i ++)
		fact = 1LL * fact * i % MOD;
	sol[N] = 1LL * sol[N] * fact % MOD;
	
	printf("%d", sol[N]);
	return 0;
}
