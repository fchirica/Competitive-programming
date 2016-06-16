#include <stdio.h>
#include <string.h>

char x[112];
int dp1[112], dp2[112];

inline int min(int A, int B)
{
	return A < B ? A : B;
}

inline int max(int A, int B)
{
	return A > B ? A : B;
}

int main()
{
	int i, N;
	
	freopen("rle-size.in", "r", stdin);
	freopen("rle-size.out", "w", stdout);
	
	scanf("%d\n", &N);
	for (i = 1; i <= N; i ++)
		scanf("%c", &x[i]);
	
	for (i = 1; i <= N; i ++)
	{
		if (x[i] == '?')
		{
			if (i == 1)
			{
				dp1[i] = dp2[i] = 1;
				continue;
			}
			dp1[i] = min(dp1[i - 1], dp2[i - 1] + 1);
			dp2[i] = min(dp1[i - 1] + 1, dp2[i - 1]);
		}
		if (x[i] == '+')
		{
			if (i == 1)
			{
				dp1[i] = 1 << 30; dp2[i] = 1;
				continue;
			}
			dp2[i] = min(dp2[i - 1], dp1[i - 1] + 1);
			dp1[i] = 1 << 30;
		}
		if (x[i] == '-')
		{
			if (i == 1)
			{
				dp1[i] = 1; dp2[i] = 1 << 30;
				continue;
			}
			dp1[i] = min(dp1[i - 1], dp2[i - 1] + 1);
			dp2[i] = 1 << 30;
		}
	}
	printf("%d ", min(dp1[N], dp2[N]));
	
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	
	for (i = 1; i <= N; i ++)
	{
		if (x[i] == '?')
		{
			if (i == 1)
			{
				dp1[i] = dp2[i] = 1;
				continue;
			}
			dp1[i] = max(dp1[i - 1], dp2[i - 1] + 1);
			dp2[i] = max(dp1[i - 1] + 1, dp2[i - 1]);
		}
		if (x[i] == '+')
		{
			if (i == 1)
			{
				dp1[i] = -1000; dp2[i] = 1;
				continue;
			}
			dp2[i] = max(dp2[i - 1], dp1[i - 1] + 1);
			dp1[i] = -1000;
		}
		if (x[i] == '-')
		{
			if (i == 1)
			{
				dp1[i] = 1; dp2[i] = -1000;
				continue;
			}
			dp1[i] = max(dp1[i - 1], dp2[i - 1] + 1);
			dp2[i] = -1000;
		}
	}
	printf("%d", max(dp1[N], dp2[N]));
	
	return 0;
}
