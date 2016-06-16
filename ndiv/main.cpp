#include <stdio.h>

long long solve(int x)
{
	int d;
	long long sol = 0, now;
	
	for (d = 1; (long long)d * d <= x; d ++)
	{
		now = x / d - d;
		now = now * 2 + 1;
		sol = sol + now;
	}
	
	return sol;
}

int main()
{
	int A, B;
	
	freopen("ndiv.in", "r", stdin);
	freopen("ndiv.out", "w", stdout);
	
	scanf("%d%d", &A, &B);
	printf("%lld", solve(B) - solve(A - 1));
	
	return 0;
}

