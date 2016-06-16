#include <stdio.h>
#include <algorithm>

using namespace std;

struct point {
    int x, y;

    point() {
        x = y = 0;
    }

    point(int xx, int yy) {
        x = xx; y = yy;
    }
} up[100100], down[100100], hup[100100], hdown[100100];

int ccw(point A, point B, point C) {
    long long cross = ((long long)B.x - A.x) * (C.y - B.y) - ((long long)B.y - A.y) * (C.x - B.x);
    return cross <= 0;
}

inline bool comp1(point A, point B) {
    if (A.x == B.x)
        return A.y < B.y;
    return A.x < B.x;
}

inline bool comp2(point A, point B) {
    if (A.x == B.x)
        return A.y > B.y;
    return A.x > B.x;
}

void convexHull(point x[], point hull[], int type, int &cnt, int n) {
    if (type == 0)
        sort(x + 1, x + n + 1, comp1);
    else
        sort(x + 1, x + n + 1, comp2);
    hull[++cnt] = x[1]; hull[++cnt] = x[2];
    for (int i = 3; i <= n; ++i) {
        while (cnt > 1 && ccw(hull[cnt - 1], hull[cnt], x[i]))
            --cnt;
        hull[++cnt] = x[i];
    }
}

int main() {
    freopen("oypara.in", "r", stdin);
    freopen("oypara.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x, yup, ydown;
        scanf("%d%d%d", &x, &ydown, &yup);
        up[i] = point(x, yup);
        down[i] = point(x, ydown);
    }

    int upCnt = 0, downCnt = 0;
    convexHull(up, hup, 0, upCnt, n);
    convexHull(down, hdown, 1, downCnt, n);

    point solUp, solDown;
    for (int i = 1, j = 1; i < upCnt; ++i) {
        for (; ccw(hup[i], hup[i + 1], hdown[j]) && j <= downCnt; ++j);
        if (j == downCnt + 1) {
            solUp = hup[i];
            break;
        }
    }
    for (int i = 1; i < downCnt; ++i)
        if (ccw(hdown[i], hdown[i + 1], solUp)) {
            solDown = hdown[i];
            break;
        }

    printf("%d %d %d %d", solUp.x, solUp.y, solDown.x, solDown.y);
    return 0;
}
