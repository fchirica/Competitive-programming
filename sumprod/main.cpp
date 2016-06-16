#include <stdio.h>

int run, k, N, S, P, x[100], now[10];

void Solve (int L, int sum, int prod, int lasti)
{
	int last, i;
	if (run == 0)
		return ;
	if (L == k)
	{
		last = S - sum;
		if (prod * last != P)
			return ;
		now[L] = last;
		for (i = 1; i <= L; i ++)
			printf ("%d ", now[i]);
		run = 0;
	}

	for (i = lasti; i <= N; i ++)
	{
		if (sum + x[i] > S || prod * x[i] > P)
			break;
		now[L] = x[i];
		Solve (L + 1, sum + x[i], prod * x[i], i);
	}
}

int main ()
{
	int i;

	freopen ("sumprod.in", "r", stdin);
	freopen ("sumprod.out", "w", stdout);

	scanf ("%d %d %d", &S, &P, &k);
	for (i = 1; i <= S; i ++)
		if (P % i == 0)
			x[++ N] = i;

	if (k == 0)
	{
		printf ("NU");
		return 0;
	}
	if (k == 1)
	{
		if (S == P)
			printf ("%d", S);
		else
			printf ("NU");
		return 0;
	}
	if (P == 0)
	{
		for (i = 1; i < k; i ++)
			printf ("0 ");
		printf ("%d ", S);
		return 0;
	}
	run = 1;
	Solve (1, 0, 1, 1);
	if (run)
		printf ("NU");

	return 0;
}


