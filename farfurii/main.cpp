#include <bits/stdc++.h>

int main() {
    freopen("farfurii.in", "r", stdin);
    freopen("farfurii.out", "w", stdout);

    int n;
    long long inv;
    scanf("%d%lld", &n, &inv);

    int i = 0, suffix;
    long long maxInversions;
    do {
        ++i;
        suffix = n - i;
        maxInversions = (long long) suffix * (suffix - 1) / 2;
    } while (maxInversions > inv);

    for (int j = 1; j < i; ++j)
        printf("%d ", j);
    int pos = i;
    while (maxInversions < inv) {
        ++i;
        ++maxInversions;
    }
    printf("%d ", i);
    int val = n;
    for (int j = pos + 1; j <= n; ++j) {
        if (val == i)
            --val;
        printf("%d ", val);
        --val;
    }
    return 0;
}
