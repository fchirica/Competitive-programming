#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <assert.h>

using namespace std;

int under[1024][1024];

struct point {
    long long x, y;
    int idx;
} x[1024], y[1024];

inline int ccw(point A, point B, point C) {
    long long prod = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
    if (prod > 0)
        return 1;
    return -1;
}

double ang[1024];
int ind[1024];

const double EPS = (double)1 / 1e14;

inline bool comp(point A, point B) {
    return A.x < B.x;
}

int AIB[2 * 1024];

inline int lsb(int X){
    return X & -X;
}

int query(int X) {
    int res = 0;
    if (X == 0)
        return 0;
    for (; X > 0; X -= lsb(X))
        res += AIB[X];
    return res;
}

void update(int X, int lim) {
    for (; X <= lim; X += lsb(X))
        ++AIB[X];
}

inline bool comp2(int A, int B) {
    return ang[A] < ang[B];
}

int main() {
    freopen("tri2.in", "r", stdin);
    freopen("tri2.out", "w", stdout);

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        scanf("%lld%lld", &x[i].x, &x[i].y);
        x[i].idx = i;
        y[i] = x[i];
    }

    sort(x + 1, x + N + 1, comp);
    for (int i = 1; i <= N; ++i) {
        memset(AIB, 0, sizeof(AIB));
        for (int j = i + 1; j <= N; ++j) {
            ind[j] = j;
            ang[j] = ((double)x[j].y - x[i].y) / (x[j].x - x[i].x);
        }
        sort(ind + i + 1, ind + N + 1, comp2);
        for (int j = i + 1; j <= N; ++j) {
            under[x[i].idx][x[ind[j]].idx] = query(ind[j]);
            under[x[ind[j]].idx][x[i].idx] = under[x[i].idx][x[ind[j]].idx];
            update(ind[j], N);
        }
    }

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        point xx, yy, zz;
        int ord1, ord2, ord3;
        scanf("%d%d%d", &ord1, &ord2, &ord3);
        xx = y[ord1];
        yy = y[ord2];
        zz = y[ord3];
        if (xx.x > yy.x)
            swap(xx, yy);
        if (xx.x > zz.x)
            swap(xx, zz);
        if (yy.x > zz.x)
            swap(yy, zz);
        ord1 = xx.idx;
        ord2 = yy.idx;
        ord3 = zz.idx;
        int res;
        if (ccw(xx, zz, yy) > 0)
            res = under[ord1][ord2] + under[ord2][ord3] - under[ord1][ord3];
        else
            res = under[ord1][ord3] - under[ord1][ord2] - under[ord2][ord3] - 1;
        printf("%d\n", res);
    }

    return 0;
}
