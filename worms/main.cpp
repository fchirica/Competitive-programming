#include <stdio.h>
#define low(X) (lim * (X - 1) + 1)
#define up(X) (lim * X)

int lim;
int x[50500];
int allEqual[50500];

int getBucket(int xx) {
    if (xx % lim == 0)
        return xx / lim;
    return xx / lim + 1;
}

void update(int xx, int yy, int val) {
    for (int i = getBucket(xx); i <= getBucket(yy); ++i)
        if (xx <= low(i) && up(i) <= yy)
            allEqual[i] = val;
        else {
            if (allEqual[i] != -1)
                for (int j = low(i); j <= up(i); ++j)
                    x[j] = allEqual[i];
            for (int j = low(i); j <= up(i); ++j)
                if (xx <= j && j <= yy)
                    x[j] = val;
            int eq = x[low(i)];
            for (int j = low(i) + 1; j <= up(i); ++j)
                if (x[j] != eq)
                    eq = -1;
            allEqual[i] = eq;
        }
}

int main() {
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (lim = 1; lim * lim <= n; ++lim); --lim;

    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int xx, yy, val;
            scanf("%d%d%d", &xx, &yy, &val);
            update(xx, yy, val);
        } else {
            int idx;
            scanf("%d", &idx);
            int lf = 1, rt = n;
            if (allEqual[getBucket(idx)] != -1)
                for (int i = low(getBucket(idx)); i <= up(getBucket(idx)); ++i)
                    x[i] = allEqual[getBucket(idx)];
            for (int i = idx; i >= low(getBucket(idx)); --i)
                if (x[i] != x[idx]) {
                    lf = i + 1;
                    break;
                }
            for (int i = getBucket(idx) - 1; i >= 1 && lf == 1; --i)
                if (allEqual[i] != x[idx])
                    for (int j = up(i); j >= low(i); --j)
                        if (x[j] != x[idx]) {
                            lf = j + 1;
                            break;
                        }
            for (int i = idx; i <= up(getBucket(idx)); ++i)
                if (x[i] != x[idx]) {
                    rt = i - 1;
                    break;
                }
            for (int i = getBucket(idx) + 1; rt == n && low(i) <= n; ++i)
                if (allEqual[i] != x[idx])
                    for (int j = low(i); j <= up(i); ++j)
                        if (x[j] != x[idx]) {
                            rt = j - 1;
                            break;
                        }
            printf("%d %d %d\n", x[idx], lf, rt);
        }
    }

    return 0;
}
