#include <stdio.h>
#include <algorithm>

using namespace std;

int x[100100];
long long psum[100100];

inline bool can(int n, int cost, int med) {
    for (int j = med; j <= n; ++j) {
        int i = j - med + 1;
        int m = (i + j) / 2;
        long long c = ((long long) m - i + 1) * x[m] - (psum[m] - psum[i - 1]) + psum[j] - psum[m] - ((long long) j - m) * x[m];
        if (c <= cost)
            return 1;
    }
    return 0;
}

int main() {
    freopen("noname2.in", "r", stdin);
    freopen("noname2.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i)
        psum[i] = psum[i - 1] + x[i];

    int st = 1, dr = n, res;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (can(n, k, med)) {
            st = med + 1;
            res = med;
        } else
            dr = med - 1;
    }
    printf("%d", res);
    return 0;
}
