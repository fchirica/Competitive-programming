#include <stdio.h>
#include <algorithm>
#include <cmath>
#define point pair <double, double>
#define x first
#define y second
#define INF 100100

using namespace std;

int N;
point x[2013];

bool remainedTest = true;
void read() {
    scanf("%d", &N);
    if (N == 0)
        remainedTest = false;
    for (int i = 1; i <= N; ++i) {
        int xi, yi;
        scanf("%d%d", &xi, &yi);
        x[i] = make_pair(xi, yi);
    }
    x[N + 1] = x[1];
}

int sgn;
point previous[2013], current[2013];

double ccw(point A, point B, point C) {
    double ret = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
    if (ret > 0.0000001)
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

bool notEmptyIntersection() {
    int previousCnt = 4;
    previous[1] = make_pair(-INF, -INF);
    previous[2] = make_pair(-INF, INF);
    previous[3] = make_pair(INF, INF);
    previous[4] = make_pair(INF, -INF);
    previous[5] = previous[1];

    int i, j;
    for (i = 1; i <= N; ++i) {
        int currentCnt = 0;
        for (j = 1; j <= previousCnt; ++j)
            if (ccw(x[i], x[i + 1], previous[j]) == sgn) {
                current[++currentCnt] = previous[j];
                if (ccw(x[i], x[i + 1], previous[j + 1]) != sgn)
                    current[++currentCnt] = intersect(x[i], x[i + 1], previous[j], previous[j + 1]);
            } else
                if (ccw(x[i], x[i + 1], previous[j + 1]) == sgn)
                    current[++currentCnt] = intersect(x[i], x[i + 1], previous[j], previous[j + 1]);
        if (currentCnt == 0)
            return 0;
        previousCnt = currentCnt;
        for (j = 1; j <= previousCnt; ++j)
            previous[j] = current[j];
        previous[previousCnt + 1] = previous[1];
    }
    return 1;
}

void solve() {
    sgn = 1;
    int area1 = notEmptyIntersection();
    sgn = -1;
    int area2 = notEmptyIntersection();
    printf("%d\n", area1 > area2 ? area1 : area2);
}

int main() {
    read();
    while (remainedTest) {
        solve();
        read();
    }
    return 0;
}
