//O(N^3) 

#include <stdio.h>
#include <string.h>
#define NMAX 112
#define INF (1 << 30)

char x[NMAX], pattern[NMAX][NMAX];
int dp[NMAX], le[NMAX];

inline int min(int A, int B)
{
	return A < B ? A : B;
}

inline bool match(int pos, int target)
{
	int i;
	
	if (pos - le[target] + 1 < 0)
		return false;
	
	for (i = 0; i < le[target]; i ++)
		if (pattern[target][i] != x[pos - le[target] + i + 1])
			return false;
	
	return true;
}

int main()
{
	int N, M, i, j;
	
	freopen("bara.in", "r", stdin);
	freopen("bara.out", "w", stdout);
	
	gets(x + 1);
	N = strlen(x + 1);
	scanf("%d\n", &M);
	for (i = 1; i <= M; i ++)
	{
		gets(pattern[i]);
		le[i] = strlen(pattern[i]);
	}
	
	dp[0] = 0;
	for (i = 1; i <= N; i ++)
		dp[i] = INF;
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			if (match(i, j))
				dp[i] = min(dp[i], dp[i - le[j]] + 1);
	
	printf("%d", dp[N]);
	return 0;
}
