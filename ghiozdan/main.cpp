#include <stdio.h>
#define INF (1 << 30)

int f[210];
int dp[2][80000], ret[2][80000], Q[80000];

void solve(int st, int dr, int G)
{
    if (G == 0)
        return ;
    if (st == dr)
    {
        int amount;

        for (amount = 1; amount <= f[st] && G - st >= 0; amount ++)
        {
            printf("%d\n", st);
            G = G - st;
        }

        return ;
    }

    int med = (st + dr) / 2, i, r, j, act = 0, step;
    int p, u;

    dp[0][0] = 0;
    for (i = 1; i <= G; i ++)
        dp[0][i] = INF;

    for (i = st; i <= dr; i ++)
        if (f[i])
        {
            act = !act;
            for (r = 0; r < i; r ++)
            {
                p = 1; u = 0; step = 0;
                for (j = r; j <= G; j = j + i, ++ step)
                {
                    int now = dp[!act][j] - step;

                    while (p <= u && dp[!act][Q[u]] >= now)
                        u --;
                    Q[++ u] = j; dp[!act][j] = now;

                    dp[act][j] = dp[!act][Q[p]] + step;
                    ret[act][j] = j;
                    if (i > med)
                        ret[act][j] = ret[!act][Q[p]];

                    if (Q[p] + i * f[i] == j)
                        p ++;
                }
            }
        }

    int left;

    for (i = G; i >= 1; i --)
        if (dp[act][i] != INF)
        {
            left = ret[act][i];
            break;
        }

    if (st == 1 && dr == 200)
        printf("%d %d\n", i, dp[act][i]);

    solve(st, med, left);
    solve(med + 1, dr, i - left);
}

int main()
{
    int i, N, G;

    freopen("ghiozdan.in", "r", stdin);
    freopen("ghiozdan.out", "w", stdout);

    scanf("%d%d", &N, &G);
    for (i = 1; i <= N; i ++)
    {
        int x;

        scanf("%d", &x);
        f[x] ++;
    }

    solve(1, 200, G);
    return 0;
}
