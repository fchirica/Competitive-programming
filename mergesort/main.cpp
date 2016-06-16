#include <stdio.h>
#define MOD 1000003

int sol[1000010], fact[1000010];
 
int getput(int A, int B)
{
    if (B == 0)
		return A;
	
	int ret = getput(A, B / 2);
	
	ret = 1LL * ret * ret % MOD;
	if (B % 2)
		ret = 1LL * ret * A % MOD;
	
	return ret;
}
 
int inv(int a) {
    return getput(a, MOD - 2);
}
 
int comb(int n, int k)
{
    long long ans;
	
    ans = 1LL * fact[n] * inv(fact[k]) % MOD;
    ans = ans * inv(fact[n - k]) % MOD;
	
    return ans;
}
 
int main() 
{
	int i, N;
	
	freopen("mergesort.in", "r", stdin);
	freopen("mergesort.out", "w", stdout);
	
    scanf("%d", &N);
 
    sol[1] = fact[1] = 1;
	for (i = 2; i <= N; ++i)
        fact[i] = (long long)fact[i - 1] * i % MOD;
 
    for (int i = 2; i <= N; ++i) 
	{
        int ret = i / 2;
        
		if (i & 1)
            ret ++;
		
		int kkt1 = (1LL * fact[ret] * sol[i - ret]) % MOD;
		int kkt2 = 1LL * fact[i - ret] * sol[ret];
		
		sol[i] = comb(i, ret);
		sol[i] = (1LL * sol[i] * (kkt1 + kkt2) % MOD + fact[i] - 2) % MOD;
	}
 
    printf("%d", sol[N]);
 
    return 0;
}
