//ciucuiaaaaalaaaa

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#define NMAX 50500

int x[NMAX], used[NMAX], available[NMAX];
bool semn[NMAX];

void swap(int &X, int &Y)
{
	int aux = X;
	X = Y;
	Y = aux;
}

int main()
{
	int i, N, pos;
	long long S, ss = 0, nowSum = 0;
	
	freopen("semne.in", "r", stdin);
	freopen("semne.out", "w", stdout);
	
	srand(time(0));
	
	scanf("%d%lld", &N, &S);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		ss += x[i];
	}
	
	ss = (ss - S) / 2;
	for (i = 1; i <= N; i ++)
		if (x[i] <= ss)
			available[++ available[0]] = i;
		
	while (nowSum != ss)
	{
		if (nowSum < ss)
		{
			pos = rand() % available[0] + 1;
			semn[available[pos]] = 1;
			nowSum += x[available[pos]];
			swap(available[pos], available[available[0]]);
			available[0] --;
			used[++ used[0]] = available[available[0] + 1];
		}
		if (nowSum > ss)
		{
			pos = rand() % used[0] + 1;
			semn[used[pos]] = 0;
			nowSum -= x[used[pos]];
			swap(used[used[0]], used[pos]); used[0] --;
			available[++ available[0]] = used[used[0] + 1];
		}
	}
	
	for (i = 1; i <= N; i ++)
		printf("%c", semn[i] ? '-' : '+');
	return 0;
}
