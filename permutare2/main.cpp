#include <stdio.h>

int x[100100], SP[100100], f[100100];

int costLeft(int from, int to, int m) {
    if (from > to)
        return from - to;
    return from + m - to;
}

int costRight(int from, int to, int m) {
    if (from < to)
        return to - from;
    return m - from + to;
}

int main() {
    freopen("permutare2.in", "r", stdin);
    freopen("permutare2.out", "w", stdout);

    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i) {
        int shit;
        scanf("%d", &shit);
    }
    for (int i = 2; i <= n; ++i)
        scanf("%d", &x[i]);
    for (int i = 1; i <= n; ++i)
        ++f[x[i]];
    int cnt = 0;
    for (int i = 0; i <= m; ++i)
        for (int j = 1; j <= f[i]; ++j)
            x[++cnt] = i;
    for (int i = 1; i <= n; ++i)
        SP[i] = SP[i - 1] + x[i];

    int ptr1 = 0, ptr2 = 2, res = 1 << 30;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;

        while (ptr1 < i && costLeft(x[ptr1], x[i], m) <= costRight(x[ptr1], x[i], m))
            ++ptr1;
        if (ptr1)
            cur += leftSum(1, ptr1);
        if (ptr1 + 1 <= i)
            cur += rightSum(ptr1 + 1, i);

        if (ptr2 < i)
            ptr2 = i;
        while (ptr2 < n && costLeft(x[ptr2], x[i], m) <= costRight(x[ptr2], x[i], m))
            ++ptr2;
        if (ptr2 > i)
            cur += leftSum(i + 1, ptr2);
        if (ptr2 + 1 <= n)
            cur += rightSum(ptr2, n);

        if (cur < res)
            res = cur;
    }

    printf("%d", res);
    return 0;
}
