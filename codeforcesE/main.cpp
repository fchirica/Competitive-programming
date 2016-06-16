#include <stdio.h>
#include <string.h>

int N, M, now[100][100], best, bestM[100][100], max;
int dx[50][60], dy[50][60];

void PreProcessDir ()
{
    dx[1][1] = -2; dx[1][2] = -2; dx[1][3] = -2; dx[1][4] = -1; dx[1][5] = 0;
    dy[1][1] = -1; dy[1][2] = 0; dy[1][3] = 1; dy[1][4] = 0; dy[1][5] = 0;
    dx[2][1] = 0; dx[2][2] = 1; dx[2][3] = 2; dx[2][4] = 2; dx[2][5] = 2;
    dy[2][1] = 0; dy[2][2] = 0; dy[2][3] = 0; dy[2][4] = -1; dy[2][5] = 1;
    dx[3][1] = 0; dx[3][2] = 1; dx[3][3] = 2; dx[3][4] = 2; dx[3][5] = 2;
    dy[3][1] = 0; dy[3][2] = 0; dy[3][3] = 0; dy[3][4] = -1; dy[3][5] = 1;
    dy[4][1] = 0; dy[4][2] = -1; dy[4][3] = -2; dy[4][4] = -2; dy[4][5] = -2;
    dx[4][1] = 0; dx[4][2] = 0; dx[4][3] = 0; dx[4][4] = -1; dx[4][5] = 1;
}

bool canPlace (int x, int y, int type)
{
    int newx, newy, d;

    for (d = 1; d < 6; d ++)
    {
        newx = x + dx[type][d];
        newy = y + dy[type][d];
        if (newx < 1 || newy < 1 || newx > N || newy > M)
            return false;
        if (now[newx][newy])
            return false;
    }

    return true;
}

void PlaceIt (int x, int y, int type, int value)
{
    int newx, newy, d;

    for (d = 1; d < 6; d ++)
    {
        newx = x + dx[type][d];
        newy = y + dy[type][d];
        now[newx][newy] = value;
    }
}

void RemoveIt (int x, int y, int type)
{
    int newx, newy, d;

    for (d = 1; d < 6; d ++)
    {
        newx = x + dx[type][d];
        newy = y + dy[type][d];
        now[newx][newy] = 0;
    }
}

void ShowMatrix ()
{
    int i, j;

    for (i = 1; i <= N; i ++, printf ("\n"))
        for (j = 1; j <= M; j ++)
            printf ("%d", now[i][j]);
    printf ("\n");
}

void Back (int len, int lasti, int lastj)
{
    int i, j, k;

    if (len > best)
    {
        best = len;
        memcpy (bestM, now, sizeof (now));
    }

    for (k = 1; k <= 4; k ++)
        for (i = lasti; i <= N; i ++)
            for (j = lastj; j <= M; j ++)
                if (canPlace (i, j, k))
                {
                    PlaceIt (i, j, k, len + 1);
                    if (k == 4)
                        ShowMatrix ();
                    Back (len + 1, i, j);
                    RemoveIt (i, j, k);
                }
}

int main ()
{
    int i, j;

    freopen ("E.in", "r", stdin);
    freopen ("E.out", "w", stdout);


    scanf ("%d%d", &N, &M); max = N * M / 5;
    PreProcessDir ();
    if (N >= 3 && M >= 3)
    Back (0, 1, 1);

    printf ("%d\n", best);
    for (i = 1; i <= N; i ++, printf ("\n"))
        for (j = 1; j <= M; j ++)
            if (bestM[i][j] == 0)
                printf (".");
            else
                printf ("%c", (char)bestM[i][j] + 'A' - 1);

    return 0;
}
