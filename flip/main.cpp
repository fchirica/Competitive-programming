#include <stdio.h>

int x[20][20];

int main()
{
	int i, j, mask, N, M;
	int sol = 0, ret, sum;
	
	freopen("flip.in", "r", stdin);
	freopen("flip.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
		{
			scanf("%d", &x[i][j]);
			sol += x[i][j];
		}
		
	for (mask = 0; mask < (1 << M); ++ mask)
	{
		ret = 0;
		for (i = 1; i <= N; i ++)
		{
			sum = 0;
			for (j = 1; j <= M; j ++)
				if (mask & (1 << (j - 1)))
					sum = sum - x[i][j];
				else
					sum = sum + x[i][j];
			if (sum < 0)
				sum = sum * (-1);
			ret += sum;
		}
		
		if (ret > sol)
			sol = ret;
	}
	
	printf("%d", sol);
	return 0;
}
