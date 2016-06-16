#include <stdio.h>

int G[52][52], deg[52], vis[52];
int st[1024];

void DFS(int nod)
{
	int i;
	
	vis[nod] = 1;
	for (i = 1; i <= 50; i ++)
		if (vis[i] == 0 && G[nod][i])
			DFS(i);
}

void tour(int nod)
{
	int i;
	while (1)
	{
		int next = 1 << 30;
		
		for (i = 1; i <= 50; i ++)
			if (G[nod][i])
			{
				G[nod][i] --; G[i][nod] --;
				next = i;
				break;
			}
		
		if (next == 1 << 30)
			break;
		st[++ st[0]] = next;
		nod = next;
	}
}

int main()
{
	int i, j, T, test;

	scanf("%d", &T);
	for (test = 1; test <= T; test ++)
	{
		int N;
		
		if (test > 1)
			printf("\n");
		
		scanf("%d", &N);
		
		for (i = 1; i <= 50; i ++)
			deg[i] = 0;
		for (i = 1; i <= N; i ++)
		{
			int x0, y0;
			scanf("%d%d", &x0, &y0);
			G[x0][y0] ++; G[y0][x0] ++;
			deg[x0] ++; deg[y0] ++;
		}
		
		bool degParity = false;
		for (i = 1; i <= 50; i ++)
			if (deg[i] % 2)
				degParity = true;
		
		bool notConnected = false;
		for (i = 1; i <= 50; i ++)
			vis[i] = 0;
		for (i = 1; i <= 50; i ++)
			if (deg[i] > 0)
			{
				DFS(i);
				break;
			}
		for (i = 1; i <= 50; i ++)
			if (deg[i] > 0 && vis[i] == 0)
				notConnected = true;
			
		if (degParity || notConnected) 
		{
			printf("Case #%d\nsome beads may be lost\n", test);
			for (i = 1; i <= 50; i ++)
				for (j = 1; j <= 50; j ++)
					G[i][j] = 0;
			continue;
		}
		
		printf("Case #%d\n", test);
		st[0] = 0;
		for (i = 1; i <= 50; i ++)
			if (deg[i] > 0)
			{
				st[++ st[0]] = i;
				break;
			}
		while (1)
		{
			tour(st[st[0]]);
			if (st[0] == 1)
				break;
			printf("%d %d\n", st[st[0]], st[st[0] - 1]);
			st[0] --;
		}
		
		for (i = 1; i <= 50; i ++)
			for (j = 1; j <= 50; j ++)
				G[i][j] = 0;
	}
	
	return 0;
}
