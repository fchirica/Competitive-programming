#include <stdio.h>
#include <string.h>
#define LMAX 1 << 10

bool G[LMAX][LMAX], used[LMAX], blocked[LMAX];

void DF (int x, int N)
{
    int i;

    used[x] = 1;
    for (i = 1; i <= N; i ++)
        if (G[x][i])
            blocked[i] = 1;
    for (i = 1; i <= N; i ++)
        if (!used[i] && blocked[i] == 0)
            DF (i, N);
}

int main ()
{
    int N, M, x, y, i, sol = 0;

    freopen ("exam.in", "r", stdin);
    freopen ("exam.out", "w", stdout);

    scanf ("%d%d", &N, &M);
    for (i = 1; i <= M; i ++)
    {
        scanf ("%d%d", &x, &y);
        G[x][y] = 1;
        G[y][x] = 1;
    }

    for (i = 1; i <= N; i ++)
        if (!used[i])
        {
            memset (blocked, 0, sizeof (blocked));
            sol ++;
            DF(i, N);
        }

    printf ("%d", sol);
    return 0;
}

