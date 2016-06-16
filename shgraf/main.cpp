//bravo wef, vezi ca poti scoate probleme misto fara sa furi de pe alte siteuri ;)

#include <stdio.h>

const int mod = 30011;

int res[300], comb[300][300], cycleDP[300], dp[300][300], pr[300];

int fastPow(int A, int B) {
    if (B == 0)
        return 1;
    int ret = fastPow(A, B / 2);
    ret = ret * ret % mod;
    if (B % 2)
        ret = ret * A % mod;
    return ret;
}

int main() {
    freopen("shgraf.in", "r", stdin);
    freopen("shgraf.out", "w", stdout);

    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i <= N; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            if (comb[i][j] >= mod)
                comb[i][j] -= mod;
        }
    }

    pr[0] = pr[1] = 1;
    for (int i = 2; i <= N; ++i)
        pr[i] = fastPow(i, i - 2);

    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; i + j <= N; ++j)
            for (int k = 0; k <= j; ++k)
                dp[i][j] = (dp[i][j] + 1LL * pr[k + 1] * comb[j][k] * dp[i - 1][j - k]) % mod;

    cycleDP[3] = 1;
    for (int i = 4; i <= N; ++i)
        cycleDP[i] = cycleDP[i - 1] * (i - 1) % mod;

    res[0] = 1;
    for (int i = 3; i <= N; ++i)
        for (int cycle = K; cycle <= i; ++cycle)
            for (int tree = 0; tree + cycle <= i; ++tree) {
                int componentWays = comb[i - 1][cycle + tree - 1];
                int cycleWays = cycleDP[cycle] * comb[cycle + tree][cycle] % mod;
                int treeWays = dp[cycle][tree];
                long long tot = 1LL * componentWays * cycleWays * treeWays * res[i - cycle - tree] % mod;
                res[i] += tot;
                if (res[i] >= mod)
                    res[i] -= mod;
            }

    printf("%d", res[N]);
    return 0;
}
