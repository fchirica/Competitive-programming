#include <stdio.h>
#define low(x) ((x - 1) * lim + 1)
#define up(x) (x * lim)

char x[100100], qq[50500];
int SP[100100];
int xx[50500], yy[50500];

int cnt(long long X) {
    int res = 0;
    while (X) {
        ++res;
        X = X & (X - 1);
    }
    return res;
}

int main() {
    freopen("memorie.in", "r", stdin);
    freopen("memorie.out", "w", stdout);

    int N, Q;
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        x[i] = tmp;
    }

    if (Q <= 10) {
        while (Q--) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            long long mask = 0;
            for (int i = xx; i <= yy; ++i)
                mask = mask | (1LL << x[i]);
            printf("%d\n", cnt(mask));
        }
        return 0;
    }

    int lim = Q / 4;
    for (int t = 1; t <= 4; ++t) {
        int cnt = 0;
        for (int i = low(t); i <= up(t) && i <= Q; ++i) {
            ++cnt;
            scanf("%d%d", &xx[cnt], &yy[cnt]);
            qq[cnt] = 0;
        }
        for (int val = 1; val <= 52; ++val) {
            for (int i = 1; i <= N; ++i)
                SP[i] = SP[i - 1] + (x[i] == val);
            for (int i = 1; i <= cnt; ++i) {
                int tmp = SP[yy[i]] - SP[xx[i] - 1];
                qq[i] += (tmp > 0);
            }
        }
        for (int i = 1; i <= cnt; ++i)
            printf("%d\n", (int)qq[i]);
    }

    return 0;
}
