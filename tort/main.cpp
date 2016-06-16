#include <stdio.h>

int H1[112], H2[112], sum[112], ans[112];

inline int max (int a, int b)
{
    return a > b ? a : b;
}

void Prod (int x[], int X)
{
    int i;
    long long tr = 0;

    for (i = 1; i <= x[0]; i ++)
    {
        tr = tr + (long long)x[i] * X;
        x[i] = tr % 10;
        tr = tr / 10;
    }

    while (tr)
    {
        x[++ x[0]] = tr % 10;
        tr = tr / 10;
    }
}

void Div2 ()
{
    int i, st = 1, dr = sum[0], aux, r = 0;

    while (st <= dr)
    {
        aux = sum[st];
        sum[st] = sum[dr];
        sum[dr] = aux;
        st ++;
        dr --;
    }

    if (sum[1] == 1)
        r = 1, i = 2;
    else
        r = 0, i = 1;
    for (; i <= sum[0]; i ++)
    {
        r = r * 10 + sum[i];
        ans[++ ans[0]] = r / 2;
        r = r % 2;
    }
}

void Add ()
{
    int i, tr = 0;

    sum[0] = max (H1[0], H2[0]);
    for (i = 1; i <= sum[0]; i ++)
    {
        sum[i] = H1[i] + H2[i] + tr;
        tr = sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
    if (tr)
        sum[++ sum[0]] = 1;
}

int main ()
{
    int i, A, B;

    freopen ("tort.in", "r", stdin);
    freopen ("tort.out", "w", stdout);

    scanf ("%d%d", &A, &B);
    H1[0] = H1[1] = H2[0] = H2[1] = 1;
    Prod (H1, A + 1);
    Prod (H1, B);
    Prod (H1, B + 1);
    Prod (H2, A + 2);
    Prod (H2, A + 1);
    Prod (H2, B + 1);
    Add ();
    Div2 ();

    for (i = 1; i <= ans[0]; i ++)
        printf ("%d", ans[i]);
    return 0;
}

