#include <stdio.h>
#include <complex>
#include <math.h>

using namespace std;

struct point {
    double x, y;
} x[100010];

inline void chmin(double &A, double B) {
    if (A > B)
        A = B;
}

inline void chmax(double &A, double B) {
    if (A < B)
        A = B;
}

point rotate(double oldx, double oldy) {
    point res;
    complex <double> x1(oldx, oldy), x2(sqrt(2) * 0.5, sqrt(2) * 0.5), x3 = x1 * x2;
    res.x = x3.real();
    res.y = x3.imag();
    return res;
}

int main() {
    freopen("dreptunghi2.in", "r", stdin);
    freopen("dreptunghi2.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            int oldx, oldy;
            scanf("%d%d", &oldx, &oldy);
            x[i] = rotate(oldx, oldy);
        }
        double minx, maxx, miny, maxy;
        minx = maxx = x[1].x;
        miny = maxy = x[1].y;
        for (int i = 2; i <= N; ++i) {
            chmin(minx, x[i].x);
            chmax(maxx, x[i].x);
            chmin(miny, x[i].y);
            chmax(maxy, x[i].y);
        }
        point xx, yy;
        xx.x = minx; xx.y = miny;
        yy.x = maxx; yy.y = maxy;
        double res = 1.000 * (yy.x - xx.x) * (yy.y - xx.y);
        printf("%.3lf\n", res);
    }

    return 0;
}
