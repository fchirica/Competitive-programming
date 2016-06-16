#include <stdio.h>
#include <algorithm>

using namespace std;

int sol[1024], x[1024];
bool sum[501000];

int main()
{
	int N, vmax = -1, i, j;
	
	freopen("economie.in", "r", stdin);
	freopen("economie.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		if (x[i] > vmax)
			vmax = x[i];
	}
	
	sort(x + 1, x + N + 1);
	sum[0] = true;
	
	for (i = 1; i <= N; i ++)
		if (sum[x[i]] == false)
		{
			sol[++ sol[0]] = x[i];
			for (j = 0; j + x[i] <= vmax; j ++)
				if (sum[j])
					sum[j + x[i]] = true;
		}
		
	for (i = 0; i <= sol[0]; i ++)
		printf("%d\n", sol[i]);
	return 0;
}
