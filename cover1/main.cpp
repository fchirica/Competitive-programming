#include <stdio.h>
#define MOD 10003

int sol = 2;

inline int Pow3 (int exp)
{
    if (exp == 1)
        return 3;
    int now = Pow3 (exp / 2);
    if (exp & 1)
        return (now * now * 3) % MOD;
    else
        return now * now % MOD;
}

int main ()
{
    int N;

    //freopen ("cover1.in", "r", stdin);
    //freopen ("cover1.out", "w", stdout);

    scanf ("%d", &N);

    sol = sol * Pow3 (N - 1) % MOD;
    printf ("%d", sol);
    return 0;
}
