#include <stdio.h>

int small[1100], big[1100], M1[1100], M2[1100];

void discard(int x[], int N)
{
	int i;
	
	for (i = 1; i <= N; i ++)
		small[x[i]] = big[x[i]] = 0;
}

void keep(int x[], int where[], int cnt, int N)
{
	int i;
	
	for (i = 1; i <= cnt; i ++)
		if (where[x[i]] == 1)
			where[x[i]] = -1;
	for (i = 1; i <= N; i ++)
		if (where[i] == -1)
			where[i] = 1;
		else
			where[i] = 0;
}

int sol;

int count(int x[], int N)
{
	int i, tot = 0;
	
	for (i = 1; i <= N; i ++)
		if (x[i])
			tot ++, sol = i;
	return tot;
}

int main()
{
	int i, j, N, M;
	
	freopen("balanta.in", "r", stdin);
	freopen("balanta.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
		small[i] = big[i] = 1;
	
	for (i = 1; i <= M; i ++)
	{
		int x, relation;
		
		scanf("%d", &x);
		for (j = 1; j <= x; j ++)
			scanf("%d", &M1[j]);
		for (j = 1; j <= x; j ++)
			scanf("%d", &M2[j]);
		scanf("%d", &relation);
		
		if (relation == 0)
			discard(M1, x), discard(M2, x);
		if (relation == 1)
			keep(M1, big, x, N), keep(M2, small, x, N);
		if (relation == 2)
			keep(M1, small, x, N), keep(M2, big, x, N);
	}
	
	if (count(big, N) + count(small, N) == 1)
		printf("%d", sol);
	else
		printf("0");
	return 0;
}
