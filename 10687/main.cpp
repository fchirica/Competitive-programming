#include <stdio.h>
#include <string.h>

struct point
{
	int x, y;
} x[1 << 10];

int graf[1024][3], vis[1024];

int solve(int idx, int forbidden, int N)
{
	int i, dmin = 1 << 30, dnow, px = 1 << 30, py = 1 << 30, sol = 0;
	
	for (i = 1; i <= N; i ++)
		if (i != forbidden && i != idx)
		{
			dnow = (x[idx].x - x[i].x) * (x[idx].x - x[i].x) + (x[idx].y - x[i].y) * (x[idx].y - x[i].y);
			if (dnow < dmin)
				dmin = dnow, sol = i, px = x[i].x, py = x[i].y;
			if (dnow == dmin && x[i].x < px)
				dmin = dnow, sol = i, px = x[i].x, py = x[i].y;
			if (dnow == dmin && x[i].x == px && x[i].y < py)
				dmin = dnow, sol = i, px = x[i].x, py = x[i].y;
		}
	return sol;
}

void DFS(int nod)
{
	vis[nod] = 1;
	
	int i;
	for (i = 1; i <= 2; i ++)
		if (vis[graf[nod][i]] == 0)
			DFS(graf[nod][i]);
}

int main()
{
	int i, N;
	
	while (scanf("%d", &N) != EOF)
	{
		if (N == 0)
			return 0;
		for (i = 1; i <= N; i ++)
			scanf("%d%d", &x[i].x, &x[i].y);
		for (i = 1; i <= N; i ++)
		{
			graf[i][1] = solve(i, 10000, N);
			graf[i][2] = solve(i, graf[i][1], N);
		}
		
		memset(vis, 0, sizeof(vis));
		DFS(1);
		vis[0] = 1;
		
		bool isConnected = true;
		for (i = 2; i <= N; i ++)
			if (vis[i] == 0)
				isConnected = false;
		if (isConnected)
			printf("All stations are reachable.");
		else
			printf("There are stations that are unreachable.");
		printf("\n");
	}
	
	return 0;
}
