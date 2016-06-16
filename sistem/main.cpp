#include <stdio.h>
#include <string.h>
#define A tmp
#define B sol[idx - 3]
#define C sol[idx]

int sol[150][1024], tmp[1024];

void inm(int X[], int scal)
{
	int i, tr = 0;
	
	for (i = 1; i <= X[0]; i ++)
	{
		X[i] = X[i] * scal + tr;
		tr = X[i] / 10;
		X[i] = X[i] % 10;
	}
	
	while (tr)
		X[++ X[0]] = tr % 10, tr = tr / 10;
}

void baga(int idx)
{
	int i, tr = 0;
	
	C[0] = A[0];
	if (B[0] > C[0])
		C[0] = B[0];
	
	for (i = 1; i <= C[0]; i ++)
	{
		C[i] = A[i] + B[i] + tr;
		tr = C[i] / 10;
		C[i] = C[i] % 10;
	}
	
	if (tr)
		C[++ C[0]] = 1;
}

int main()
{
	int i, N;
	
	freopen("sistem.in", "r", stdin);
	freopen("sistem.out", "w", stdout);
	
	scanf("%d", &N);
	sol[3][0] = sol[3][1] = 1;
	
	for (i = 4; i <= N; i ++)
	{
		memcpy(tmp, sol[i - 1], sizeof(tmp));
		inm(tmp, i - 1);
		inm(sol[i - 3], (i - 2) * (i - 1) / 2);
		baga(i);
	}
	
	for (i = sol[N][0]; i >= 1; i --)
		printf("%d", sol[N][i]);
	return 0;
}
