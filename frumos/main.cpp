#include <stdio.h>

const int kMod = 666013;
const int offset = 26;

int dp[110][110][30][2 * 30];
int psum[110][110][30];

int main() {
    freopen("frumos.in", "r", stdin);
    freopen("frumos.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < 26; ++i)
        dp[1][1][i][0] = 1;

    for (int len = 2; len <= n; ++len)
        for (int g = 1; g <= len; ++g)
            for (int c = 0; c < 26; ++c) {
                for (int c2 = 0; c2 < 26; ++c2)
                    if (c != c2) {
                        dp[len][g][c][0] = (dp[len][g][c][0] + psum[len - 1][g - 1][c2]) % kMod;
                        dp[len][g][c][0] = (dp[len][g][c][0] - dp[len - 1][g - 1][c2][c - c2 + offset] + kMod) % kMod;
                    }
                for (int c2 = 0; c2 < 26; ++c2)
                    if (c != c2){
                        int rat = c - c2 + offset;
                        dp[len][g][c][rat] = (dp[len][g][c][rat] + dp[len - 1][g][c2][rat] + dp[len - 1][g][c2][0]) % kMod;
                        psum[len][g][c] = (psum[len][g][c] + dp[len][g][c][rat]) % kMod;
                    }
            }

    int res = 0;
    for (int i = 0; i < 26; ++i)
        res = (res + psum[n][k][i] + dp[n][k][i][0]) % kMod;
    printf("%d", res);
    return 0;
}
