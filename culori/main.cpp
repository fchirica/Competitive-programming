#include <stdio.h>
#define MOD 9901

int dp[600][600], X[600];

int main()
{
    int N, i, x, y, lg;

    freopen("culori.in", "r", stdin);
    freopen("culori.out", "w", stdout);

    scanf("%d", &N); N = 2 * N - 1;
    for (i = 1; i <= N; i ++)
    {
        scanf("%d", &X[i]);
        dp[i][i] = 1;
    }

    for (lg = 3; lg <= N; lg += 2)
        for (x = 1; x <= N - lg + 1; x ++)
        {
            y = x + lg - 1;
            if (X[x] != X[y])
                continue;
            for (i = x + 1; i <= y; i ++)
                if (X[x + 1] == X[i])
                {
                    dp[x][y] += dp[x + 1][i] * dp[i + 1][y];
                    dp[x][y] %= MOD;
                }
        }

    printf("%d", dp[1][N]);
    return 0;
}

