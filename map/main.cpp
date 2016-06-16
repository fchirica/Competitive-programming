#include <stdio.h>

int a[900][900], sum[900][900];

int get(int x0, int y0, int x1, int y1) {
    return sum[x1][y1] - sum[x0 - 1][y1] - sum[x1][y0 - 1] + sum[x0 - 1][y0 - 1];
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &a[i + N][j + N]);
    for (int i = 1; i <= 3 * N; ++i)
        for (int j = 1; j <= 3 * N; ++j)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    for (int i = 1; i <= N; ++i, printf("\n"))
        for (int j = 1; j <= N; ++j)
            printf("%d ", get(i + N - K, j + N - K, i + N + K, j + N + K));

    return 0;
}
