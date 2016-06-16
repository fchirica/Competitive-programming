#include <stdio.h>

int rf[300][300], drum[300][300];

int main()
{
	int i, j, k, N;
	
	freopen("rf.in", "r", stdin);
	freopen("rf.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
		{
			scanf("%d", &rf[i][j]);
			if (i != j)
				drum[i][j] = 1;
		}
		
	for (k = 1; k <= N; k ++)
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= N; j ++)
			{
				bool canChange = 0;
				if (rf[i][j] > rf[i][k] + rf[k][j])
					canChange = 1;
				if (rf[i][j] == rf[i][k] + rf[k][j] && drum[i][j] < drum[i][k] + drum[k][j])
					canChange = 1;
				if (canChange)
				{
					rf[i][j] = rf[i][k] + rf[k][j];
					drum[i][j] = drum[i][k] + drum[k][j];
				}
			}
			
	for (i = 1; i <= N; i ++, printf("\n"))
		for (j = 1; j <= N; j ++)
			printf("%d ", rf[i][j]);
	for (i = 1; i <= N; i ++, printf("\n"))
		for (j = 1; j <= N; j ++)
			printf("%d ", drum[i][j]);
	return 0;
}
