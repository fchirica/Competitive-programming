#include <stdio.h>
#include <math.h>
#include <cassert>

struct point {
    double x, y;
} xx[10100], yy[10100];

double ccw(point A, point B, point C) {
    double tmp = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
    return tmp > 0 ? 1 : -1;
}

bool intersect(point A, point B, point C, point D) {
    double cc1 = ccw(A, C, D);
    double cc2 = ccw(B, C, D);
    double cc3 = ccw(C, A, B);
    double cc4 = ccw(D, A, B);
    return (cc1 * cc2 < 0 && cc3 * cc4 < 0);
}

double dist(point A, point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

bool equal(double A, double B) {
    double diff = A - B;
    if (diff < 0)
        diff = diff * (-1);
    return diff <= 0.00000001;
}

int main() {
    int i, N;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
        scanf("%lf%lf%lf%lf", &xx[i].x, &xx[i].y, &yy[i].x, &yy[i].y);
    point P;
    scanf("%lf%lf", &P.x, &P.y);

    for (i = 1; i <= N; ++i)
        if (equal(dist(xx[i], P) + dist(P, yy[i]), dist(xx[i], yy[i]))) {
            printf("BORDER");
            return 0;
        }

    P.x += 0.0005; P.y += 0.0005;

    int cnt = 0;
    point P2;
    P2.x = 100100; P2.y = P.y;
    for (i = 1; i <= N; ++i)
        if (intersect(P, P2, xx[i], yy[i]))
            ++cnt;
    printf("%s", cnt % 2 ? "INSIDE" : "OUTSIDE");
    return 0;
}
