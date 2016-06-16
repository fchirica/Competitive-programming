#include <stdio.h>
#define MOD 9007

bool is[100001];
int dp[100001];

int main()
{
	int i, N, K;

	freopen("ccount.in", "r", stdin);
	freopen("ccount.out", "w", stdout);

	scanf("%d%d", &N, &K);
	for (i = 1; i <= K; i ++)
	{
		int x;

		scanf("%d", &x);
		is[x] = true;
	}

	for (i = 3; i <= N; i ++)
		if (!is[i])
		{
			dp[i] = dp[i - 1] + dp[i - 2] + 1;
			while (dp[i] >= MOD)
				dp[i] = dp[i] - MOD;
		}

	printf("%d", dp[N]);
	return 0;
}
