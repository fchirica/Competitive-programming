#include <stdio.h>

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long xx, yy;
    long long d = gcd(b, a % b, xx, yy);
    x = yy; y = xx - (a / b) * yy;
    return d;
}

int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        int c1, a, c2, b;
        scanf("%d%d%d%d", &c1, &a, &c2, &b);
        long long x, y, d = gcd(a, b, x, y);
        if (n % d) {
            printf("failed\n");
            continue ;
        } else {
            x = x * (n / d); y = y * (n / d);
            long long cost = 1LL << 60, xs, ys;
            long long v[2]; v[0] = -x * ((double)d / b); v[1] = y * ((double)d / a);
            for (int i = 0; i < 2; ++i)
                for (long long val = v[i] - 2; val <= v[i] + 2; ++val) {
                    long long xx = x + val * (b / d);
                    long long yy = y - val * (a / d);
                    if (xx >= 0 && yy >= 0)
                        if (xx * c1 + yy * c2 < cost)
                            cost = xx * c1 + yy * c2, xs = xx, ys = yy;
                }
            if (cost == 1LL << 60)
                printf("failed\n");
            else
                printf("%lld %lld\n", xs, ys);
        }
    }
    return 0;
}
