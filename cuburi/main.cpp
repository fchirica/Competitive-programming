#include <stdio.h>

int next[NMAX], cost[NMAX], len[NMAX];

int main()
{
	char op;
	int T1, T2;
	
	freopen("cuburi.in", "r", stdin);
	freopen("cuburi.out", "w", stdout);
	
	while (scanf("%c", &op) != EOF)
	{
		if (op == 'P')
		{
			scanf("%d%d\n", &T1, &T2);
			unite(T1, T2);
		}
		if (op == 'S')
		{
			scanf("%d\n", &T1);
			query(T1);
		}
	}
	
	return 0;
}
