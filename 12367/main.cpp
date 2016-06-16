#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char line[1 << 10];
int x[1 << 10][1 << 10], now[1 << 10], A[1 << 10];

inline int ab(int X)
{
	if (X > 0)
		return X;
	return X * (-1);
}

int minChanges(int N)
{
	int i, med = 0;
	
	for (i = 1; i <= N; i ++)
		med = med + now[i];
	if (med % N)
		return -1;
	med = med / N;
	
	memset(A, 0, sizeof(A));
	for (i = 1; i <= N; i ++)
		A[i] = med - now[i];
	A[1] = 0;
	for (i = N - 1; i > 1; i --)
		A[i] = A[i] + A[i + 1];
	sort(A + 1, A + N + 1);

	int mediana, sol = 0;
	
	if (N % 2)
		mediana = A[(N + 1) / 2];
	else
		mediana = (A[N / 2] + A[N / 2 + 1]) / 2;
	
	for (i = 1; i <= N; i ++)
	{
		A[i] = A[i] - mediana;
		sol = sol + ab(A[i]);
	}
	
	return sol;
}

int main()
{
	int i, j, test, Q, N, M;
	
	scanf("%d\n", &Q);
	for (test = 1; test <= Q; test ++)
	{
		scanf("%d%d\n", &N, &M);
		memset(x, 0, sizeof(x));
		for (i = 1; i <= N; i ++)
		{
			memset(line + 1, 0, sizeof(line + 1));
			gets(line + 1);
			for (j = 1; j <= M; j ++)
				x[i][j] = line[j] - '0';
		}
		
		memset(now, 0, sizeof(now));
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= M; j ++)
				now[i] += x[i][j];
		int sol = minChanges(N);
		if (sol == -1)
		{
			if (test != 1)
				printf("\n");
			printf("Case %d: impossible", test);
			continue;
		}
		memset(now, 0, sizeof(now));
		for (j = 1; j <= M; j ++)
			for (i = 1; i <= N; i ++)
				now[j] += x[i][j];
		int sol2 = minChanges(M);
		if (sol2 == -1)
		{
			if (test != 1)
				printf("\n");
			printf("Case %d: row %d", test, sol);
			continue;
		}
		if (test != 1)
			printf("\n");
		printf("Case %d: both %d", test, sol + sol2);
	}
	
	return 0;
}
