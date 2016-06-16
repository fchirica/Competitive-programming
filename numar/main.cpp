#include <stdio.h>

int x[550][550], col = 2;

void Divide (int x0, int y0, int N, int xg, int yg)
{
    int i, j, xc, yc;

    if (N == 2)
    {
        for (i = x0; i <= x0 + 1; i ++)
            for (j = y0; j <= y0 + 1; j ++)
                if (!x[i][j])
                    x[i][j] = col;
        return ;
    }

    xc = x0 + N / 2 - 1; yc = y0 + N / 2 - 1;
    if (xg <= xc && yg <= yc)
    {
        x[xc + 1][yc] = x[xc][yc + 1] = x[xc + 1][yc + 1] = col;
        col ++; Divide (x0, y0, N / 2, xg, yg);
        col ++; Divide (x0, yc + 1, N / 2, xc, yc + 1);
        col ++; Divide (xc + 1, y0, N / 2, xc + 1, yc);
        col ++; Divide (xc + 1, yc + 1, N / 2, xc + 1, yc + 1);
    }
    if (xg <= xc && yg > yc)
    {
        x[xc][yc] = x[xc + 1][yc] = x[xc + 1][yc + 1] = col;
        col ++; Divide (x0, y0, N / 2, xc, yc);
        col ++; Divide (x0, yc + 1, N / 2, xg, yg);
        col ++; Divide (xc + 1, y0, N / 2, xc + 1, yc);
        col ++; Divide (xc + 1, yc + 1, N / 2, xc + 1, yc + 1);
    }
    if (xg > xc && yg <= yc)
    {
        x[xc][yc] = x[xc][yc + 1] = x[xc + 1][yc + 1] = col;
        col ++; Divide (x0, y0, N / 2, xc, yc);
        col ++; Divide (x0, yc + 1, N / 2, xc, yc + 1);
        col ++; Divide (xc + 1, y0, N / 2, xg, yg);
        col ++; Divide (xc + 1, yc + 1, N / 2, xc + 1, yc + 1);

    }
    if (xg > xc && yg > yc)
    {
        x[xc][yc] = x[xc + 1][yc] = x[xc][yc + 1] = col;
        col ++; Divide (x0, y0, N / 2, xc, yc);
        col ++; Divide (x0, yc + 1, N / 2, xc, yc + 1);
        col ++; Divide (xc + 1, y0, N / 2, xc + 1, yc);
        col ++; Divide (xc + 1, yc + 1, N / 2, xg, yg);
    }
}
int main ()
{
    int i, j, N, x0, y0;

    freopen ("pav.in", "r", stdin);
    freopen ("pav.out", "w", stdout);

    scanf ("%d%d%d", &N, &x0, &y0); N = 1 << N;
    x[x0][y0] = 1;

    Divide (1, 1, N, x0, y0);
    for (i = 1; i <= N; i ++, printf ("\n"))
        for (j = 1; j <= N; j ++)
            printf ("%d ", x[i][j] - 1);

    return 0;
}
