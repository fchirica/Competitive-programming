//O (T * sqrtP) Baby-step giant-step algorithm

#include <stdio.h>
#include <assert.h>
#include <math.h>
#define PMAX 2000100

int x[PMAX];

void addTable (int A, int lim, int P)
{
	int pw = 1, i;
	
	for (i = 0; i <= lim; i ++)
	{
		if (x[pw] == -1)
			x[pw] = i;
		pw = (long long)pw * A % P;
	}
}

void delTable (int A, int lim, int P)
{
	int pw = 1, i;
	
	for (i = 0; i <= lim; i ++)
	{
		x[pw] = -1;
		pw = (long long)pw * A % P;
	}
}

int FastPow (int A, int B, int P)
{
	if (B == 0)
		return A % P;
	if (B == 1)
		return A;
	int now = FastPow (A, B / 2, P);
	if (B % 2 == 0)
		return (long long)now * now % P;
	else
		return (((long long)now * now) % P * (long long)A) % P;
}

int main ()
{
	int i, Q, A, B, P, M, val;
	
	freopen ("dlog.in", "r", stdin);
	freopen ("dlog.out", "w", stdout);
	
	for (i = 0; i <= 2000000; i ++)
		x[i] = -1;
	
	scanf ("%d", &Q);
	while (Q --)
	{
		scanf ("%d%d%d", &P, &A, &B);
		
		M = ceil ((double)sqrt (P - 1));
		
		addTable (A, M - 1, P);
		
		val = FastPow (A, M, P);
		val = FastPow (val, P - 2, P);
		
		for (i = 0; i < M; i ++)
		{
			if (x[B] != -1)
			{
				printf ("%d\n", i * M + x[B]);
				break;
			}
			B = (long long)B * val % P;
		}
		delTable (A, M - 1, P);
	}
	
	return 0;
}
