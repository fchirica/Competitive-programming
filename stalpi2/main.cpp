#include <stdio.h>

int x[55], dp[55][10100], Q[10100];
int N, mx;

inline int ab(int X) {
    if (X > 0)
        return X;
    return -X;
}

bool can(int ret, int lim) {
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= mx; ++j)
            dp[i][j] = 400010;
    dp[1][0] = 0;
    for (int i = 2; i <= N; ++i) {
        int p = 1, u = 0;
        for (int j = 0; j <= mx; ++j) {
            while (p <= u && dp[i - 1][j] <= dp[i - 1][Q[u]])
                --u;
            Q[++u] = j;
            dp[i][j] = dp[i - 1][Q[p]];
            if (Q[p] + ret == j)
                ++p;
            dp[i][j] += ab(x[i] - j);
        }
    }
    return dp[N][mx] <= lim;
}

int main() {
    freopen("stalpi2.in", "r", stdin);
    freopen("stalpi2.out", "w", stdout);

    int S;
    scanf("%d%d", &N, &S);
    for (int i = 2; i <= N; ++i)
        scanf("%d", &x[i]);
    mx = x[N];

    can(15, S);

    int st = 0, dr = 10000, ret;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (can(med, S)) {
            ret = med;
            dr = med - 1;
        } else
            st = med + 1;
    }

    printf("%d", ret);
    return 0;
}
