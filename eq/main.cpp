#include <stdio.h>

struct SegmentTree {
    int xmin, xmax;
    int ymax, zmin;
    int x_min_min, x_min_max;
    int x_max_min, x_max_max;
} AINT[4 * 100100 + 69];

int x[100100];

inline void chmax(int &A, int B) {
    if (B > A)
        A = B;
}

inline void chmin(int &A, int B) {
    if (A > B)
        A = B;
}

void build(int nod, int st, int dr) {
    if (st > dr)
        return ;

    AINT[nod].xmin = AINT[nod].xmax = AINT[nod].ymax = AINT[nod].zmin = x[dr];
    AINT[nod].x_min_max = AINT[nod].x_max_min = 0;
    AINT[nod].x_min_min = AINT[nod].x_max_max = 2 * x[dr];

    for (int i = dr - 1; i >= st; --i) {
        chmax(AINT[nod].xmax, x[i]);
        chmin(AINT[nod].xmin, x[i]);
        chmax(AINT[nod].x_min_max, x[i] - AINT[nod].xmin);
        chmax(AINT[nod].x_max_max, x[i] + AINT[nod].xmax);
        chmin(AINT[nod].x_min_min, x[i] + AINT[nod].xmin);
        chmin(AINT[nod].x_max_min, x[i] - AINT[nod].xmax);
        chmax(AINT[nod].ymax, x[i] - AINT[nod].xmin + AINT[nod].xmax);
        chmin(AINT[nod].zmin, x[i] - AINT[nod].xmax + AINT[nod].xmin);
    }

    if (st == dr)
        return ;
    int m = (st + dr) / 2;
    build(2 * nod, st, m);
    build(2 * nod + 1, m + 1, dr);
}

SegmentTree ans;

void query(int nod, int st, int dr, int xx, int yy) {
    if (xx <= st && dr <= yy) {
        chmax(ans.ymax, AINT[nod].ymax);
        chmax(ans.ymax, AINT[nod].x_min_max + ans.xmax);
        chmax(ans.ymax, AINT[nod].x_max_max - ans.xmin);
        chmax(ans.ymax, AINT[nod].xmax + ans.xmax - ans.xmin);
        chmin(ans.zmin, AINT[nod].zmin);
        chmin(ans.zmin, AINT[nod].x_min_min - ans.xmax);
        chmin(ans.zmin, AINT[nod].x_max_min + ans.xmin);
        chmin(ans.zmin, AINT[nod].xmin - ans.xmax + ans.xmin);
        chmax(ans.xmax, AINT[nod].xmax);
        chmin(ans.xmin, AINT[nod].xmin);
        return ;
    }

    int m = (st + dr) / 2;
    if (m < yy)
        query(2 * nod + 1, m + 1, dr, xx, yy);
    if (xx <= m)
        query(2 * nod, st, m, xx, yy);
}

int main() {
    freopen("eq.in", "r", stdin);
    freopen("eq.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    build(1, 1, n);

    while (q--) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        ans.ymax = ans.xmax = -1000000000;
        ans.zmin = ans.xmin = 1000000000;
        query(1, 1, n, xx, yy);
        printf("%d\n", ans.ymax + ans.zmin);
    }

    return 0;
}
