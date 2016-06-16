#include <stdio.h>

int main()
{
	int N;
	
	scanf("%d", &N);
	for (i = 1; ; i ++)
	{
		if (i % 2 == 0)
		{
			maxCap = (i / 2) * i;
			if (N <= maxCap && N % 2)
				return i;
		}
		