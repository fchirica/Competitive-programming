#include <stdio.h>

int G[210][210], deg[210], vis[210];

void DFS(int nod, int N)
{
	int i;
	
	vis[nod] = 1;
	for (i = 1; i <= N; i ++)
		if (G[nod][i] && vis[i] == 0)
			DFS(i, N);
}

int main()
{
	int i, j, N, R;
	
	while (scanf("%d%d", &N, &R) != EOF)
	{
		int x0, x1;
		
		for (i = 1; i <= R; i ++)
		{
			scanf("%d%d", &x0, &x1); x0 ++; x1 ++;
			deg[x0] ++; deg[x1] ++;
			G[x0][x1] = G[x1][x0] = 1;
		}
		
		DFS(1, N);
		bool possible = true;
		
		for (i = 1; i <= N; i ++)
			if (vis[i] == 0 || deg[i] % 2)
				possible = false;
		if (possible)
			printf("Possible\n");
		else
			printf("Not Possible\n");
		
		for (i = 1; i <= N; i ++)
		{
			deg[i] = 0;
			for (j = 1; j <= N; j ++)
				G[i][j] = 0;
		}
	}
	
	return 0;
}
