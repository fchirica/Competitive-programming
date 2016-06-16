#include <stdio.h>
#define MOD 1234

int x[1 << 10];

int main ()
{
    int i, N, T, sol = 1;

    freopen ("nrpomi.in", "r", stdin);
    freopen ("nrpomi.out", "w", stdout);

    scanf ("%d%d", &N, &T);
    for (i = 1; i <= N; i ++)
        scanf ("%d", &x[i]);
    x[N + 1] = x[N - 1];

    for (i = 2; i <= N; i = i + 2)
        if (x[i - 1] == x[i + 1])
            sol = sol * (T - 1) % MOD;
        else
            sol = sol * (T - 2) % MOD;

    printf ("%d", sol);
    return 0;
}

