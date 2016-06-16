#include <stdio.h>

int N, cap, x[20], dp[1 << 17], dp2[1 << 17];

void set()
{
	int i;
	
	for (i = 0; i < (1 << N); i ++)
		dp[i] = dp2[i] = 0;
}

void update(int where, int val1, int val2)
{
	if (dp[where] > val1)
	{
		dp[where] = val1; dp2[where] = val2;
		return ;
	}
	if (dp[where] == val1 && dp2[where] < val2)
		dp[where] = val1, dp2[where] = val2;
}

void solve()
{
	int mask, b;
	
	for (mask = 1; mask < (1 << N); mask ++)
		dp[mask] = 1 << 30;
	for (mask = 0; mask < (1 << N); mask ++)
		for (b = 0; b < N; b ++)
			if ((mask & (1 << b)) == 0)
			{
				if (x[b] <= dp2[mask])
					update(mask | (1 << b), dp[mask], dp2[mask] - x[b]);
				else
					update(mask | (1 << b), dp[mask] + 1, cap - x[b]);
			}
}

int main()
{
	int test, i;
	
	freopen("zebughil.in", "r", stdin);
	freopen("zebughil.out", "w", stdout);
	
	for (test = 1; test <= 3; test ++)
	{
		scanf("%d%d", &N, &cap); 
		for (i = 0; i < N; i ++)
			scanf("%d", &x[i]);
		
		solve();
		printf("%d\n", dp[(1 << N) - 1]);
		set(); 
	}
	
	return 0;
}
