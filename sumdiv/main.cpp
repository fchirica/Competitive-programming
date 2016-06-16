//Respect Mihai Patrascu, sincere condoleante

#include <stdio.h>
#define MOD 9901

inline int FastPow(int A, int B)
{
	int now;
	
	if (B == 1)
		return A;
	now = FastPow(A, B / 2);
	
	now = (long long)now * now % MOD;
	if (B % 2 == 0)
		return now;
	return (long long)now * A % MOD;
}

inline int compute (int A, int B)
{
	if (A % MOD == 1)
		return (B + 1) % MOD;
	
	int ans = FastPow(A, B + 1) - 1;
	
	ans = ans * FastPow(A - 1, 9899) % MOD;
	return ans;
}

int main()
{
	int A, B, pw, sol = 1, d;
	
	freopen("sumdiv.in", "r", stdin);
	freopen("sumdiv.out", "w", stdout);
	
	scanf("%d%d", &A, &B);
	
	for (d = 2; d * d <= A; d ++)
	{
		pw = 0;
		while (A % d == 0)
		{
			pw ++;
			A = A / d;
		}
		pw = pw * B;
		
		if (pw > 0)
			sol = sol * compute(d, pw) % MOD;
	}
	
	if (A > 1)
		sol = sol * compute(A, B) % MOD;
	
	while (sol < 0)
		sol = sol + MOD;
	printf("%d", sol);
	return 0;
}
