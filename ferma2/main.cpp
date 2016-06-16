#include <stdio.h>
#define LMAX 1 << 10

int x[LMAX][LMAX], line[LMAX][LMAX], col[LMAX][LMAX], diag[LMAX][LMAX];

int main ()
{
    int i, j, N, K, sumTot = 0, firstSum = 0, minSum, nowSum;

    freopen ("ferma2.in", "r", stdin);
    freopen ("ferma2.out", "w", stdout);

    scanf ("%d%d", &N, &K);
    K = N - K;

    for (i = 1; i <= N; i ++)
        for (j = 1; j <= i; j ++)
        {
            scanf ("%d", &x[i][j]);
            sumTot = sumTot + x[i][j];
            if (i <= K)
                firstSum = firstSum + x[i][j];
            line[i][j] = line[i][j - 1] + x[i][j];
            col[j][i] = col[j][i - 1] + x[i][j];
            diag[i - j + 1][j] = diag[i - j + 1][j - 1] + x[i][j];
        }

    minSum = firstSum;
    for (i = K + 1; i <= N; i ++)
    {
        firstSum = firstSum - diag[i - K][K] + line[i][K];
        nowSum = firstSum;
        if (firstSum < minSum)
            minSum = firstSum;
        for (j = 2; j <= i - K + 1; j ++)
        {
            nowSum = nowSum - col[j - 1][i] + col[j - 1][i - K];
            nowSum = nowSum + diag[i - (j + K - 1) + 1][j + K - 1] - diag[i - (j + K - 1) + 1][j - 1];
            if (nowSum < minSum)
                minSum = nowSum;
        }
    }

    printf ("%d", sumTot - minSum);
    return 0;
}
