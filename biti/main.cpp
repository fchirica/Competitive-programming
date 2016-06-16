#include <stdio.h>

const int kNMax = (1 << 20) + 100;

int g[kNMax], st[kNMax], what[kNMax], res[kNMax];

int main() {
    freopen("biti.in", "r", stdin);
    freopen("biti.out", "w", stdout);

    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("2\n01");
        return 0;
    }
    printf("%d\n", (1 << n) + n - 1);
    for (int i = 1; i < n - 1; ++i)
        printf("0");

    int N = (1 << (n - 1)) - 1;
    for (int i = 0; i <= N; ++i)
        g[i] = -1;
    int u = 0;
    st[++u] = 0;
    while (u > 0) {
        int nod = st[u];
        if (g[nod] == -1) {
            g[nod] = 0;
            st[++u] = (nod * 2) & N;
            what[u] = 0;
        } else
        if (g[nod] == 0) {
            g[nod] = 1;
            st[++u] = (nod * 2 + 1) & N;
            what[u] = 1;
        } else {
            res[++res[0]] = what[u];
            --u;
        }
    }

    for (int i = res[0]; i >= 1; --i)
        printf("%d", res[i]);
    return 0;
}
