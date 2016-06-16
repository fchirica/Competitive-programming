#include <stdio.h>
#define MOD 3210121

int N, K, S, x[25][35], dp[35][10100], st[25], food[35], sol = 0;

void back(int lev)
{
    int i, j;
    int lastFood[35];

    for (i = 1; i <= K; i ++)
        lastFood[i] = food[i];

    for (i = st[lev - 1] + 1; i <= N; i ++)
    {
        st[lev] = i;
        for (j = 1; j <= K; j ++)
            if (x[i][j] > food[j])
                food[j] = x[i][j];

        int ret = S;
        for (j = 1; j <= K; j ++)
            ret = ret - food[j];
        if (ret >= 0)
        {
            if (lev % 2)
                sol = (sol + dp[K][ret]) % MOD;
            else
                sol = (sol - dp[K][ret] + MOD) % MOD;
        }
        back(lev + 1);
        for (j = 1; j <= K; j ++)
            food[j] = lastFood[j];
    }
}

int main()
{
    int i, j;

    freopen("cowfood.in", "r", stdin);
    freopen("cowfood.out", "w", stdout);

    scanf("%d%d%d", &K, &S, &N);
    for (i = 1; i <= N; i ++)
        for (j = 1; j <= K; j ++)
            scanf("%d", &x[i][j]);

    for (i = 0; i <= K; i ++)
        for (j = 0; j <= S; j ++)
        {
            if (i == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j];
            if (j)
                dp[i][j] += dp[i][j - 1];
            if (dp[i][j] >= MOD)
                dp[i][j] = dp[i][j] - MOD;
        }

    back(1);
    sol = dp[K][S] - sol;
    sol = sol - S * K - 1;
    while (sol < 0)
        sol += MOD;
    printf("%d", sol);
    return 0;
}
