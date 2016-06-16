#include <stdio.h>
#define LMAX 112

int used[LMAX], mat[LMAX][LMAX], mask[LMAX], dp[1 << 20];

inline int comb (int K, int N, int MOD)
{
    int triangle[LMAX][LMAX];
    int i, j;

    triangle[1][0] = triangle[1][1] = 1;

    for (i = 2; i <= N; i ++)
        for (j = 0; j <= K; j ++)
            triangle[i][j] = (triangle[i - 1][j] + triangle[i - 1][j - 1]) % MOD;

    return triangle[N][K];
}

inline int fact (int N, int MOD)
{
    int i, sol = 1;

    for (i = 2; i <= N; i ++)
        sol = (long long)sol * i % MOD;

    return sol;
}

int main ()
{
    int i, j, N, K, MOD, nowmask, num, x, y;

    freopen ("teroristi2.in", "r", stdin);
    freopen ("teroristi2.out", "w", stdout);

    scanf ("%d%d%d", &N, &K, &MOD);

    for (i = 1; i <= K; i ++)
    {
        scanf ("%d%d", &x, &y);
        used[x] = used[y] = 1;
        mat[y][x] = 1;
    }

    int restricted = -1;

    for (i = 1; i <= N; i ++)
        if (used[i])
        {
            nowmask = num = 0;
            for (j = 1; j <= N; j ++)
            {
                if (mat[i][j])
                    nowmask = nowmask | (1 << num);
                if (used[j])
                    num ++;
            }

            mask[++ restricted] = nowmask;
        }

    dp[0] = 1;
    for (i = 0; i < (1 << (restricted + 1)); i ++)
        if (dp[i])
            for (j = 0; j <= restricted; j ++)
                if (!(i & (1 << j)))
                    if ((i & mask[j]) == mask[j])
                    {
                        dp[i | (1 << j)] += dp[i];
                        dp[i | (1 << j)] %= MOD;
                    }

    int sol = dp[(1 << (restricted + 1)) - 1];

    sol = (long long)sol * comb (restricted + 1, N, MOD) % MOD;
    sol = (long long)sol * fact (N - restricted - 1, MOD) % MOD;

    printf ("%d", sol);

    return 0;
}
