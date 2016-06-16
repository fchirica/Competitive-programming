//O (N * M)

#include <stdio.h>

int dp[22][400], memo[22];
bool sgn[22][400];

void solve (int N, int M)
{
    if (N == 1)
    {
        if (dp[1][M] == 0)
            printf ("%d", memo[1]);
        else
            printf ("-%d", memo[1]);
        return ;
    }
    if (dp[N][M] == 0)
    {
        solve (N - 1, M - memo[N]);
        printf ("+%d", memo[N]);
    }
    else
    {
        solve (N - 1, M + memo[N]);
        printf ("-%d", memo[N]);
    }
}

int main ()
{
    int N, M, i, x, low = 180, up = 180, j;

    freopen ("adunscad.in", "r", stdin);
    freopen ("adunscad.out", "w", stdout);

    for (i = 0; i < 400; i ++)
        dp[0][i] = -1;
    dp[0][180] = 0;

    scanf ("%d%d", &M, &N);
    M = M + 180;

    for (i = 1; i <= N; i ++)
    {
        scanf ("%d", &x);
        for (j = 0; j < 400; j ++)
            dp[i][j] = -1;
        for (j = up; j >= low; j --)
            if (dp[i - 1][j] != -1)
            {
                if (x + j < 400)
                    dp[i][x + j] = 0;
                if (j - x >= 0)
                    dp[i][j - x] = 1;
            }
        low = low - x; up = up + x;
        if (low < 0)
            low = 0;
        if (up > 399)
            up = 399;
        memo[i] = x;
    }

    if (dp[N][M] != -1)
        solve (N, M);
    else
        printf ("0\n");
    return 0;
}

