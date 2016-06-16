#include <stdio.h>
#include <string.h>

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char commands[105];
bool killed[55][55];

char get(int dir)
{
	if (dir == 0)
		return 'N';
	if (dir == 1)
		return 'E';
	if (dir == 2)
		return 'S';
	return 'W';
}

int main()
{
	int N, M, x0, y0, dir, i;
	char D;
	
	scanf("%d%d", &N, &M);
	while (scanf("%d %d %c\n", &x0, &y0, &D) != EOF)
	{
		gets(commands + 1);
		if (D == 'N')
			dir = 0;
		if (D == 'E')
			dir = 1;
		if (D == 'S')
			dir = 2;
		if (D == 'W')
			dir = 3;
		
		int cntCmds = strlen(commands + 1);
		bool isDead = false;
		
		for (i = 1; i <= cntCmds; i ++)
		{
			char now = commands[i];
			if (now == 'F')
			{
				int nx = x0 + dx[dir], ny = y0 + dy[dir];
				if (0 <= nx && 0 <= ny && nx <= N && ny <= M)
					x0 = nx, y0 = ny;
				else
				{
					if (killed[x0][y0])
						continue;
					killed[x0][y0] = 1;
					isDead = true;
					break;
				}
			}
			if (now == 'R')
				dir = (dir + 1) % 4;
			if (now == 'L')
				dir = (dir + 3) % 4;
		}
		
		printf("%d %d %c", x0, y0, get(dir));
		if (isDead)
			printf(" LOST\n");
		else
			printf("\n");
	}
	
	return 0;
}
