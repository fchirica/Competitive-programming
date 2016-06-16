#include <stdio.h>
#include <math.h>
#include <algorithm>
#define PI 2 * acos(0)
#define point pair <double, double>
#define x first
#define y second

using namespace std;

point makeRotation(point O, point X, double alfa) {
    point _X;
    _X.x = O.x + (X.x - O.x) * cos(alfa) - (X.y - O.y) * sin(alfa);
    _X.y = O.y + (X.x - O.x) * sin(alfa) + (X.y - O.y) * cos(alfa);
    return _X;
}

struct eq {
    double A, B, C;
};

eq makeEquation(point A, point B) {
    eq tmp;
    tmp.A = A.y - B.y;
    tmp.B = B.x - A.x;
    tmp.C = A.x * B.y - A.y * B.x;
    return tmp;
}

double det(double A, double B, double C, double D) {
    return A * C - B * D;
}

point intersect(eq eq1, eq eq2) {
    point O;
    O.x = det(-eq1.C, eq1.B, -eq2.C, eq2.B) / det(eq1.A, eq1.B, eq2.A, eq2.B);
    O.y = det(eq1.A, -eq1.C, eq2.A, -eq2.C) / det(eq1.A, eq1.B, eq2.A, eq2.B);
    return O;
}

point sol[200];

int main() {
    freopen("120.in", "r", stdin);
    freopen("120.out", "w", stdout);

    int i, N, pos1, pos2;
    point X, Y;
    scanf("%d%d%d", &N, &pos1, &pos2);
    scanf("%lf%lf%lf%lf", &X.x, &X.y, &Y.x, &Y.y);
    if (pos1 > pos2) {
        swap(pos1, pos2);
        swap(X, Y);
    }

    double angle = 2 * PI / N;
    double angleBetween = (pos2 - pos1) * angle;
    double rotAngle = (PI - angleBetween) / 2;
    point O;
    if (rotAngle) {
        point X2 = makeRotation(Y, X, rotAngle);
        point Y2 = makeRotation(X, Y, -rotAngle);
        eq eq1 = makeEquation(X, X2);
        eq eq2 = makeEquation(Y, Y2);
        O = intersect(eq1, eq2);
    }
    if (rotAngle == 0) {
        O.x = (X.x + Y.x) * 0.5;
        O.y = (X.y + Y.y) * 0.5;
    }

    sol[1] = makeRotation(O, X, (pos1 - 1) * angle);
    for (i = 2; i <= N; ++i)
        sol[i] = makeRotation(O, sol[i - 1], -angle);

    for (i = 1; i <= N; ++i)
        printf("%.4lf %.4lf\n", sol[i].x, sol[i].y);
    return 0;
}
