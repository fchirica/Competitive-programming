#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-2

using namespace std;

struct point {
    double x, y;
} x[2222];

int comp(double A, double B) {
    if (fabs(A - B) < EPS)
        return 0;
    if (A < B - EPS)
        return -1;
    return 1;
}

inline bool cmp(point A, point B) {
    if (comp(A.x, B.x) == 0)
        return comp(A.y, B.y) == -1 ? 1 : 0;
    return comp(A.x, B.x) == -1 ? 1 : 0;
}

int find(int st, int dr, point X) {
    if (st > dr)
        return 0;
    int med = (st + dr) / 2;
    if (comp(X.x, x[med].x) == 0 && comp(X.y, x[med].y) == 0)
        return med;
    if (cmp(X, x[med]) == 1)
        return find(st, med - 1, X);
    return find(med + 1, dr, X);
}

struct eq {
    double A, B, C;
} sol[2222];

eq make(point A, point B) {
    eq tmp;
    tmp.A = A.y - B.y;
    tmp.B = B.x - A.x;
    tmp.C = A.x * B.y - A.y * B.x;
    return tmp;
}

double det(double A, double B, double C, double D) {
    return A * D - B * C;
}

point intersect(eq L1, eq L2) {
    point tmp;
    tmp.x = det(-L1.C, L1.B, -L2.C, L2.B) / det(L1.A, L1.B, L2.A, L2.B);
    tmp.y = det(L1.A, -L1.C, L2.A, -L2.C) / det(L1.A, L1.B, L2.A, L2.B);
    return tmp;
}

bool skipped[1024];

bool good(eq X, int N) {
    for (int i = 1; i <= N; ++i)
        skipped[i] = 0;
    for (int i = 1; i <= N; ++i) {
        if (comp(X.A * x[i].x + X.B * x[i].y + X.C, 0.0) == 0)
            continue;
        if (skipped[i])
            continue;
        eq X2;
        X2.A = -X.B; X2.B = X.A; X2.C = -X2.A * x[i].x - X2.B * x[i].y;
        point O = intersect(X, X2), want;
        want.x = 2.0 * O.x - x[i].x;
        want.y = 2.0 * O.y - x[i].y;
        int idx = find(1, N, want);
        if (idx == 0)
            return 0;
        skipped[idx] = 1;
    }
    return 1;
}

int main() {
    freopen("dmg.in", "r", stdin);
    freopen("dmg.out", "w", stdout);

    int N;
    point G;
    scanf("%d", &N);
    G.x = G.y = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%lf %lf", &x[i].x, &x[i].y);
        G.x += x[i].x;
        G.y += x[i].y;
    }

    G.x /= (1.0 * N); G.y /= (1.0 * N);
    sort(x + 1, x + N + 1, cmp);

    eq cur = make(x[1], G);
    int cnt = 0;
    if (good(cur, N))
        sol[++cnt] = cur;

    for (int i = 2; i <= N; ++i) {
        cur = make(x[1], x[i]);
        if (good(cur, N) && comp(cur.A * G.x + cur.B * G.y + cur.C, 0.0))
            sol[++cnt] = cur;
        point med;
        med.x = (x[1].x + x[i].x) * 0.5;
        med.y = (x[1].y + x[i].y) * 0.5;
        eq newEq;
        newEq.A = -cur.B; newEq.B = cur.A; newEq.C = -newEq.A * med.x - newEq.B * med.y;
        if (good(newEq, N))
            sol[++cnt] = newEq;
    }

    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i)
        printf("%.8lf %.8lf %.8lf\n", sol[i].A + (1e-10), sol[i].B + (1e-10), sol[i].C + (1e-10));
    return 0;
}
