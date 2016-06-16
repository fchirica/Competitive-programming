#include <stdio.h>
#include <string.h>
#define NMAX 1000

int A[NMAX], B[NMAX], C[NMAX], AB[NMAX], BC[NMAX], ABC1[NMAX], ABC2[NMAX];

inline int max (int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void ReadHuge (int x[])
{
    char now[NMAX];
    int N, i;

    scanf (" %s ", &now);
    N = strlen (now);
    x[0] = N;
    for (i = 0; i < N; i ++)
        x[i + 1] = now[N - i - 1] - '0';
}

void AddHuge (int sol[], int first[], int second[])
{
    int i, now;

    for (i = 1; i <= max (first[0], second[0]); i ++)
    {
        now = first[i] + second[i];
        do
        {
            sol [++ sol[0]] = now % 10;
            now = now / 10;
        }
        while (now);
    }
}

bool cmp ()
{
    if (ABC1[0] != ABC2[0])
        return 0;
    for (register int i = 1; i <= ABC1[0]; i ++)
        if (ABC1[i] != ABC2[i])
            return 0;
    return 1;
}

int main ()
{
    int i, T;

    freopen ("asociativ.in", "r", stdin);
    freopen ("asociativ.out", "w", stdout);

    scanf ("%d\n", &T);
    while (T --)
    {
        memset (A, 0, sizeof (A));
        memset (B, 0, sizeof (B));
        memset (C, 0, sizeof (C));
        memset (AB, 0, sizeof (AB));
        memset (BC, 0, sizeof (BC));
        memset (ABC1, 0, sizeof (ABC1));
        memset (ABC2, 0, sizeof (ABC2));
        ReadHuge (A);
        ReadHuge (B);
        ReadHuge (C);
        AddHuge (AB, A, B);
        AddHuge (BC, B, C);
        AddHuge (ABC1, AB, C);
        AddHuge (ABC2, BC, A);
        if (cmp ())
            for (i = ABC1[0]; i >= 1; i --)
                printf ("%d", ABC1[i]);
        else
            printf ("0");
        printf ("\n");
    }

    return 0;
}
