#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int x[2 * 5555], good[2 * 5555], y[2 * 5555];
map <int, int> spec;

int dp[3][10001][1001];
int pv[10100], sum[10100], psum[10100];

int main() {
    freopen("mafioti.in", "r", stdin);
    freopen("mafioti.out", "w", stdout);

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &y[i]);
        spec[y[i]] = 1;
    }
    int K = k;
    for (int i = 1; i <= n; ++i)
        y[n + i] = y[i] + k - 1;
    sort(y + 1, y + 2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i)
        if (x[x[0]] != y[i])
            x[++x[0]] = y[i];
    for (int i = 1; i <= x[0]; ++i) {
        good[i] = spec[x[i]];
        psum[i] = psum[i - 1] + good[i];
    }

    int ptr = 0;
    for (int i = 1; i <= x[0]; ++i) {
        while (x[i] - x[ptr + 1] >= K)
            ++ptr;
        pv[i] = ptr;
    }

    dp[0][0][0] = 0;
    for (int j = 1; j <= m; ++j)
        dp[0][0][j] = dp[1][0][j] = dp[2][0][j] = 1000000000;
    for (int i = 1; i <= x[0]; ++i)
        dp[1][i][0] = dp[2][i][0] = 1000000000;

    for (int i = 1; i <= x[0]; ++i)
        for (int j = 1; j <= m; ++j) {
            if (x[i] < K) {
                dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = 1000000000;
                continue;
            }
            dp[1][i][j] = dp[0][pv[i]][max(0, j - (psum[i] - psum[pv[i]]))] + K;
            bool special = psum[i] - psum[i - 1];
            dp[2][i][j] = min(dp[1][i - 1][j - special], dp[2][i - 1][j - special]) + x[i] - x[i - 1];
            dp[0][i][j] = dp[0][i - 1][j];
            dp[0][i][j] = min(dp[0][i][j], dp[1][i][j]);
            dp[0][i][j] = min(dp[0][i][j], dp[2][i][j]);
        }

    printf("%d", dp[0][x[0]][m]);
    return 0;
}
