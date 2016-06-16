#include <stdio.h>
#include <string.h>
#define INF (1 << 30)

int x[512][512], a[512][512], L[512], C[512], goodL[512], goodC[512];

int solve(int N, int M)
{
    int i, j;

    for (i = 1; i <= N; i ++)
        for (j = 1; j <= M; j ++)
            a[i][j] = x[i][j];

    for (i = 1; i <= M; i ++)
        if (a[1][i] == 1)
        {
            C[++ C[0]] = i;
            for (j = 1; j <= N; j ++)
                a[j][i] = 1 - a[j][i];
        }

    for (i = 2; i <= N; i ++)
    {
        int one = 0;
        for (j = 1; j <= M; j ++)
            one += a[i][j];
        if (one != 0 && one != M)
            return INF;
        if (one == M)
            L[++ L[0]] = i;
    }

    int ans = L[0], mi = C[0];
    if (C[0] > L[0])
        ans = C[0], mi = L[0];
    if ((ans - mi) % 2)
        return INF;
    return ans;
}

void recon()
{
    int i;

    if (goodL[0] <= goodC[0])
    {
        for (i = 1; i <= goodL[0]; i ++)
            printf("%d %d\n", goodL[i], goodC[i]);
        for (i = goodL[0] + 1; i <= goodC[0]; i ++)
            printf("1 %d\n", goodC[i]);
    }
    else
    {
        for (i = 1; i <= goodC[0]; i ++)
            printf("%d %d\n", goodL[i], goodC[i]);
        for (i = goodC[0] + 1; i <= goodL[0]; i ++)
            printf("%d 1\n", goodL[i]);
    }
}

int main()
{
    int i, j, N, M;

    freopen("becuri.in", "r", stdin);
    freopen("becuri.out", "w", stdout);

    scanf("%d%d", &N, &M);
    for (i = 1; i <= N; i ++)
        for (j = 1; j <= M; j ++)
            scanf("%d", &x[i][j]);

    int best = solve(N, M);
    memcpy(goodL, L, sizeof(goodL));
    memcpy(goodC, C, sizeof(goodC));

    for (i = 1; i <= M; i ++)
        x[1][i] = 1 - x[1][i];
    memset(L, 0, sizeof(L));
    L[0] = L[1] = 1;
    memset(C, 0, sizeof(C));
    int ret = solve(N, M);

    if (ret < best)
    {
        best = ret;
        memcpy(goodL, L, sizeof(goodL));
        memcpy(goodC, C, sizeof(goodC));
    }

    if (best == INF)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n", best);
    recon();

    return 0;
}
