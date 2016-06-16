#include <stdio.h>

int f[1000100], x[1000100];

int main ()
{
    int N, max = 0, val, i;

    freopen ("mincinosi.in", "r", stdin);
    freopen ("mincinosi.out", "w", stdout);

    scanf ("%d", &N);
    for (i = 1; i <= N; i ++)
    {
        scanf ("%d", &x[i]);
        f[x[i]] ++;
    }

    for (i = 0; i < N; i ++)
        if (i + f[i] == N)
            if (f[i] > max)
                max = f[i], val = i;

    printf ("%d\n", max);
    for (i = 1; i <= N; i ++)
        if (x[i] == val)
            printf ("%d\n", i);

    return 0;
}

