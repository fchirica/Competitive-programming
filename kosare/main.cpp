#include <stdio.h>

int a[1 << 20], pw[1 << 20];
const int mod = 1000000007;

int cnt(int X) {
    int res = 0;
    while (X) {
        ++res;
        X = X & (X - 1);
    }
    return res;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        int cnt, mask = 0;
        scanf("%d", &cnt);
        for (int j = 1; j <= cnt; ++j) {
            int tmp;
            scanf("%d", &tmp);
            --tmp;
            mask |= (1 << tmp);
        }
        ++a[mask];
    }

    pw[0] = 1;
    for (int i = 1; i <= N; ++i)
        pw[i] = 2 * pw[i - 1] % mod;

    for (int b = 0; b < M; ++b)
        for (int mask = 0; mask < (1 << M); ++mask)
            if ((mask & (1 << b)) == 0)
                a[mask | (1 << b)] += a[mask];

    int res = 0;
    for (int mask = 0; mask < (1 << M); ++mask) {
        int bitCnt = M - cnt(mask);
        if (bitCnt % 2 == 0)
            res = res + pw[a[mask]];
        else
            res = res - pw[a[mask]];
        if (res >= mod)
            res -= mod;
        if (res < 0)
            res += mod;
    }

    printf("%d", res);
    return 0;
}
