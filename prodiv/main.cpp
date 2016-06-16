#include <stdio.h>

long long A = 1, B = 1, sol = 1;

long long pow (long long A, long long B)
{
	long long i, ans = 1;
	
	for (i = 1; i <= B; i ++)
		ans = ans * A;
	
	return ans;
}

void compute (long long fact, long long put)
{
	A *= pow (fact, put / 2);
	B *= pow (fact, put / 2);
	if (put % 2)
	{
		sol = sol * 2;
		A = A * fact;
	}
}

void solve (long long N)
{
	long long d = 2, put;
	
	while (d * d <= N && N > 1)
	{
		put = 0;
		while (N % d == 0)
		{
			put ++;
			N = N / d;
		}
		if (put)
			compute (d, put);
		d ++;
	}
	
	if (N > 1)
		compute (N, 1);
}

int main ()
{
	long long N;
	
	freopen ("prodiv.in", "r", stdin);
	freopen ("prodiv.out", "w", stdout);
	
	scanf ("%lld", &N);
	
	solve (N);
	
	printf ("%lld %lld\n%lld", A, B, sol);
	return 0;
}
