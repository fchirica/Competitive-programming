#include <stdio.h>

struct point {
    double x, y;
} x[10001];

inline int ccw(point A, point B, point C) {
    double cross_product = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
    if (cross_product > 0)
        return 1;
    return -1;
}

int main() {
    freopen("tangente.in", "r", stdin);
    freopen("tangente.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", &x[i].x, &x[i].y);

    while (q--) {
        point X;
        int cnt = 0;
        scanf("%lf%lf", &X.x, &X.y);
        for (int i = 1; i <= n && cnt < 2; ++i) {
            point next = x[i % n + 1];
            point prev = x[(i - 2 + n) % n + 1];
            if (ccw(X, x[i], prev) * ccw(X, x[i], next) > 0) {
                printf("%d ", i);
                ++cnt;
            }
        }
        printf("\n");
    }

    return 0;
}
