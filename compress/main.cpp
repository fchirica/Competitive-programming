#include <stdio.h>
#include <string.h>
#define LMAX 100100

char x[LMAX];

int main()
{
	int i, N, cant, j;
	
	freopen("compress.in", "r", stdin);
	freopen("compress.out", "w", stdout);
	
	gets(x + 1);
	N = strlen(x + 1);
	
	for (i = 1; i <= N; i ++)
	{
		cant = 0;
		for (j = i; j <= N; j ++)
			if (x[i] != x[j])
				break;
			else
				cant ++;
		printf("%c%d", x[i], cant);
		i = j - 1;
	}
	
	return 0;
}
