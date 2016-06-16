#include <stdio.h>

int sol = 1000000000; 
int d[10000];

void compute(long long d, long long prod)
{
	long long D, sol1, sol2;
	
	D = prod / d;
	if ((D + d) % 2)
		return ;
	sol1 = (d + D) / 2;
	sol2 = D - sol1;
	if (sol2 < sol && sol2 > 0)
		sol = sol2;
}

int main()
{
	int x, i, j;
	
	freopen("pitagora2.in", "r", stdin);
	freopen("pitagora2.out", "w", stdout);
	
	scanf("%d", &x);
	
	for (i = 1; i * i <= x; i ++)
		if (x % i == 0)
		{
			d[++ d[0]] = i;
			d[++ d[0]] = x / i;
		}
	
	for (i = 1; i <= d[0]; i ++)
		for (j = 1; j <= d[0]; j ++)
			compute((long long)d[i] * d[j], (long long)x * x);
	
	if (sol == 1000000000)
		sol = -1;
	printf("%d", sol);
	return 0;
}