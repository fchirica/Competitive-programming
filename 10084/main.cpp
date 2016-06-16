#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <complex>
#define x first
#define y second
#define point pair <double, double>
#define EPS 0.0000001

using namespace std;

point P[100], P2[100];

int ccw(point A, point B, point C) {
    double ret = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
    if (ret > EPS)
        return 1;
    return -1;
}

double det(double A, double B, double C, double D) {
    return A * D - B * C;
}

point intersect(point A, point B, point C, point D) {
    double A1 = A.y - B.y; double B1 = B.x - A.x; double C1 = -A.x * B.y + A.y * B.x;
    double A2 = C.y - D.y; double B2 = D.x - C.x; double C2 = -C.x * D.y + C.y * D.x;
    double xint, yint;
    xint = det(C1, B1, C2, B2) / det(A1, B1, A2, B2);
    yint = det(A1, C1, A2, C2) / det(A1, B1, A2, B2);
    return make_pair(xint, yint);
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    double lx, ly, px, py, ans = 100;
    char state[100];

    int cnt = 4;
    P[1] = make_pair(0, 0);
    P[2] = make_pair(0, 10);
    P[3] = make_pair(10, 10);
    P[4] = make_pair(10, 0);
    P[5] = P[1];

    lx = 0; ly = 0;
    while (scanf("%lf %lf %s\n", &px, &py, &state) != EOF) {
        if (state[0] == 'S')
            if (fabs(px - lx) <= EPS && fabs(py - ly) <= EPS)
                printf("%lf\n", ans);
            else
                ans = 0;
        if (ans == 0) {
            printf("0.00\n");
            continue;
        }

        point X1 = make_pair((lx + px) * 0.5, (ly + py) * 0.5);
        complex <double> c1(px - X1.x, py - X1.y), c2(0, 1), c3 = c1 * c2;
        point X2 = make_pair(c3.real() + X1.x, c3.imag() + X1.y);

        int wantedSgn = ccw(X1, X2, make_pair(px, py));
        if (state[0] == 'C')
            wantedSgn = ccw(X1, X2, make_pair(lx, ly));

        int i, currentCnt = 0;
        for (i = 1; i <= cnt; ++i)
            if (ccw(X1, X2, P[i]) == wantedSgn) {
                P2[++currentCnt] = P[i];
                if (ccw(X1, X2, P[i + 1]) != wantedSgn)
                    P2[++currentCnt] = intersect(X1, X2, P[i], P[i + 1]);
            } else
                if (ccw(X1, X2, P[i + 1]) == wantedSgn)
                    P2[++currentCnt] = intersect(X1, X2, P[i], P[i + 1]);
        cnt = currentCnt;
        for (i = 1; i <= cnt; ++i)
            P[i] = P2[i];
        P[cnt + 1] = P[1];

        double area = 0;
        for (i = 1; i <= cnt; ++i)
            area += P[i].x * P[i + 1].y - P[i].y * P[i + 1].x;
        if (area < 0)
            area = -area;
        printf("%.2lf\n", area * 0.5);
        lx = px; ly = py;
    }

    return 0;
}
