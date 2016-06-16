#include <bits/stdc++.h>

using namespace std;

const int kNMax = 10010;
const int kKMax = 1010;

int n, k;
int x[kNMax];
int dp[2][kNMax], best[2][kNMax], bestSuffix[kNMax];

void init() {
    for (int i = 1; i <= n; ++i)
        dp[1][i] = x[i] + max(dp[1][i - 1], 0);
}

void init2() {
    for (int i = 1; i <= n; ++i)
        dp[1][i] = x[i] + dp[1][i - 1];
    int sum = 0;
    for (int i = n; i >= 1; --i) {
        sum += x[i];
        bestSuffix[i] = max(sum, bestSuffix[i + 1]);
    }
}

void solve() {
    best[1][1] = dp[1][1];
    for (int i = 2; i <= n; ++i)
        best[1][i] = max(best[1][i - 1], dp[1][i]);

    for (int i = 2; i <= k; ++i) {
        for (int j = 1; j < i; ++j)
            best[i % 2][j] = dp[i % 2][j] = -1000000;
        for (int j = i; j <= n; ++j) {
            dp[i % 2][j] = x[j] + max(dp[i % 2][j - 1], best[(i - 1) % 2][j - 1]);
            best[i % 2][j] = max(dp[i % 2][j], best[i % 2][j - 1]);
        }
    }
}

int main() {
    freopen("ferma.in", "r", stdin);
    freopen("ferma.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    init();
    solve();
    int res = best[k % 2][n];
    init2();
    solve();
    for (int i = 1; i <= n; ++i)
        if (best[k % 2][i] + bestSuffix[i + 1] > res)
            res = best[k % 2][i] + bestSuffix[i + 1];
    printf("%d", res);
    return 0;
}
