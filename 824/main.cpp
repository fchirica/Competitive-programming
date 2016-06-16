#include <stdio.h>
#include <string.h>
 
int N, M, x[15][15], vis[15][15], mysol[15][15], canReach[15][15];
 
int canN(int x0, int y0)
{
        if (x0 == 1)
                return 0;
        if (x[x0 - 1][y0] >= 2)
                return 0;
        return 1;
}
 
int canS(int x0, int y0)
{
        if (x0 == N)
                return 0;
        if (x[x0][y0] >= 2)
                return 0;
        return 1;
}
 
int canE(int x0, int y0)
{
        if (y0 == M)
                return 0;
        if (x[x0][y0] == 1 || x[x0][y0] == 3)
                return 0;
        return 1;
}
 
int canW(int x0, int y0)
{
        if (y0 == 1)
                return 0;
        if (x[x0][y0 - 1] == 1 || x[x0][y0 - 1] == 3)
                return 0;
        return 1;
}
 
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
 
int check(int x0, int y0, int dir)
{
        if (dir == 0)
                return canW(x0, y0);
        if (dir == 1)
                return canN(x0, y0);
        if (dir == 2)
                return canE(x0, y0);
        return canS(x0, y0);
}

void show(int x)
{
	if (x == 0)
		printf("   ");
	if (1 <= x && x <= 9)
		printf("  %d", x);
	if (10 <= x && x <= 99)
		printf(" %d", x);
	if (100 <= x && x <= 999)
		printf("%d", x);
	if (x == -1)
		printf("???");
}

void print()
{
	int i, j;
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			if (canReach[i][j] && mysol[i][j] == 0)
				mysol[i][j] = -1;
	
	for (i = 1; i <= M; i ++)
		printf("+---");
	printf("+\n");
	for (i = 1; i <= N; i ++)
	{
		for (j = 1; j <= M; j ++)
			if (canW(i, j))
			{
				printf(" ");
				show(mysol[i][j]);
			}
			else
			{
				printf("|");
				show(mysol[i][j]);
			}
		printf("|\n");
		if (i != N)
		{
			for (j = 1; j <= M; j ++)
				if (canS(i, j))
					printf("+   ");
				else
					printf("+---");
			printf("+\n");
		}
	}
	for (i = 1; i <= M; i ++)
		printf("+---");
	printf("+\n");
}

int x1, y1;
bool isSolution;

void DFS(int x0, int y0, int cost)
{
	int d;
	
	vis[x0][y0] = cost + 1;	
	canReach[x0][y0] = 1;
	
	if (x0 == x1 && y0 == y1)
	{
		memcpy(mysol, vis, sizeof(mysol));
		isSolution = true;
	}
	if (isSolution)
		return; 
	
	for (d = 0; d < 4 && isSolution == false; d ++)
		if (check(x0, y0, d) && vis[x0 + dx[d]][y0 + dy[d]] == 0)
			DFS(x0 + dx[d], y0 + dy[d], cost + 1);
		
	vis[x0][y0] = 0;
}

int main()
{
        int i, j, x0, y0, dir, test = 0;
       
        while (1)
        {
                scanf("%d%d%d%d%d%d", &N, &M, &x0, &y0, &x1, &y1);
               
                memset(x, 0, sizeof(x));
                memset(vis, 0, sizeof(vis));
				memset(canReach, 0, sizeof(canReach));
				
                if (N == 0 && M == 0 && x0 == 0 && y0 == 0 && x1 == 0 && y1 == 0)
                        break;
                for (i = 1; i <= N; i ++)
                        for (j = 1; j <= M; j ++)
							scanf("%d", &x[i][j]);
								
				
				isSolution = false;
				DFS(x0, y0, 0);
				++test; 
				printf("Maze %d\n\n", test);
				print();
				printf("\n\n");
        }
       
        return 0;
}