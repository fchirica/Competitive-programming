#include <stdio.h>

int main()
{
	int i, j, N;
	
	freopen("zaruri.in", "r", stdin);
	freopen("zaruri.out", "w", stdout);
	
	scanf("%d", &N);
	double med = 0, sum1, sum2;
	int n1, n2;
	
	for (i = 1; i <= N; i ++)
	{
		n1 = sum1 = sum2 = n2 = 0;
		for (j = 1; j <= 6; j ++)
			if (j - med > 0.00000001)
			{
				n1 ++;
				sum1 += j;
			}
			else
			{
				n2 ++; 
				sum2 += j;
			}
		med = ((double)n2 / 6) * med + ((double)n1 / 6) * (sum1 / n1);
	}
	
	printf("%.7lf", med);
	return 0;
}
