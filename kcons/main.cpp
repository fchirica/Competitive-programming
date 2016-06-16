#include <stdio.h>

int a[2001][2001], b[2001][2001];
const int mod = 30013;

inline int max(int A, int B) {
    return A > B ? A : B;
}

int main() {
    freopen("kcons.in", "r", stdin);
    freopen("kcons.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);

    a[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long sum = a[i - 1][j - 1] + (j + 1) * a[i - 1][j + 1] + (i - j - 1) * a[i - 1][j];
            a[i][j] = sum % mod;
        }
        a[i][0] = (a[i - 1][1] + (i - 1) * a[i - 1][0]) % mod;
    }

    for (int i = 1; i <= k; ++i)
        b[i][1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= i; ++j)
            b[i][j] = (b[i - 1][j] + b[i - 1][j - 1] - b[max(i - k - 1, 0)][j - 1] + mod) % mod;

    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + a[i][0] * b[n][i]) % mod;

    printf("%d", res);
    return 0;
}
