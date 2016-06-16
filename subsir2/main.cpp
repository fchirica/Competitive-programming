#include <stdio.h>

int x[5100], dp[5100], next[5100];
bool valid[5100];

int main()
{
	int i, j, N, sol = 1 << 30, idxsol = 1 << 30;
	
	freopen("subsir2.in", "r", stdin);
	freopen("subsir2.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		valid[i] = true;
	}
	
	for (i = N; i >= 1; i --)
	{
		int vmin = 1 << 30, idx = -1;
		
		dp[i] = 1 << 30;
		for (j = i + 1; j <= N; j ++)
			if (x[j] >= x[i] && x[j] < vmin)
			{
				valid[j] = false;
				if (dp[j] < dp[i] || (dp[i] == dp[j] && x[j] < x[idx]))
					dp[i] = dp[j], idx = j;
				vmin = x[j];
			}
		
		if (dp[i] == 1 << 30)
			dp[i] = 0;
		dp[i] ++;
		next[i] = idx;
	}
	
	for (i = 1; i <= N; i ++)
		if (valid[i])
			if (dp[i] < sol || (dp[i] == sol && x[i] < x[idxsol]))
				sol = dp[i], idxsol = i;
			
	printf("%d\n", sol);
	while (idxsol != -1)
	{
		printf("%d ", idxsol);
		idxsol = next[idxsol];
	}
	
	return 0;
}
