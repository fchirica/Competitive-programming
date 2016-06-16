#include <stdio.h>
#include <algorithm>
#include <math.h>
#define point pair <double, double>
#define x first
#define y second

using namespace std;

int cntH;
point X[120100], H[120100];

inline double ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

inline bool comp(point A, point B) {
    return ccw(X[1], A, B) > 0;
}

void convexHull(int N) {
    int i;
    for (i = 1; i <= N; ++i)
        if (X[i].y < X[1].y || (X[i].y == X[1].y && X[i].x < X[1].x))
            swap(X[1], X[i]);
    sort(X + 2, X + N + 1, comp);
    X[++N] = X[1];
    H[++cntH] = X[1]; H[++cntH] = X[2];
    int currentPoint = 3;
    while (currentPoint <= N)
        if (ccw(H[cntH - 1], H[cntH], X[currentPoint]) > 0) {
            H[++cntH] = X[currentPoint];
            ++currentPoint;
        } else
            --cntH;
}

int main() {
    freopen("hull.in", "r", stdin);
    freopen("hull.out", "w", stdout);

    int i, N;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
        scanf("%lf%lf", &X[i].x, &X[i].y);

    convexHull(N);

    printf("%d\n", cntH - 1);
    for (i = 1; i < cntH; ++i)
        printf("%lf %lf\n", H[i].x, H[i].y);
    return 0;
}
