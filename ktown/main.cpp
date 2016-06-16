#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

ll x[3001], sol[3001], vals[3001];

inline ll ab(ll X) {
    if (X > 0)
        return X;
    return -X;
}

inline bool comp(ll A, ll B) {
    return A > B;
}

int main() {
    freopen("ktown.in", "r", stdin);
    freopen("ktown.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int shit;
        scanf("%d", &shit);
        x[i] = shit - ((long long)i - 1) * k;
        vals[i] = x[i];
    }

    sort(vals + 1, vals + n + 1, comp);

    long long best = 0;
    for (int i = 1; i <= n; ++i) {
        sol[i] = vals[1];
        best += ab(x[i] - sol[i]);
    }

    for (int i = 2; i <= n; ++i) {
        int bestPos = -1;
        long long cur = best;
        for (int j = 1; j <= n; ++j) {
            cur = cur - ab(x[j] - sol[j]) + ab(x[j] - vals[i]);
            if (cur < best) {
                best = cur;
                bestPos = j;
            }
        }
        if (bestPos != -1)
            for (int j = 1; j <= bestPos; ++j)
                sol[j] = vals[i];
    }

    printf("%lld", best);
    return 0;
}
