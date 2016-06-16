#include <stdio.h>

int G[16], x[16], sub[1 << 16];
bool got[1 << 16];
long long d[16][1 << 16];

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

    for (int mask = 1; mask < (1 << n); ++mask) {
        got[mask] = 1;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i))
                for (int j = 0; j < n; ++j)
                    if (mask & (1 << j))
                        if (G[i] & (1 << j))
                            got[mask] = 0;
    }

    d[0][0] = 1;
    for (int c = 1; c <= n; ++c) {
        for (int mask = 1; mask < (1 << n); ++mask) {
            if (c == 1) {
                d[1][mask] = got[mask];
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
                if (got[])
            }
        }

        if (got[(1 << n) - 1])
            printf("%d %d", c, d[c][(1 << n) - 1]);
    }


    return 0;
}
