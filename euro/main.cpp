#include <stdio.h>
#include <math.h>

long long S[35000], dp[35000];
int Q[35000];
const long long INF = 1LL << 55;

struct convexHullTrick {
    long long m, n;

    convexHullTrick() {
        m = 0;
        n = 0;
    };

    convexHullTrick(long long _m, long long _n) {
        m = _m;
        n = _n;
    }

    long long get(int x) {
        return m * x + n;
    }

    long long better(convexHullTrick other) {
        if (m > other.m)
            return INF;
        if (m == other.m)
            return n < other.n ? -INF : INF;
        return ceil((double)(n - other.n) / (other.m - m));
    }
} L[35000];

int main() {
    freopen("euro.in", "r", stdin);
    freopen("euro.out", "w", stdout);

    int N, T;
    scanf("%d%d", &N, &T);
    for (int i = 1; i <= N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        S[i] = S[i - 1] + tmp;
    }

    int p = 1, u = 1;
    Q[1] = 0;
    for (int i = 1; i <= N; ++i) {
        while (p < u && L[Q[p]].better(L[Q[p + 1]]) <= i)
            ++p;
        dp[i] = L[Q[p]].get(i) + i * S[i] - T;
        L[i] = convexHullTrick(-S[i], dp[i]);
        while (p < u && L[Q[u]].better(L[i]) <= L[Q[u - 1]].better(L[Q[u]]))
            --u;
        Q[++u] = i;
    }

    printf("%lld", dp[N]);
    return 0;
}
