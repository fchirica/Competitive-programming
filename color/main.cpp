#include <bits/stdc++.h>

using namespace std;

int deg[4444];

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        ++deg[xx]; ++deg[yy];
    }

    long long comb = (long long) n * (n - 1) * (n - 2) / 6;
    long long bad = 0;
    for (int i = 1; i <= n; ++i)
        bad += deg[i] * (n - 1 - deg[i]);
    printf("%lld", comb - bad / 2);
    return 0;
}
