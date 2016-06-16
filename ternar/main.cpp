#include <stdio.h>

int minx, maxx, miny, maxy, x[1300][1300];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int Qx[1234 * 1234 + 100], Qy[1234 * 1234 + 100];

void update(int x0, int y0)
{
	x[x0][y0] = 100;
	if (x0 < minx)
		minx = x0;
	if (x0 > maxx)
		maxx = x0;
	if (y0 < miny)
		miny = y0;
	if (y0 > maxy)
		maxy = y0;
}

void BFS(int x0, int y0)
{
	int p = 1, u = 0, d;
	
	Qx[++ u] = x0; Qy[u] = y0;
	update(x0, y0);
	
	while (p <= u)
	{
		for (d = 0; d < 4; d ++)
			if (x[Qx[p] + dx[d]][Qy[p] + dy[d]] == 2)
			{
				Qx[++ u] = Qx[p] + dx[d];
				Qy[u] = Qy[p] + dy[d];
				update(Qx[p] + dx[d], Qy[p] + dy[d]);
			}
		p ++;
	}
}

bool check()
{
	int i, j;
	
	for (i = miny - 1; i <= maxy + 1; i ++)
		if (x[minx - 1][i] != 1 || x[maxx + 1][i] != 1)
			return 0;
	for (i = minx - 1; i <= maxx + 1; i ++)
		if (x[i][miny - 1] != 1 || x[i][maxy + 1] != 1)
			return 0;
	for (i = minx; i <= maxx; i ++)
		for (j = miny; j <= maxy; j ++)
			if (x[i][j] != 100)
				return 0;
	return 1;
}

int main()
{
	int i, j, N, M, sol = 0;
	
	freopen("ternar.in", "r", stdin);
	freopen("ternar.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			scanf("%d", &x[i][j]);
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			if (x[i][j] == 2)
			{
				minx = miny = 1000000;
				maxx = maxy = -1;
				BFS(i, j);
				if (check())
					if ((maxx - minx + 3) * (maxy - miny + 3) > sol)
						sol = (maxx - minx + 3) * (maxy - miny + 3);
			}
			
	printf("%d", sol);
	return 0;
}
