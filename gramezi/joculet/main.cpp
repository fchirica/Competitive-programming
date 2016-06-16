#include <stdio.h>
#define LMAX 1 << 11

int max (int a, int b, int c)
{
    int maximum = a;

    if (b > maximum)
        maximum = b;
    if (c > maximum)
        maximum = c;

    return maximum;
}

int x[LMAX], dp[3][LMAX];

int main ()
{
    int i, N, j, val1, val2, val3;

    freopen ("joculet.in", "r", stdin);
    freopen ("joculet.out", "w", stdout);

    scanf ("%d", &N);
    for (i = 1; i <= N; i ++)
        scanf ("%d", &x[i]);

    for (i = 1; i <= N; i ++)
        dp[1][i] = x[i];
    for (i = 1; i < N; i ++)
        dp[2][i] = max (x[i] - x[i + 1], x[i + 1] - x[i], x[i] + x[i + 1]);
    for (i = 3; i <= N; i ++)
        for (j = 1; j <= N - i + 1; j ++)
        {
            val1 = x[j] - dp[(i - 1) % 3][j + 1];
            val2 = x[i + j - 1] - dp[(i - 1) % 3][j];
            val3 = x[j] + x[i + j - 1] - dp[(i - 2) % 3][j + 1];
            dp[i % 3][j] = max(val1, val2, val3);
        }

    printf ("%d", dp[N % 3][1]);
    return 0;
}
