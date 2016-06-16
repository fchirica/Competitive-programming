#include <stdio.h>

int x[310][310], memo[310][310], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

inline bool valid(int x0, int y0, int N)
{
	return x0 > 0 && y0 > 0 && x0 <= N && y0 <= N;
}

int solve(int x0, int y0)
{
	if (memo[x0][y0] != 1 << 30)
		return memo[x0][y0];
	
	bool hasAscensor = false;
	
	int d;
	
	memo[x0][y0] = 0;
	for (d = 0; d <= 3; d ++)
		if (x[x0 + dx[d]][y0 + dy[d]] > x[x0][y0])
		{
			hasAscensor = true;
			memo[x0][y0] += solve(x0 + dx[d], y0 + dy[d]);
		}
		
	if (hasAscensor == false)
		memo[x0][y0] = 1;
	return memo[x0][y0];
}

int main()
{
	int i, j, d, N;
	
	freopen("drumuri1.in", "r", stdin);
	freopen("drumuri1.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
		{
			scanf("%d", &x[i][j]);
			memo[i][j] = 1 << 30;
		}
	
	int tot = 0;
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
		{
			bool capat = true;
			for (d = 0; d < 4; d ++)
				if (x[i][j] > x[i + dx[d]][j + dy[d]] && valid(i + dx[d], j + dy[d], N))
					capat = false;
			if (capat)
				tot += solve(i, j);
		}
	
	printf("%d", tot);
	return 0;
}
