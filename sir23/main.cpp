/* problema ol3333mpika */

#include <stdio.h>

const int kNMax = 1001;
const int kMod = 1000000;

int dp[kNMax][kNMax], psum[kNMax][kNMax], dp_aux[kNMax][kNMax];

int main() {
    freopen("sir23.in", "r", stdin);
    freopen("sir23.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = i;
        dp[2][i] = i * i % kMod;
        psum[1][i] = (psum[1][i - 1] + dp[1][i]) % kMod;
        psum[2][i] = (psum[2][i - 1] + dp[2][i]) % kMod;
    }

    for (int i = 3; i <= n; ++i)
        for (int j = 2; j <= n; ++j) {
            dp_aux[i][j] = (dp_aux[i][j - 1] + psum[i - 2][j - 2] + dp[i - 2][j - 1]) % kMod;
            dp[i][j] = (psum[i - 1][j - 1] + dp_aux[i][j]) % kMod;
            psum[i][j] = (psum[i][j - 1] + dp[i][j]) % kMod;
        }

    printf("%d", dp[n][n]);
    return 0;
}
