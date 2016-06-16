#include <stdio.h>

int x[70][70];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
	int i, j, test, testCases, N, M, x0, y0, dir;
	char ch;
	
	scanf("%d", &testCases);
	for (test = 1; test <= testCases; test ++)
	{
		scanf("%d%d\n", &N, &M);
		for (i = 1; i <= N; i ++, scanf("\n"))
			for (j = 1; j <= M; j ++)
			{
				scanf("%c", &ch);
				if (ch == '*')
					x[i][j] = -1;
				else
					x[i][j] = 0;
			}
		scanf("%d%d", &x0, &y0); dir = 0;
		while (1)
		{
			scanf("%c", &ch);
			if (ch == ' ' || ch == '\n')
				continue;
			if (ch == 'Q')
			{
				printf("%d %d ", x0, y0);
				if (dir == 0)
					printf("N");
				if (dir == 1)
					printf("E");
				if (dir == 2)
					printf("S");
				if (dir == 3)
					printf("W");
				printf("\n");
				if (test != testCases)
					printf("\n");
				break;
			}
			if (ch == 'L')
				dir = (dir + 3) % 4;
			if (ch == 'R')
				dir = (dir + 1) % 4;
			if (ch == 'F')
			{
				int nx = x0 + dx[dir], ny = y0 + dy[dir];
				if (x[nx][ny] != -1)
					x0 = nx, y0 = ny;
			}
		}
	}
	
	return 0;
}
