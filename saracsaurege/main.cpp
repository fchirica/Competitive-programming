#include <stdio.h>

int x[50500], lg[50500], rm[50500], q[50500];

void recalc(int len, int n) {
    int p = 1, u = 0;
    for (int i = 1; i <= n; ++i) {
        while (p <= u && x[q[u]] <= x[i])
            --u;
        q[++u] = i;
        if (q[p] + len == i)
            ++p;
        if (i >= len)
            rm[i - len + 1] = x[q[p]];
    }
}

int main() {
    freopen("saracsaurege.in", "r", stdin);
    freopen("saracsaurege.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;

    int maxPw = 100;
    while (m--) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        if (maxPw > lg[yy - xx + 1]) {
            maxPw = lg[yy - xx + 1];
            recalc(1 << maxPw, n);
        }
        int len = 1 << maxPw;
        int res = rm[yy - len + 1];
        if (rm[xx] > res)
            res = rm[xx];
        printf("%d\n", res);
    }

    return 0;
}
