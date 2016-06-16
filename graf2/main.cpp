#include <stdio.h>
#include <string.h>

int N, G[610][610], GT[610][610], GN[610][610], GN2[610][610];
int vis[610], timp[610], ctc[610], numCTC, sol = 0, times = 0;

void DFS1(int nod)
{
	int i;
	
	vis[nod] = 1;
	for (i = 1; i <= N; i ++)
		if (GT[nod][i] == 1 && !vis[i])
			DFS1(i);
		
	timp[++ timp[0]] = nod;
}

void DFS2(int nod)
{
	int i;
	
	vis[nod] = 1; ctc[nod] = numCTC;
	times ++;
	
	for (i = 1; i <= N; i ++)
	{
		if (G[nod][i] == 1 && !vis[i])
			DFS2(i);
		if (G[nod][i] == 1 && vis[i])
			if (ctc[nod] != ctc[i])
				GN[ctc[nod]][ctc[i]] = 1;
	}
}

int main()
{
	int i, j, k, M;
	
	freopen("graf2.in", "r", stdin);
	freopen("graf2.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		int x0, y0;
		scanf("%d%d", &x0, &y0);
		G[x0][y0] = 1;
		GT[y0][x0] = 1;
	}
	
	for (i = 1; i <= N; i ++)
		if (vis[i] == 0)
			DFS1(i);
	for (i = 1; i <= N; i ++)
		vis[i] = 0;
	for (i = timp[0]; i >= 1; i --)
		if (vis[timp[i]] == 0)
		{
			++ numCTC;
			times = 0;
			DFS2(timp[i]);
			if (times > 1)
				sol += times;
		}
		
	N = numCTC;
	for (i = 1; i <= N; i ++)
		for (j = N; j >= 1; j --)
			if (GN[i][j] == 1 && GN2[i][j] == 0)
			{
				++ sol; GN2[i][j] = 1;
				for (k = 1; k <= N; k ++)
					if (GN2[j][k] == 1)
						GN2[i][k] = 1;
			}
	
	printf("%d", sol);
	return 0;
}
