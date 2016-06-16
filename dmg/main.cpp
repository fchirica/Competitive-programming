#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <complex>
#include <cassert>
#include <map>

using namespace std;

struct point {
    double x, y;
} x[2000];

struct eq {
    double A, B, C;

    eq() {}

    eq(point P1, point P2) {
        A = P1.y - P2.y;
        B = P2.x - P1.x;
        C = P1.x * P2.y - P1.y * P2.x;
    }

    eq(double m, point P) {
        A = -m;
        B = 1;
        C = m * P.x - P.y;
    }
} L[5000 * 5000];

int N, cnt;
bool sol[5000 * 5000];
const double EPS = 0.0000001;

inline double ab(double X) {
    return X > 0 ? X : -X;
}

void load(point P) {
    for (int kkt = 1; kkt <= N; ++kkt) {
        P = x[kkt];
    for (int i = kkt + 1; i <= N; ++i) {
        if (ab(P.x - x[i].x) <= EPS && ab(P.y - x[i].y) <= EPS)
            continue;
        L[++cnt] = eq(P, x[i]);
        point med;
        med.x = (P.x + x[i].x) * 0.5;
        med.y = (P.y + x[i].y) * 0.5;
        if (P.x == x[i].x) {
            L[++cnt].A = 0; L[cnt].B = 1; L[cnt].C = -med.y;
            continue;
        }
        if (P.y == x[i].y) {
            L[++cnt].A = 1; L[cnt].B = 0; L[cnt].C = -med.x;
            continue;
        }
        double m = (P.y - x[i].y) / (P.x - x[i].x);
        m = (double)-1 / m;
        L[++cnt] = eq(m, P);
    }
    }
}

double det(double A, double B, double C, double D) {
    return A * D - B * C;
}

point intersect(eq L1, eq L2) {
    point tmp;
    assert(det(L1.A, L1.B, L2.A, L2.B) != 0);
    tmp.x = det(-L1.C, L1.B, -L2.C, L2.B) / det(L1.A, L1.B, L2.A, L2.B);
    tmp.y = det(L1.A, -L1.C, L2.A, -L2.C) / det(L1.A, L1.B, L2.A, L2.B);
    return tmp;
}

inline bool comp(point A, point B) {
    if (ab(A.x - B.x) <= EPS)
        return A.y - B.y <= -EPS;
    return A.x - B.x <= -EPS;
}

int exist(point A) {
    int st = 1, dr = N, med;
    while (st <= dr) {
        med = (st + dr) / 2;
        if (ab(x[med].x - A.x) <= EPS && ab(x[med].y - A.y) <= EPS)
            return med;
        if (comp(A, x[med]))
            dr = med - 1;
        else
            st = med + 1;
    }
    return 0;
}

int check(eq ll) {
    for (int i = 1; i <= N; ++i) {
        eq otherLine;
        if (!ab(ll.A) <= EPS) {
            double m = (double)ll.B / ll.A;
            otherLine = eq(m, x[i]);
        } else {
            point need;
            need.x = x[i].x;
            double lineY = (double)(-ll.C) / ll.B;
            need.y = 2 * lineY - x[i].y;
            if (!exist(need))
                return 0;
            continue;
        }
        point O = intersect(ll, otherLine), need;
        need.x = 2 * O.x - x[i].x;
        need.y = 2 * O.y - x[i].y;
        if (!exist(need))
            return 0;
    }
    return 1;
}

bool sameLine(eq L1, eq L2) {
    if (ab(L1.B) <= EPS && ab(L2.B) <= EPS)
        assert(0);
    if (ab(L1.B) <= EPS || ab(L2.B) <= EPS)
        return 0;
    for (int px = 0; px <= 1; ++px) {
        double y1 = (-L1.C - px * L1.A) / L1.B;
        double y2 = (-L2.C - px * L2.A) / L2.B;
        if (ab(y1 - y2) > EPS)
            return 0;
    }
    return 1;
}

int main() {
    freopen("dmg.in", "r", stdin);
    freopen("dmg.out", "w", stdout);

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%lf%lf", &x[i].x, &x[i].y);

    sort(x + 1, x + N + 1, comp);

    //load(x[1]);
    load(x[2]);

    int res = 0;
    for (int i = 1; i <= cnt; ++i)
        if (check(L[i])) {
            sol[i] = 1;
            for (int j = 1; j < i; ++j)
                if (sameLine(L[i], L[j])) {
                    sol[i] = 0;
                    break;
                }
            if (sol[i])
                ++res;
        }

    printf("%d\n", res);
    for (int i = 1; i <= cnt; ++i)
        if (sol[i])
            printf("%.8lf %.8lf %.8lf\n", L[i].A, L[i].B, L[i].C);

    return 0;
}
