#include <bits/stdc++.h>

using namespace std;

int q[65555 * 2];
int x[65555];

int main() {
    freopen("caraibe.in", "r", stdin);
    freopen("caraibe.out", "w", stdout);

    int p = 65001, u = 65000;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    q[++u] = 1;
    q[++u] = 1;
    for (int i = n - 2; i >= 1; --i) {
        int kill = n - i - x[i];
        while (kill) {
            if (q[u] <= kill) {
                kill -= q[u];
                --u;
            } else {
                q[u] -= kill;
                kill = 0;
            }
        }
        q[--p] = n - i - x[i];
        q[++u] = 1;
    }

    long long mySum = 10000000000LL;
    for (int i = p; i < u; ++i)
        mySum -= 1LL * q[i] * (i - p);
    printf("%lld", mySum);
    return 0;
}
