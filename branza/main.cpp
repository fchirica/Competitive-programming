#include <stdio.h>
#define NMAX 100100

int Q[NMAX], val[NMAX];

int main()
{
    int i, N, S, T, p = 1, u = 0, C, P;
    long long sol = 0;

    freopen("branza.in", "r", stdin);
    freopen("branza.out", "w", stdout);

    scanf("%d%d%d", &N, &S, &T);
    for (i = 1; i <= N; i++)
    {
        scanf("%d%d", &C, &P);

        val[i] = C - i * S;
        while (p <= u && val[i] <= val[Q[u]])
            u--;
        Q[++ u] = i;

        sol += (long long)P * (val[Q[p]] + i * S);

        if (Q[p] + T == i)
            p ++;
    }

    printf ("%lld", sol);
    return 0;
}
