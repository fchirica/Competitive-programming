#include <stdio.h>

int f[25];
double w[25];

int main()
{
	int i, j;
	double val = 1;
	
	freopen("pl.in", "r", stdin);
	freopen("pl.out", "w", stdout);
	
	for (i = 0; i <= 20; i ++)
	{
		if (i)
			f[i] = f[i - 1];
		for (j = 1; j <= 8; j ++)
		{
			int x;
			scanf("%d", &x);
			f[i] += x;
		}
		w[i] = 105 * val;
		val = val * (double)1.015;
	}
	
	for (i = 0; i <= 20; i ++)
	{
		printf("[TR][TD]%d[/TD][TD]%d[/TD][TD]%.4lf[/TD]", i, f[i], w[i]);
		double comp = w[i] * ((1000000 - f[i]) / 315);
		if (comp < 0)
			printf("[TD]Not enough resources![/TD]\n");
		else
			printf("[TD]%.4lf[/TD][/TR]\n", comp);
	}
	
	return 0;
}
