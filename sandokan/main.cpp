#include <stdio.h>
#define MOD 2000003

int fact(int N)
{
	int i, sol = 1;
	
	for (i = 2; i <= N; i ++)
		sol = (long long)sol * i % MOD;
	return sol;
}

int pow(int A, int B)
{
	if (B == 0)
		return 1;
	
	long long ret = pow(A, B / 2);
	
	ret = ret * ret % MOD;
	if (B & 1)
		ret = ret * A % MOD;
	return ret;
}

int main()
{
	int N, K;
	
	freopen("sandokan.in", "r", stdin);
	freopen("sandokan.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	
	int p = N % (K - 1);
    if (!p)
        p = K - 1;
	K = p;
    -- N; -- K;
	
	long long res;
	
	res = fact(N);
	res = res * pow(fact(K), MOD - 2) % MOD;
	res = res * pow(fact(N - K), MOD - 2) % MOD;
	
	printf("%lld", res);
	return 0;
}
