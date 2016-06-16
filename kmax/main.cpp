#include <stdio.h>

int dp[310][310], C[310][310], sol[310];

int main() {
    freopen("kmax.in", "r", stdin);
    freopen("kmax.out", "w", stdout);

    int N, K, mod;
    scanf("%d%d%d", &N, &K, &mod);

    for (int i = 0; i <= N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if (C[i][j] >= mod)
                C[i][j] -= mod;
        }
    }
    sol[0] = 1;
    for (int i = 0; i <= N; ++i)
        dp[0][i] = 1;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= K && j <= i; ++j) {
            for (int k = 1; k < i; ++k) {
                int tmp = C[i - 1][k - 1];
                tmp = tmp * sol[k - 1] % mod;
                tmp = tmp * dp[i - k][j] % mod;
                dp[i][j] += tmp;
                if (dp[i][j] >= mod)
                    dp[i][j] -= mod;
            }
            dp[i][j] += dp[i - 1][j - 1];
            if (dp[i][j] >= mod)
                dp[i][j] -= mod;
            if (j != K) {
                sol[i] += dp[i][j];
                if (sol[i] >= mod)
                    sol[i] -= mod;
            }
        }

    printf("%d", (sol[N] + dp[N][K]) % mod);
    return 0;
}
