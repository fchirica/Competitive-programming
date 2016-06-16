#include <stdio.h>
#define LMAX 210

char x[LMAX][LMAX];

int dx1[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy1[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, now;

void DF1 (int x0, int y0)
{
    int d;

    x[x0][y0] = 'Z';
    for (d = 0; d <= 3; d ++)
        if (x[x0 + dx[d]][y0 + dy[d]] == 'C')
            DF1 (x0 + dx[d], y0 + dy[d]);
}

void DF2 (int x0, int y0)
{
    int d;

    x[x0][y0] = 'Z';
    now ++;
    for (d = 0; d <= 3; d ++)
        if (x[x0 + dx[d]][y0 + dy[d]] == 'P')
            DF2 (x0 + dx[d], y0 + dy[d]);
}

int main ()
{
    int N, M, i, j, num = 0, k, out;

    freopen ("oras1.in", "r", stdin);
    freopen ("oras1.out", "w", stdout);

    scanf ("%d%d\n", &N, &M);
    for (i = 1; i <= N; i ++)
        gets (x[i] + 1);
    for (i = 0; i <= N; i ++)
        x[i][0] = x[i][M + 1] = '.';
    for (i = 0; i <= M; i ++)
        x[0][i] = x[N + 1][i] = '.';
    for (i = 1; i <= N; i ++)
        for (j = 1; j <= M; j ++)
        {
            if (x[i][j] == '.')
                continue;
            out = 0;
            for (k = 0; k < 8; k ++)
                if (x[i + dx1[k]][j + dy1[k]] == '.')
                {
                    num ++;
                    break;
                }
        }
    printf ("%d ", num);

    num = 0;
    for (i = 1; i <= N; i ++)
        for (j = 1; j <= M; j ++)
            if (x[i][j] == 'C')
                DF1 (i, j), num ++;
    printf ("%d ", num);

    num = 0;
    for (i = 1; i <= N; i ++)
        for (j = 1; j <= M; j ++)
            if (x[i][j] == 'P')
            {
                now = 0;
                DF2(i, j);
                if (now > num)
                    num = now;
            }
    printf ("%d", num);
    return 0;
}
