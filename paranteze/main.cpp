#include <stdio.h>
#define NMAX 1000100

char x[NMAX];
int dp[NMAX], st[NMAX];

int main()
{
	int N, i, u = 0, okay, sol = 0;
	
	freopen("paranteze.in", "r", stdin);
	freopen("paranteze.out", "w", stdout);
	
	scanf("%d\n", &N);
	gets(x + 1);
	
	for (i = 1; i <= N; i ++)
	{
		st[++ u] = i;
		if (u == 1)
			continue;
		okay = 0;
		if (x[st[u - 1]] == '(' && x[i] == ')')
			okay = 1;
		if (x[st[u - 1]] == '[' && x[i] ==']')
			okay = 1;
		if (x[st[u - 1]] == '{' && x[i] == '}')
			okay = 1;
		if (okay)
		{
			dp[i] = i - st[u - 1] + 1 + dp[st[u - 1] - 1];
			if (dp[i] > sol)
				sol = dp[i];
			u = u - 2;
		}
	}
		
	printf("%d", sol);
	return 0;
}
