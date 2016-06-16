#include <stdio.h>

int x[200010], h[200010];
int st[200010];
int nxt[20][200010], cost[20][210000];

inline int min(int A, int B) {
    return A < B ? A : B;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &h[i]);

    for (int i = n; i >= 1; --i) {
        cost[0][i] = 2000000000;
        while (st[0] > 0) {
            if (x[st[st[0]]] <= x[i] + h[i]) {
                nxt[0][i] = nxt[0][st[st[0]]];
                cost[0][i] = cost[0][st[st[0]]];
                --st[0];
            } else {
                nxt[0][i] = st[st[0]];
                cost[0][i] = min(cost[0][i], x[st[st[0]]] - h[i] - x[i]);
                break;
            }
        }
        if (st[0] == 0) {
            cost[0][i] = 0;
            nxt[0][i] = n;
        }
        st[++st[0]] = i;
    }

    for (int pw = 1; pw <= 19; ++pw)
        for (int i = 1; i <= n; ++i)
            if (nxt[pw - 1][i] == n) {
                nxt[pw][i] = nxt[pw - 1][i];
                cost[pw][i] = cost[pw - 1][i];
            } else {
                nxt[pw][i] = nxt[pw - 1][nxt[pw - 1][i]];
                cost[pw][i] = cost[pw - 1][i] + cost[pw - 1][nxt[pw - 1][i]];
            }

    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int xx, yy, res = 0;
        scanf("%d%d", &xx, &yy);
        for (int pw = 19; pw >= 0; --pw)
            if (nxt[pw][xx] <= yy) {
                res += cost[pw][xx];
                xx = nxt[pw][xx];
            }
        printf("%d\n", res);
    }

    return 0;
}
