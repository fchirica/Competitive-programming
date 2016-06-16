#include <stdio.h>
#include <string.h>

long long dp[4][64];
char x[1000100];

int main() {
    freopen("decupare.in", "r", stdin);
    freopen("decupare.out", "w", stdout);

    int i, j, N, K, LIM = 63;
    scanf("%d%d\n", &N, &K);
    long long cur = 0, mod = 1;
    for (i = 1; i < K; ++i)
        mod = mod * 10;

    gets(x + 1);
    for (i = 1; i <= N; ++i) {
        if (i > K) {
            int dig = cur / mod;
            cur = cur - dig * mod;
        }
        cur = cur * 10 + x[i] - '0';
        for (j = 1; j <= 3; ++j) {
            dp[j][i & LIM] = dp[j][(i - 1) & LIM];
            if (i < K)
                continue;
            if (dp[j - 1][(i - K) & LIM] + cur > dp[j][i & LIM])
                dp[j][i & LIM] = dp[j - 1][(i - K) & LIM] + cur;
        }
    }

    printf("%lld", dp[3][N & LIM]);
    return 0;
}
