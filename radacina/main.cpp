#include <stdio.h>

double x[10];
int N;

int semn(double val)
{
	int i;
	double sum = 0, now = 1;
	
	for (i = 0; i <= N; i ++)
	{
		sum = sum + x[i] * now;
		now = now * val;
	}
	
	if (sum > 0)
		return 1;
	return -1;
}


int main()
{
	int i;
	
	freopen("radacina.in", "r", stdin);
	freopen("radacina.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 0; i <= N; i ++)
		scanf("%lf", &x[i]);
	
	double st = -20, dr = 20, med;
	
	int step;
	for (step = 1; step <= 100; step ++)
	{
		med = (st + dr) / 2.0;
		if (semn(st) * semn(med) == -1)
			dr = med;
		else
			st = med;
	}
	
	printf("%lf", med);
	return 0;
}
