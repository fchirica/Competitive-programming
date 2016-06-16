#include <stdio.h>

int main() {
    freopen("perechi.in", "r", stdin);
    freopen("perechi.out", "w", stdout);

    int n, res = 1;
    scanf("%d", &n);
    for (int d = 2; 1LL * d * d <= n; ++d)
        if (n % d == 0) {
            int pw = 0;
            while (n % d == 0) {
                ++pw;
                n /= d;
            }
            res *= (2 * pw + 1);
        }

    if (n > 1)
        res *= 3;

    printf("%d", (res + 1) / 2);
    return 0;
}
