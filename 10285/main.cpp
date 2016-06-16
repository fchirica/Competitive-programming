#include <stdio.h>

char name[100];
int N, M, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, x[105][105], sol[105][105];

void solve(int x0, int y0, int N, int M)
{
	if (x0 < 1 || y0 < 1 || x0 > N || y0 > M)
		return ;
	if (sol[x0][y0] != -1)
		return ;
	int ret = 0, d;
	
	if (x0 == 3 && y0 == 4)
		printf("");
	
	for (d = 0; d <= 3; d ++)
	{
		if (x[x0][y0] <= x[x0 + dx[d]][y0 + dy[d]])
			continue;
		solve(x0 + dx[d], y0 + dy[d], N, M);
		if (sol[x0 + dx[d]][y0 + dy[d]] > ret)
			ret = sol[x0 + dx[d]][y0 + dy[d]];
	}
	
	sol[x0][y0] = ret + 1;
}

int main()
{
	int i, j, test;
	
	scanf("%d", &test);
	while (test --)
	{
		scanf("\n%s", &name);
		scanf("%d%d", &N, &M);
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= M; j ++)
			{
				scanf("%d", &x[i][j]);
				sol[i][j] = -1;
			}
			
		int ans = 0;
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= M; j ++)
			{
				solve(i, j, N, M);
				if (sol[i][j] > ans)
					ans = sol[i][j];
			}
			
		printf("%s: %d\n", name, ans);
	}
	
	return 0;
}
