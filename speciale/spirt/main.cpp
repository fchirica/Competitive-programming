#include <stdio.h>
#define MOD 666013

char x[100100];
int dp[100100], st[100100], left[100100], AIB[100100];

inline int lsb(int X)
{
	return X & -X;
}

int query(int X)
{
	int sol = 0;
	
	for (; X > 0; X = X - lsb(X))
		sol += AIB[X];
	
	return sol;
}

void update(int X, int N, int val)
{
	for (; X <= N; X = X + lsb(X))
		AIB[X] = AIB[X] + val;
}

int main()
{
	int N, M, i, sol = 1;
	
	freopen("spirt.in", "r", stdin);
	freopen("spirt.out", "w", stdout);
	
	scanf("%d%d\n", &N, &M);
	gets(x + 1);
	
	int swag = 1LL * (M - 1) * (M - 1) % MOD;
	
	dp[0] = 1;
	for (i = 1; i <= N; i ++)
	{
		dp[i] = (1LL * swag * dp[i - 1] - M + 2) % MOD;
		while (dp[i] < 0)
			dp[i] += MOD;
	}
	
	for (i = 1; i <= N; i ++)
		if (x[i] == '(')
			st[++ st[0]] = i;
		else
			left[i] = st[st[0] --];
		
	for (i = 1; i <= N; i ++)
		if (left[i])
		{
			int len = i - left[i] + 1;
			
			len = len - query(i) + query(left[i] - 1);
			if (len == 2)
				continue;
			
			sol = sol * 1LL * dp[(len - 2) / 2] % MOD;
			update(left[i], N, len - 2);
		}
		
	int line = N - query(N) - 1;
	
	sol = 1LL * sol * M % MOD;
	for (i = 1; i <= line; i ++)
		sol = 1LL * sol * (M - 1) % MOD;
	
	printf("%d", sol);
	return 0;
}
