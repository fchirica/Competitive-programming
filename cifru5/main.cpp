#include <stdio.h>
#include <string.h>

char x[11111];
int curF[10], F[10], fact[10100];
int dp[10][10100];

const int mod = 30313;

int fastPow(int A, int B) {
    if (B == 0)
        return 1;
    int ret = fastPow(A, B / 2);
    ret = (long long)ret * ret % mod;
    if (B & 1)
        ret = (long long)ret * A % mod;
    return ret;
}

int invers(int X) {
    return fastPow(X, mod - 2);
}

int main() {
    freopen("cifru5.in", "r", stdin);
    freopen("cifru5.out", "w", stdout);

    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= 9; ++i)
        F[i] = 1 << 30;
    for (int i = 1; i <= n; ++i) {
        gets(x + 1);
        int len = strlen(x + 1);
        memset(curF, 0, sizeof(curF));
        for (int j = 1; j <= len; ++j)
            ++curF[x[j] - '0'];
        for (int j = 1; j <= 9; ++j)
            if (curF[j] < F[j])
                F[j] = curF[j];
    }

    int maxL = 0;
    for (int i = 1; i <= 9; ++i)
        maxL += F[i];
    fact[0] = 1;
    for (int i = 1; i <= maxL; ++i)
        fact[i] = (long long)fact[i - 1] * i % mod;

    int maxRes = fact[maxL];
    for (int i = 1; i <= 9; ++i)
        maxRes = (long long)maxRes * invers(fact[F[i]]) % mod;

    for (int i = 0; i <= 9; ++i)
        dp[i][0] = 1;
    for (int c = 1; c <= 9; ++c)
        for (int i = 1; i <= maxL; ++i) {
            dp[c][i] += dp[c - 1][i];
            int prod = 1, lim = F[c];
            if (lim > i)
                lim = i;
            for (int take = 1; take <= lim; ++take) {
                prod = prod * (F[c] - take + 1) % mod;
                dp[c][i] += dp[c - 1][i - take] * prod;
                dp[c][i] %= mod;
            }
        }

    int tot = 0, inv = 1;
    for (int i = 0; i < maxL; ++i) {
        tot = (tot + (long long)maxRes * inv * dp[9][i]) % mod;
        inv = (long long)inv * invers(maxL - i) % mod;
    }

    printf("%d", tot);
    return 0;
}
