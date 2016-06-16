#include <stdio.h>
#include <algorithm>

using namespace std;

int a[100100], b[100100];

int main() {
    freopen("permut.in", "r", stdin);
    freopen("permut.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    long long tot = 0;
    for (int i = 1; i <= n; ++i)
        tot += 1LL * a[i] * b[i];
    printf("%lld", tot);
    return 0;
}
