#include <stdio.h>

int main() {
    freopen("neconex.in", "r", stdin);
    freopen("neconex.out", "w", stdout);

    int q;
    scanf("%d", &q);

    while (q--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            int foo, bar;
            scanf("%d%d", &foo, &bar);
        }
        int res = (n * (n - 1) / 2 - m) % 2;
        printf("%d\n", res);
    }

    return 0;
}
