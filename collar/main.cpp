#include <stdio.h>

const int NMAX = 66000;

int x[2 * NMAX], dmin[2 * NMAX], dmax[2 * NMAX];
long long ans = 0, startPos[NMAX];

void solve(int n, int len) {
    int intervals = n / len;
    for (int i = 1; i <= n; ++i)
        startPos[i] = 0;
    for (int inter = 1; inter <= intervals; ++inter) {
        int pmax = 1, umax = 0, pmin = 1, umin = 0, processed = 0;
        for (int j = len * (inter - 1) + 1; processed <= 2 * len - 1; ++j) {
            int val = x[j];
            while (pmin <= umin && x[dmin[umin]] >= val)
                --umin;
            while (pmax <= umax && x[dmax[umax]] <= val)
                --umax;
            dmin[++umin] = j;
            dmax[++umax] = j;
            if (dmin[pmin] + len == j)
                ++pmin;
            if (dmax[pmax] + len == j)
                ++pmax;
            ++processed;
            if (processed >= len)
                startPos[processed - len + 1] += x[dmax[pmax]] - x[dmin[pmin]];
        }
    }
    for (int i = 1; i <= len; ++i)
        if (startPos[i] > ans)
            ans = startPos[i];
}

int main() {
    freopen("collar.in", "r", stdin);
    freopen("collar.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    for (int i = n + 1; i <= 2 * n; ++i)
        x[i] = x[i - n];

    for (int d = 1; d * d <= n; ++d)
        if (n % d == 0) {
            solve(n, d);
            solve(n, n / d);
        }

    printf("%lld", ans);
    return 0;
}
