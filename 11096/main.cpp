#include <stdio.h>
#include <string.h>

int dx[10], dy[10];
int x[112][112], vis[112][112];
int N, M;

inline bool inside(int x0, int y0)
{
	return 0 <= x0 && 0 <= y0 && x0 < N && y0 < M;
}

void DFS(int x0, int y0)
{
	x[x0][y0] = 1;
	
	int d;
	for (d = 1; d <= 8; d ++)
		if (inside(x0 + dx[d], y0 + dy[d]) && x[x0 + dx[d]][y0 + dy[d]] == 0)
			DFS(x0 + dx[d], y0 + dy[d]);
}

int main()
{
	int i, j, k, K, x0, y0, testCases, test, n, m;
	
	scanf("%d", &testCases);
	for (test = 1; test <= testCases; test ++)
	{
		scanf("%d%d%d%d", &N, &M, &n, &m);
		scanf("%d", &K);
		memset(x, 0, sizeof(x));
		
		for (i = 1; i <= K; i ++)
		{
			scanf("%d%d", &x0, &y0);
			x[x0][y0] = -1;
		}
		
		dx[1] = n; dy[1] = m;
		dx[2] = n; dy[2] = m * (-1);
		dx[3] = n * (-1); dy[3] = m;
		dx[4] = n * (-1); dy[4] = m * (-1);
		dx[5] = m; dy[5] = n;
		dx[6] = m; dy[6] = n * (-1);
		dx[7] = m * (-1); dy[7] = n;
		dx[8] = m * (-1); dy[8] = n * (-1);
		
		DFS(0, 0);
		
		int odd = 0, even = 0;
		for (i = 0; i < N; i ++)
			for (j = 0; j < M; j ++)
				if (x[i][j] == 1)
				{
					int cnt = 0;
					for (k = 1; k <= 8; k ++)
						if (inside(i + dx[k], j + dy[k]) && x[i + dx[k]][j + dy[k]] == 1 && vis[i + dx[k]][j + dy[k]] == 0)
						{
							vis[i + dx[k]][j + dy[k]] = 1;
							cnt ++;
						}
					if (cnt % 2)
						odd ++;
					else
						even ++;
					for (k = 1; k <= 8; k ++)
						if (inside(i + dx[k], j + dy[k]))
							vis[i + dx[k]][j + dy[k]] = 0;
				}
				
		printf("Case %d: %d %d\n", test, even, odd);
	}
	
	return 0;
}

	
