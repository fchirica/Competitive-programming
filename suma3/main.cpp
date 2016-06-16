#include <stdio.h>
#define MOD 30103

int main ()
{
    int sol = 1, i, N;

    freopen ("scaune.in", "r", stdin);
    freopen ("scaune.out", "w", stdout);

    scanf ("%d", &N);
    for (i = 3; i < 2 * N; i = i + 2)
        sol = sol * i % MOD;

    printf ("%d", sol);
    return 0;
}

