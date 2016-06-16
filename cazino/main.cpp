#include <stdio.h>

int main()
{
	int i, T;
	
	freopen("cazino.in", "r", stdin);
	freopen("cazino.out", "w", stdout);
	
	scanf("%d", &T);
	for (i = 1; i <= T; i ++)
	{
		int X, Y, ret;
		double sol;
		
		scanf("%d%d", &X, &Y);
		
		if (X % 2 == 0)
		{
			if (Y % 2 == 0)
				ret = Y / 2;
			else
				ret = Y / 2 + 1;
			X = X / 2;
			sol = (double)X / ret;
		}
		else
		{
			ret = Y / 2;
			X = X / 2;
			sol = (double)X / ret;
		}
		
		printf("%.5lf\n", sol);
	}
	
	return 0;
}
