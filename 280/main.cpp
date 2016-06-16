#include <stdio.h>

int fw[105][105], sol[105];

int main()
{
	int i, j, k, N, x, y;
	
	scanf("%d", &N);
	if (N == 0)
		return 0;
	
	while (1)
	{
		while (1)
		{
			scanf("%d", &x);
			if (x == 0)
				break;
			while (1)
			{
				scanf("%d", &y);
				if (y == 0)
					break;
				fw[x][y] = 1;
			}
		}
		
		for (k = 1; k <= N; k ++)
			for (i = 1; i <= N; i ++)
				for (j = 1; j <= N; j ++)
					if (fw[i][j] == 0)
						fw[i][j] = fw[i][k] * fw[k][j];
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= N; j ++)
				if (fw[i][j] == 0)
					sol[i] ++;
				
		scanf("%d", &x);
		for (i = 1; i <= x; i ++)
		{
			scanf("%d", &y);
			printf("%d", sol[y]);
			for (j = 1; j <= N; j ++)
				if (fw[y][j] == 0)
					printf(" %d", j);
			printf("\n");
		}
		
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= N; j ++)
				fw[i][j] = 0;
		for (i = 1; i <= N; i ++)
			sol[i] = 0;
		scanf("%d", &N);
		if (N == 0)
			break;
		
	}
	
	return 0;
}
