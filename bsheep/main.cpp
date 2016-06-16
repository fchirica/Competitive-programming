#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct point {
    int x, y, origin;
} LL, x[100100];

inline int ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

inline double dist(point A, point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

int st[100100];

inline bool comp(point A, point B) {
    if (ccw(LL, A, B) == 0)
        return dist(LL, A) - dist(LL, B) <= -0.0000001;
    return ccw(LL, A, B) > 0 ? 1 : 0;
}

void solveTest() {
    int i, N;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i) {
        scanf("%d%d", &x[i].x, &x[i].y);
        x[i].origin = i;
    }

    LL.x = LL.y = 1 << 30;
    int idx;
    for (i = 1; i <= N; ++i)
        if (x[i].y < LL.y || (x[i].y == LL.y && x[i].x < LL.x)) {
            LL = x[i];
            idx = i;
        }

    point tmp;
    tmp = x[1];
    x[1] = x[idx];
    x[idx] = tmp;

    sort(x + 2, x + N + 1, comp);
    x[++N] = LL;

    st[1] = 1; st[2] = 2;
    int currentPoint = 3, u = 2;
    while (currentPoint <= N) {
        int curCCW = ccw(x[st[u - 1]], x[st[u]], x[currentPoint]);
        if (curCCW > 0) {
            st[++u] = currentPoint;
            ++currentPoint;
        } else {
            if (currentPoint != N)
                --u;
            if (curCCW == 0) {
                st[++u] = currentPoint;
                ++currentPoint;
            }
        }
    }

    double D = 0;
    for (i = 1; i < u; ++i)
        D += dist(x[st[i]], x[st[i + 1]]);

    printf("%.2lf\n", D);
    for (i = 1; i < u; ++i)
        printf("%d ", x[st[i]].origin);
    printf("\n\n");
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
        solveTest();

    return 0;
}
