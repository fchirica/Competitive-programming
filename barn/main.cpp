#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
} x[1024];

struct rectangle {
    double x0, y0, d;
} P[1024 * 1024];

double dist(int x0, int y0, int x1, int y1) {
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

inline bool comp(rectangle A, rectangle B) {
    if (A.x0 == B.x0) {
        if (A.y0 == B.y0)
            return A.d < B.d;
        else
            return A.y0 < B.y0;
    }
    return A.x0 < B.x0;
}

void solveTest() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);

    int n = 0;
    for (int i = 1; i < N; ++i)
        for (int j = i + 1; j <= N; ++j) {
            P[++n].x0 = (x[i].x + x[j].x) * 0.5;
            P[n].y0 = (x[i].y + x[j].y) * 0.5;
            P[n].d = dist(x[i].x, x[i].y, x[j].x, x[j].y);
        }

    sort(P + 1, P + n + 1, comp);

    int sol = 0, ret = 1;
    for (int i = 1; i <= n; ++i)
        if (P[i].x0 == P[i + 1].x0 && P[i].y0 == P[i + 1].y0 && P[i].d == P[i + 1].d)
            ++ret;
        else {
            sol += ret * (ret - 1) / 2;
            ret = 1;
        }

    printf("%d\n", sol);
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int i;
    for (i = 1; i <= 10; ++i)
        solveTest();

    return 0;
}
