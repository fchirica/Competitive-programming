#include <stdio.h>

const int INF = 1 << 30;

int main() {
    freopen("pba.in", "r", stdin);
    freopen("pba.out", "w", stdout);

    int max1 = -INF, max2 = -INF, max3 = -INF;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (x >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = x;
        } else if (x >= max2) {
            max3 = max2;
            max2 = x;
        } else if (x >= max3)
            max3 = x;
    }

    long long sol = ((long long) max1 * max2 + 1000000007LL) % 1000000007;
    sol = (sol * max3 + 1000000007LL) % 1000000007;
    printf("%lld", sol);
    return 0;
}
