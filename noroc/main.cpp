#include <stdio.h>

int main()
{
	int X, M;
	
	freopen("noroc.in", "r", stdin);
	freopen("noroc.out", "w", stdout);
	
	scanf("%d%d", &X, &M);
	
	long double prob = (long double)(M - X) / M;
	
	if (prob < 0)
		prob = 0;
	printf("%.7Lf", prob);
	return 0;
}
