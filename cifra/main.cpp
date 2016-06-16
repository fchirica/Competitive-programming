#include <stdio.h>
#include <string.h>

char x[150], sol[150];

int main()
{
	int i, j, T, ret;
	
	freopen("cifra.in", "r", stdin);
	freopen("cifra.out", "w", stdout);
	
	scanf("%d\n", &T);
	
	for (i = 1; i < 100; i ++)
	{
		ret = 1;
		for (j = 1; j <= i; j ++)
			ret = ret * i % 10;
		
		sol[i] = (sol[i - 1] + ret) % 10;
	}
	
	for (i = 1; i <= T; i ++)
	{
		gets(x + 1);
		int N = strlen(x + 1);
		
		if (N == 1)
			ret = x[1] - '0';
		else
			ret = (x[N - 1] - '0') * 10 + x[N] - '0';
		
		printf("%d\n", sol[ret]);
	}
	
	return 0;
}
