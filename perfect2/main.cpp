#include <stdio.h>
#define LMAX 1 << 10
#define PMAX 10100

int x[LMAX][LMAX], dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
struct position
{
    int x, y;
} pescari[PMAX], Q[LMAX * LMAX];

inline position make_position (int x, int y)
{
    position aux;

    aux.x = x;
    aux.y = y;

    return aux;
}

int main ()
{
    int i, j, d, N, M, P, num = 0, p = 1, u = 0, newx, newy;

    freopen ("pescari.in", "r", stdin);
    freopen ("pescari.out", "w", stdout);

    scanf ("%d %d %d", &N, &M, &P);
    for (i = 1; i <= N; i ++)
        for (j = 1; j <= M; j ++)
        {
            scanf ("%d", &x[i][j]);
            if (x[i][j] == 0)
                x[i][j] = -1;
            if (x[i][j] == 1)
                x[i][j] = -1, pescari[++ num] = make_position(i, j);
            if (x[i][j] == 2)
                x[i][j] = 0, Q[++ u] = make_position (i, j);
        }

    while (p <= u)
    {
        for (d = 0; d <= 7; d ++)
        {
            newx = Q[p].x + dx[d];
            newy = Q[p].y + dy[d];
            if (x[newx][newy] == -1)
            {
                x[newx][newy] = x[Q[p].x][Q[p].y] + 1;
                Q[++ u] = make_position (newx, newy);
            }
        }
        p ++;
    }

    for (i = 1; i <= num; i ++)
        printf ("%d\n", x[pescari[i].x][pescari[i].y]);
    return 0;
}

