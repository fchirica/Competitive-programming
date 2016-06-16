#include <stdio.h>

int main()
{
	int i, T;
	
	freopen("chocolate.in", "r", stdin);
	freopen("chocolate.out", "w", stdout);
	
	scanf("%d", &T);
	for (i = 1; i <= T; i ++)
	{
		int N, M, X, Y, nim;
		
		scanf("%d%d%d%d", &N, &M, &X, &Y);
		
		nim = (X - 1) ^ (Y - 1) ^ (N - X) ^ (M - Y);
		if (nim > 0)
			nim = 1;
		
		printf("%d\n", nim);
	}
	
	return 0;
}
