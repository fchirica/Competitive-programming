#include <stdio.h>
#include <string.h>
#include <iostream>
#define LMAX 3000100
#define unUsed -1

char x[LMAX];
int last[30];

int main()
{
	int i, N, lastElim = 0, nowElim, min, bestElim;
	
	freopen("cmmstr.in", "r", stdin);
	freopen("cmmstr.out", "w", stdout);
	
	gets(x + 1);
	N = strlen(x + 1);
	
	for (i = 0; i < 26; i ++)
		last[i] = unUsed;
	for (i = 1; i <= N; i ++)
		last[x[i] - 'a'] = i;
	
	while (1)
	{
		min = 1000000000;
		for (i = 0; i < 26; i ++)
			if (last[i] < min && last[i] != unUsed)
				min = last[i];
		if (min == 1000000000)
			break;
		
		nowElim = min; min = 1000000000;
		for (; nowElim > lastElim; nowElim --)
			if (x[nowElim] <= min && last[x[nowElim] - 'a'] != unUsed)
				min = x[nowElim], bestElim = nowElim;
		
		printf("%c", x[bestElim]);
		last[min - 'a'] = unUsed;
		lastElim = bestElim;
	}
	
	return 0;
}
