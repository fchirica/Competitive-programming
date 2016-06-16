#include <stdio.h>
#define MOD 194767

inline int ab(int X)
{
    if (X > 0)
        return X;
    return -X;
}
 
int dp[2][90000];
 
int main()
{
    int i, j, N, S, lim;
     
    freopen("1-sir.in", "r", stdin);
    freopen("1-sir.out", "w", stdout);
     
    scanf("%d%d", &N, &S);
    S = ab(S);
	lim = N * (N - 1) / 2;
    if (lim < S)
    {
        printf("0");
        return 0;
    }
     
    int sol = 0;
     
    dp[1][0] = 1;
    for (i = 2; i <= N; i ++)
	{
        for (j = 0; j <= lim; j ++)
        {
			dp[i & 1][j] = dp[(i - 1) & 1][j + i - 1] + dp[(i - 1) & 1][ab(j - i + 1)];
			if (dp[i & 1][j] > MOD)
				dp[i & 1][j] -= MOD;
		}
		
		if (i == N)
			sol = dp[i & 1][S];
		for (j = 0; j <= lim; j ++)
			dp[(i - 1) & 1][j] = 0;
	}  
    printf("%d", sol);
    return 0;
}
