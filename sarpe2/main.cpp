#include <stdio.h>
#define LMAX 100100
#define NMAX 1024
#define MOD 666013

int pos[LMAX], x[LMAX], a[NMAX][NMAX], sol[NMAX][NMAX], dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1}, ways, M;

int DF (int i, int j)
{
    int d, now = 0, last;

    if (sol[i][j] != -1)
        return sol[i][j];
    if (pos[a[i][j]] == 0)
    {
        sol[i][j] = 0;
        return 0;
    }
    last = x[pos[a[i][j]] - 1];
    if (last == 1 << 30)
    {
        sol[i][j] = 1;
        return sol[i][j];
    }
    for (d = 0; d < 8; d ++)
        if (a[i + dx[d]][j + dy[d]] == last)
            now = (now + DF (i + dx[d], j + dy[d])) % MOD;

    sol[i][j] = now;
    if (pos[a[i][j]] == M)
        ways = (ways + now) % MOD;
    return sol[i][j];
}

int main ()
{
    int N, i, j, ret;

    freopen ("sarpe2.in", "r", stdin);
    freopen ("sarpe2.out", "w", stdout);

    scanf ("%d%d", &N, &M);
    for (i = 1; i <= M; i ++)
    {
        scanf ("%d", &x[i]);
        pos[x[i]] = i;
    }

    for (i = 1; i <= N; i ++)
        for (j = 1; j <= N; j ++)
        {
            scanf ("%d", &a[i][j]);
            sol[i][j] = -1;
        }

    for (i = 0; i <= N; i ++)
        sol[i][0] = sol[0][i] = sol[N + 1][i] = sol[i][N + 1] = 0;
    x[0] = 1 << 30;

    for (i = 1; i <= N; i ++)
        for (j = 1; j <= N; j ++)
            ret = DF (i, j);

    printf ("%d", ways);
    return 0;
}

