#include <stdio.h>

int main() {
    freopen("sticle.in", "r", stdin);
    freopen("sticle.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int res;
        for (res = 0; (1 << res) < n; ++res);
        printf("%d\n", res);
    }

    return 0;
}
