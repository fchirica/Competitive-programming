#include <stdio.h>

int G[16], x[16], sub[1 << 16];
long long d[16][1 << 16];
int got[1 << 16];

void gen(int mask, int i) {
    ++i;
    for (; i <= x[0]; ++i)
        if ((G[x[i]] & mask) == 0) {
            int nmask = mask ^ (1 << x[i]);
            sub[++sub[0]] = nmask;
            gen(nmask, i);
        }
}

int main() {
    freopen("colorare.in", "r", stdin);
    freopen("colorare.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        --xx; --yy;
        G[xx] |= (1 << yy);
        G[yy] |= (1 << xx);
    }

    d[0][0] = 1;
    got[0] = 1;
    for (int c = 1; c <= n; ++c)
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (got[mask]) {
                d[c][mask] = d[c - 1][mask];
                continue;
            }
            x[0] = 0;
            for (int b = 0; b < n; ++b)
                if (mask & (1 << b))
                    x[++x[0]] = b;
            sub[0] = 0;
            gen(0, 0);
            for (int i = 1; i <= sub[0]; ++i) {
                d[c][mask] += d[c - 1][mask ^ sub[i]];
                got[mask] |= got[mask ^ sub[i]];
            }
            if (d[c][mask] && mask == ((1 << n) - 1))
                break;
        }

    for (int i = 1; i <= n; ++i)
        if (d[i][(1 << n) - 1]) {
            printf("%d %lld", i, d[i][(1 << n) - 1]);
            return 0;
        }

    return 0;
}
