#include <stdio.h>

int a[1000100], b[1000100], c[1000100], go[1000100], res[1000100];

int main() {
    freopen("curcubeu.in", "r", stdin);
    freopen("curcubeu.out", "w", stdout);

    int n;
    scanf("%d%d%d%d", &n, &a[1], &b[1], &c[1]);
    for (int i = 2; i <= n; ++i) {
        a[i] = (long long) a[i - 1] * i % n;
        b[i] = (long long) b[i - 1] * i % n;
        c[i] = (long long) c[i - 1] * i % n;
    }

    for (int i = n; i >= 1; --i) {
        int l = a[i], r = b[i];
        if (l > r) {
            int tmp = l;
            l = r;
            r = tmp;
        }
        while (l <= r) {
            if (!go[l]) {
                go[l] = r + 1;
                res[l] = c[i];
                ++l;
            } else {
                int tmp = go[l];
                if (r + 1 > go[l])
                    go[l] = r + 1;
                l = tmp;
            }
        }
    }

    for (int i = 1; i < n; ++i)
        printf("%d\n", res[i]);
    return 0;
}
