#include <stdio.h>
#define INF (1 << 29)

int graf[69][69], rf[69][69];

int main()
{
	int testCases;
	int N, M, i, j, k, x, y;
	
	freopen("rfinv.in", "r", stdin);
	freopen("rfinv.out", "w", stdout);
	
	scanf("%d", &testCases);
	while (testCases --)
	{
		scanf("%d%d", &N, &M);
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= N; j ++)
				graf[i][j] = INF;
		for (i = 1; i <= M; i ++)
		{
			scanf("%d%d", &x, &y);
			graf[x][y] = graf[y][x] = -1;
		}
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= N; j ++)
			{
				scanf("%d", &rf[i][j]);
				if (i == j || graf[i][j] == -1)
					graf[i][j] = rf[i][j];
			}
		for (k = 1; k <= N; k ++)
			for (i = 1; i <= N; i ++)
				for (j = 1; j <= N; j ++)
					if (graf[i][k] + graf[k][j] < graf[i][j])
						graf[i][j] = graf[i][k] + graf[k][j];
		bool isSolution = true;
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= N; j ++)
				if (rf[i][j] != graf[i][j])
					isSolution = false;
		printf("%s\n", isSolution ? "DA" : "NU");
	}
	
	return 0;
}
