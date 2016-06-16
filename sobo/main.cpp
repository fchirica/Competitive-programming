#include <stdio.h>
#include <string.h>

int x[20][1024];
int change[1024], mask[1024], mask2[1024];
int dp[1 << 15], M;

bool cnt(int X)
{
	if ((X & (X - 1)) == 0)
		return 1;
	return 0;
}

int go(int state)
{
	if (dp[state] != -1)
		return dp[state];
	if (cnt(state))
		return dp[state] = 0;
	
	int i, best = 1 << 30;
	
	for (i = 1; i <= M; i ++)
	{
		int ret = 1 << 30, ret2, cur, cur2;
		
		cur = state & mask[i];
		cur2 = state & mask2[i];
		
		if (cur && cur != state)
			ret = go(cur);
		if (cur2 && cur2 != state)
		{
			ret2 = go(cur2);
			if (ret == 1 << 30 || ret2 > ret)
				ret = ret2;
		}
		
		if (ret != 1 << 30)
			ret += change[i];
		if (ret < best)
			best = ret;
	}
	
	return dp[state] = best;
}

int main()
{
	int i, j, N;
	
	freopen("sobo.in", "r", stdin);
	freopen("sobo.out", "w", stdout);
	
	scanf("%d%d\n", &N, &M);
	for (i = 1; i <= N; i ++, scanf("\n"))
		for (j = 1; j <= M; j ++)
		{
			char ch;
			
			scanf("%c", &ch);
			x[i][j] = ch - '0';
		}
		
	for (i = 1; i <= M; i ++)
	{
		scanf("%d", &change[i]);
		for (j = 1; j <= N; j ++)
			if (x[j][i] == 0)
				mask[i] = mask[i] | (1 << (j - 1));
			else
				mask2[i] = mask2[i] | (1 << (j - 1));
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%d", go((1 << N) - 1));
	
	return 0;
}
