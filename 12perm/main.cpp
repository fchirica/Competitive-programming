#include <stdio.h>
#define MOD ((1 << 20) - 1)

int dp1[5], dp2[5];

int main()
{
	int i, N;
	
	freopen("12perm.in", "r", stdin);
	freopen("12perm.out", "w", stdout);
	
	scanf("%d", &N); N --;
	dp1[0] = 1; dp1[1] = 2; dp1[2] = 4; dp1[3] = 8;
	dp2[0] = 0; dp2[1] = 0; dp2[2] = 2; dp2[3] = 4;
	
	for (i = 4; i <= N; i ++)
	{
		dp1[i % 4] = (dp1[(i - 1) % 4] + dp1[(i - 3) % 4] + 2) & MOD;
		dp2[i % 4] = (dp2[(i - 1) % 4] + dp1[(i - 2) % 4]) & MOD;
	}
	
	printf("%d", (dp1[N % 4] + dp2[N % 4]) & MOD);
	return 0;
}

	