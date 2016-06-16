#include <stdio.h>

const int kNMax = 200200;

int x[kNMax], f[kNMax], fin[kNMax];

int main() {
    freopen("invsc.in", "r", stdin);
    freopen("invsc.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
        ++f[x[i]];
    }
    for (int i = 1; i <= n; ++i)
        fin[i] = fin[i - 1] + f[i];
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", fin[x[i]]);
        --fin[x[i]];
    }
    return 0;
}
