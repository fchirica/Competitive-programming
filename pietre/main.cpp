#include <stdio.h>

int wythoff[1000100];

int main()
{
	int i, diff = 1;
	
	freopen("pietre.in", "r", stdin);
	freopen("pietre.out", "w", stdout);
	
	for (i = 1; i <= 1000001; i ++)
		if (wythoff[i] == 0)
		{
			wythoff[i] = i + diff;
			if (i + diff <= 1000000)
				wythoff[i + diff] = i;
			++ diff;
		}
		
	int T, x0, y0;
	
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d%d", &x0, &y0);
		
		if (wythoff[x0] == y0)
			printf("2");
		else
			printf("1");
		printf("\n");
	}
	
	return 0;
}
