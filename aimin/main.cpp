#include <stdio.h>

int st[100100];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    freopen("aimin.in", "r", stdin);
    freopen("aimin.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int leaf;
        scanf("%d", &leaf);
        if (i == 1) {
            st[++st[0]] = leaf;
            continue;
        }
        while (st[0] >= 2) {
            int curh = max(st[st[0]], leaf) + 1;
            if (curh + 1 <= st[st[0] - 1]) {
                st[st[0]] = curh;
                st[++st[0]] = leaf;
                break;
            } else
                --st[0];
        }
        if (st[0] == 1) {
            st[1] = max(leaf, st[1]) + 1;
            st[++st[0]] = leaf;
        }
    }

    printf("%d", st[1]);
    return 0;
}
