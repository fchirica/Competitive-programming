#include <stdio.h>
#define MOD 543217 

int perm[500500];

inline int ab(int X)
{
	if (X > 0)
		return X;
	return -X;
}

int main()
{
	int i, N;
	
	freopen("urat.in", "r", stdin);
	freopen("urat.out", "w", stdout);
	
	scanf("%d", &N);
	
	perm[1] = N / 2; perm[N] = N / 2 + 1;
	if (!perm[2])
		perm[2] = perm[1] + 2; 
	if (!perm[3])
		perm[3] = 1;
	for (i = 4; i < N; i ++)
		perm[i] = perm[i - 2] + 1;
	
	int sol = 1, fact = 1, lim = N / 2;
	long long ugly = 0;
	
	for (i = 2; i <= N; i ++)
		ugly += ab(perm[i] - perm[i - 1]);
	
	for (i = 2; i < lim; i ++)
		fact = 1LL * fact * i % MOD;
	if (N % 2 == 0)
		sol = 2LL * fact * fact % MOD;
	else
		sol = 4LL * fact * ((1LL * fact * lim) % MOD) % MOD;
	
	printf("%lld\n%d\n", ugly, sol);
	for (i = 1; i <= N; i ++)
		printf("%d ", perm[i]);
	
	return 0;
}
