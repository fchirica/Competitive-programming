//Faraonu, Faraonu, cine este faraonu? 
//Am piramideee

#include <stdio.h>
#define MOD 10000
	
int comb[20][20];
int sol[2][600600];

int main()
{
	int i, j, S, N, last;
	
	freopen("piramida.in", "r", stdin);
	freopen("piramida.out", "w", stdout);
	
	scanf("%d", &S);
	for (N = 0; (1 << N) <= S; N ++); 
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= i; j ++)
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
	
	sol[0][0] = 1;
	for (i = 1; i <= N; i ++)
	{
		last = S - ((1 << N) - comb[N][i]);
		for (j = 1; j * comb[N][i] <= last; j ++)
			for (k = 0; k + j * comb[N][	i] <= last; k ++)
				if (sol[(i - 1) & 1][k])
					sol[i & 1][