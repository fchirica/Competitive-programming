#include <stdio.h>

char x[20][20];
int N, M, dist[20][20], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int decode(char ch)
{
	if (ch == 'N')
		return 0;
	if (ch == 'E')
		return 1;
	if (ch == 'S')
		return 2;
	return 3;
}

void solve(int x0, int y0)
{
	dist[x0][y0] = 0;
	while (1)
	{
		int dir = decode(x[x0][y0]);
		int nx = x0 + dx[dir], ny = y0 + dy[dir];
		if (nx <= 0 || ny <= 0 || nx > N || ny > M)
		{
			printf("%d step(s) to exit\n", dist[x0][y0] + 1);
			return ;
		}
		if (dist[nx][ny] != -1)
		{
			int loop = dist[x0][y0] + 1 - dist[nx][ny];
			printf("%d step(s) before a loop of %d step(s)\n", dist[nx][ny], loop);
			return ;
		}
		dist[nx][ny] = dist[x0][y0] + 1;
		x0 = nx; y0 = ny;
	}
}

int main()
{
	int i, j, where;

	while (1)
	{
		scanf("%d%d%d\n", &N, &M, &where);
		if (N == M && M == where && N == 0)
			return 0;
		for (i = 1; i <= N; i ++, scanf("\n"))
			for (j = 1; j <= M; j ++)
			{
				scanf("%c", &x[i][j]);
				dist[i][j] = -1;
			}
		solve(1, where);
	}
	
	return 0;
}
