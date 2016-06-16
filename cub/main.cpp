#include <stdio.h>
#define NMAX 30500

int next[NMAX], cost[NMAX], lenth[NMAX];

int find(int node, int okay)
{
	int cst = 0, cnode = node, root;
	
	while (node)
	{
		root = node;
		cst += cost[node];
		node = next[node];
		if (node == 0)
			cst = cst - cost[root];
	}
	
	if (okay)
		printf("%d\n", cst);
	
	//Compresia drumurilor
	
	node = cnode;
	while (node != root)
	{
		cnode = next[node];
		next[node] = root;
		cst = cst - cost[node];
		cost[node] += cst;
		node = cnode;
	}
	
	return root;
}

int main()
{
	char ch;
	int i, X1, X2, root1, root2;
	
	freopen("cuburi.in", "r", stdin);
	freopen("cuburi.out", "w", stdout);
	
	for (i = 1; i <= 30000; i ++)
		next[i] = cost[i] = 0, lenth[i] = 1; 
	
	while (scanf("%c", &ch) != EOF)
	{
		if (ch == 'P')
		{
			scanf("%d%d\n", &X1, &X2);
			root1 = find(X1, 0);
			root2 = find(X2, 0);
			next[root1] = root2;
			cost[root1] = lenth[root2];
			lenth[root2] += lenth[root1]; lenth[root1] = 0;
		}
		else
		{
			scanf("%d\n", &X1);
			find(X1, 1);
		}
	}
	
	return 0;
}
