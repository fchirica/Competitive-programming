#include <stdio.h>
#define NMAX 40100

int N, S[NMAX];

int getDigitSum (int x)
{
    int sum = 0;

    while (x)
    {
        sum = sum + x % 10;
        x = x / 10;
    }

    return sum;
}

void ComputeSums ()
{
    int i;

    for (i = 1; i <= N; i ++)
        S[i] = S[i - 1] + getDigitSum (i);
}

inline int suma (int x, int y)
{
    return S[y] - S[x - 1];
}

int solve (int x, int y)
{
    int i, sum = 0, first, left;

    for (i = 1; i <= x; i ++)
    {
        first = N - i + 2;
        if (first == N + 1)
        {
            sum = sum + suma (1, y);
            continue;
        }
        if (N - first + 1 <= y)
        {
            sum = sum + suma (first, N);
            left = y - i + 1;
            sum = sum + suma (1, left);
        }
        else
            sum = sum + suma (first, first + y - 1);
    }

    return sum;
}

int main ()
{
    int x0, y0, x1, y1;

    freopen ("piata.in", "r", stdin);
    freopen ("piata.out", "w", stdout);

    scanf ("%d%d%d%d%d", &N, &x0, &y0, &x1, &y1);
    ComputeSums ();

    printf ("%d", solve (x1, y1) - solve (x0 - 1, y1) - solve (x1, y0 - 1) + solve (x0 - 1, y0 - 1));
    return 0;
}

