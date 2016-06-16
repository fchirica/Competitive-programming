#include <bits/stdc++.h>

using namespace std;

const int kNMax = 50500;

int x[kNMax], y[kNMax];

int main() {
    freopen("specsort.in", "r", stdin);
    freopen("specsort.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    for (int b = 0; (1 << b) <= n; ++b) {
        int y_cnt = 0;
        for (int i = 1; i <= n; ++i)
            if ((x[i] & (1 << b)) == 0)
                y[++y_cnt] = x[i];
        for (int i = 1; i <= n; ++i)
            if (x[i] & (1 << b))
                y[++y_cnt] = x[i];
        for (int i = 1; i <= n; ++i) {
            x[i] = y[i];
            printf("%d ", x[i]);
        }
        printf("\n");
    }
    return 0;
}

