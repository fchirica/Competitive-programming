#include <stdio.h>

int x[100100];

int main() {
    freopen("cabine.in", "r", stdin);
    freopen("cabine.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    int cnt = 0;
    if (x[1] == 0)
        x[1] = ++cnt;
    if (x[n] == 0)
        x[n] = ++cnt;
    for (int i = n - 1; i >= 1; --i)
        if (x[i] == 0 && x[i + 1] == 0)
            x[i] = ++cnt;
    for (int i = 1; i <= n; ++i)
        if (x[i] == 0)
            x[i] = ++cnt;
    for (int i = 1; i <= n; ++i)
        if (x[i] == k)
            printf("%d", i);
    return 0;
}
