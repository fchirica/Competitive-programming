#include <stdio.h>
#include <algorithm>
#include <complex>
#include <cmath>
#define x first
#define y second
#define point pair <double, double>
#define EPS 0.0000001

using namespace std;

point x[1600];

point getThird(point A, point B) {
    point C;
    B.x -= A.x; B.y -= A.y;
    complex <double> x1(B.x, B.y), x2(0.5, sqrt(3) * 0.5), x3 = x1 * x2;
    C = make_pair(x3.real() + A.x, x3.imag() + A.y);
    return C;
}

int comp(point A, point B) {
    if (fabs(A.x - B.x) < EPS) {
        if (fabs(A.y - B.y) < EPS)
            return 0;
        if (A.y - B.y > EPS)
            return 1;
        return -1;
    }
    if (A.x - B.x > EPS)
        return 1;
    return -1;
}

bool is(point A, int dr) {
    int st = 1, med;
    while (st <= dr) {
        med = (st + dr) / 2;
        if (comp(x[med], A) == 0)
            return 1;
        if (comp(x[med], A) > 0)
            dr = med - 1;
        else
            st = med + 1;
    }
    return 0;
}

int main() {
    freopen("triang.in", "r", stdin);
    freopen("triang.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%lf%lf", &x[i].x, &x[i].y);
    sort(x + 1, x + N + 1);

    long long res = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (i != j) {
                point X = getThird(x[i], x[j]);
                if (is(X, N))
                    ++res;
            }

    printf("%lld", res / 3);
    return 0;
}
