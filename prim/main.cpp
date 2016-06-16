#include <stdio.h>

bool c[2000000];

void precalc()
{
	int i, j, bound = 1900000;
	
	for (i = 3; i * i <= bound; i ++)
		if (!c[i])
			for (j = i * i; j <= bound; j = j + 2 * i)
				c[j] = 1;
}

bool prime(long long x)
{
	if (x == 2)
		return 1;
	if (x % 2 == 0)
		return 0;
	return !c[x];
}

int main()
{
	int left;
	long long x;
	
	freopen("prim.in", "r", stdin);
	freopen("prim.out", "w", stdout);

	scanf("%d", &left); left ++;
	
	precalc();
	
	for (x = 2; left > 0; x ++)
	{
		if (prime(x))
		{
			left --;
			if (left == 0)
				break;
		}
	}
	
	printf("%lld", x * x);
	return 0;
}
