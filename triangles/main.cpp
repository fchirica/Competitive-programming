#include <stdio.h>
#include <algorithm>

using namespace std;

int x[160100], ind[160100];

inline bool cmp(int A, int B)
{
	return x[A] < x[B];
}

int main()
{
	int i, j, N, K;
	
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	if (N > 160000)
		N = 160000;
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		ind[i] = i;
	}
	
	sort(ind + 1, ind + N + 1, cmp);
	for (i = 1; ; i ++)
		if (x[ind[i]] + x[ind[i + 1]] >= x[ind[i + K - 1]])
		{
			for (j = i; j <= i + K - 1; j ++)
				printf("%d ", ind[j]);
			return 0;
		}
		
	return 0;
}
