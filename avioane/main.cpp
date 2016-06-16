#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

const long long INF = 1LL << 60;

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
} L[100100];
int x[100100], Q[100100];

int main() {
    freopen("avioane.in", "r", stdin);
    freopen("avioane.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    sort(x + 1, x + n + 1);

    long long best = 0;
    int st = 1, dr = 0;
    for (int i = 1; i <= n; ++i) {
        while (st < dr && L[Q[st]].better(L[Q[st + 1]]) <= i)
            ++st;
        long long cur = ((long long)n - i + 1) * x[i] + L[Q[st]].get(i);
        if (cur > best)
            best = cur;
        L[i] = convexHullTrick(x[i], (long long)-i * x[i]);
        while (st < dr && L[Q[dr - 1]].better(L[Q[dr]]) >= L[Q[dr]].better(L[i]))
            --dr;
        Q[++dr] = i;
    }

    printf("%lld", best);
    return 0;
}
