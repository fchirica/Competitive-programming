#include <stdio.h>

int main()
{
	int X, Y, C;
	
	while (1)
	{
		scanf("%d%d%d", &X, &Y, &C);
		if (X == 0 && Y == 0 && C == 0)
			return 0;
		
		X = X - 7; Y = Y - 7;
		if (X * Y % 2 == 0)
			printf("%d\n", X * Y / 2);
		else
			if (C == 1)
				printf("%d\n", X * Y / 2 + 1);
			else
				printf("%d\n", X * Y / 2);
	}
	
	return 0;
}
