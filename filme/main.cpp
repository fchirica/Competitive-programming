#include <stdio.h>
#include <algorithm>
#define NMAX 10100

using namespace std;

int X[NMAX];

int main()
{
	int i, x, y, N, M;
	
	freopen("filme.in", "r", stdin);
	freopen("filme.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d", &x, &y);
		X[i] = x + y;
	}
	
	sort(X + 1, X + N + 1);
	
	int cant = 0;
	
	for (i = 1; ; i ++)
	{
		cant += X[i];
		if (cant > M)
		{
			printf("%d", i - 1);
			return 0;
		}
	}
	
	printf("%d", N);
	
	return 0;
}
