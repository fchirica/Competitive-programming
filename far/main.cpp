#include <stdio.h>

int lagrange(int P, int N)
{
	long long num = P;
	int tot = 0;
	
	while (num <= N)
	{
		tot += N / num;
		num = num * P;
	}
	
	return tot;
}

int solve(int A, int B, int M)
{
	int d, pw1, pw2, pwmod;
	
	for (d = 2; 1LL * d * d <= M; d ++)
		if (M % d == 0)
		{
			pwmod = 0;
			while (M % d == 0)
			{
				++ pwmod;
				M = M / d;
			}
			
			pw1 = lagrange(d, A);
			pw2 = lagrange(d, B) + lagrange(d, A - B);
			if (pw1 < pw2 || (pw1 - pw2) < pwmod)
				return 0;
		}
		
	if (M > 1)
	{
		pw1 = lagrange(M, A);
		pw2 = lagrange(M, B) + lagrange(M, A - B);
		if (pw1 < pw2 || (pw1 - pw2) < 1)
			return 0;
	}
	
	return 1;
}

int main()
{
	int test, T;
	
	freopen("far.in", "r", stdin);
	freopen("far.out", "w", stdout);
	
	scanf("%d", &T);
	
	for (test = 1; test <= T; test ++)
	{
		int x, y, mod;
		
		scanf("%d%d%d", &x, &y, &mod);
		
		if (x > y)
			x = x ^ y, y = x ^ y, x = x ^ y;
		printf("%d\n", solve(x + y - 2, y - 1, mod));
	}
	
	return 0;
}
