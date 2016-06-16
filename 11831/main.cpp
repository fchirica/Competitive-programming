#include <stdio.h>

char x[105][105];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
	int N, M, S;
	int i, j, x0, y0, dir;
	
	while (1)
	{
		scanf("%d%d%d\n", &N, &M, &S);
		if (N == 0 && M == 0 && S == 0)
			return 0;
		for (i = 1; i <= N; i ++, scanf("\n"))
			for (j = 1; j <= M; j ++)
			{
				scanf("%c", &x[i][j]);
				if (x[i][j] == 'N')
					x0 = i, y0 = j, dir = 0;
				if (x[i][j] == 'S')
					x0 = i, y0 = j, dir = 2;
				if (x[i][j] == 'L')
					x0 = i, y0 = j, dir = 1;
				if (x[i][j] == 'O')
					x0 = i, y0 = j, dir = 3;
			}
		
		int stickers = 0;
		char command;
		
		for (i = 1; i <= S; i ++)
		{
			scanf("%c", &command);
			if (command == 'D')
				dir = (dir + 1) % 4;
			if (command == 'E')
				dir = (dir + 3) % 4;
			if (command == 'F')
			{
				int nx = x0 + dx[dir], ny = y0 + dy[dir];
				if (nx <= 0 || ny <= 0 || nx > N || ny > M)
					continue;
				if (x[nx][ny] == '#')
					continue;
				x0 = nx; y0 = ny;
				if (x[x0][y0] == '*')
				{
					stickers ++;
					x[x0][y0] = '.';
				}
			}
		}
		printf("%d\n", stickers);
	}
	
	return 0;
}
