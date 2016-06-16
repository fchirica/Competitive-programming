#include <stdio.h>
#include <math.h>

struct point {
    double x, y;

    void get() {
        int _x, _y;
        scanf("%d%d", &_x, &_y);
        x = _x; y = _y;
    }
} P[3100], fi[3100], se[3100];
point rect[10];

int N, M;

bool isTest() {
    scanf("%d%d", &N, &M);
    if (N + M == 0)
        return 0;
    int i;
    for (i = 1; i <= N; ++i)
        P[i].get();
    for (i = 1; i <= M; ++i)
        fi[i].get(), se[i].get();
    return 1;
}

inline point mp(double X, double Y) {
    point tmp;
    tmp.x = X; tmp.y = Y;
    return tmp;
}

inline int ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x) > 0 ? 1 : -1;
}

inline bool intersect(point x0, point y0, point x1, point y1) {
    double sgn1 = ccw(x0, y0, x1);
    sgn1 = sgn1 * ccw(x0, y0, y1);
    double sgn2 = ccw(x1, y1, x0);
    sgn2 = sgn2 * ccw(x1, y1, y0);
    return sgn1 < 0 && sgn2 < 0;
}

bool solveTest() {
    //Only vertical or horizontal lines in polygon
    P[++N] = P[1];
    int i;
    for (i = 1; i < N; ++i) {
        bool valid = false;
        if (P[i].x == P[i + 1].x)
            valid = true;
        if (P[i].y == P[i + 1].y)
            valid = true;
        if (valid == false)
            return 0;
    }
    //Get the area of the polygon
    double area = 0, area2 = 0;
    for (i = 1; i < N; ++i)
        area += (P[i].x * P[i + 1].y - P[i].y * P[i + 1].x) * 0.5;
    if (area < 0)
        area = -area;
    //Process each rectangle
    for (i = 1; i <= M; ++i) {
        //Make it to a "polygon" form
        if (fi[i].x > se[i].x) {
            point tmp;
            tmp = fi[i];
            fi[i] = se[i];
            se[i] = tmp;
        }
        if (fi[i].y < se[i].y) {
            rect[1] = fi[i];
            rect[2] = mp(se[i].x, fi[i].y);
            rect[3] = se[i];
            rect[4] = mp(fi[i].x, se[i].y);
            rect[5] = rect[1];
        } else {
            rect[1] = mp(fi[i].x, se[i].y);
            rect[2] = se[i];
            rect[3] = mp(se[i].x, fi[i].y);
            rect[4] = fi[i];
            rect[5] = rect[1];
        }
        //Area of the current rectangle
        double curArea = 0;
        for (int j = 1; j < 5; ++j)
            curArea += (rect[j].x * rect[j + 1].y - rect[j].y * rect[j + 1].x) * 0.5;
        if (curArea < 0)
            curArea = -curArea;
        //Transform it to a "smaller" rectangle included in the current one
        double deltax = 0.5, deltay = 0.4;
        rect[1].x += deltax; rect[1].y += deltay;
        rect[2].x -= deltax; rect[2].y += deltay;
        rect[3].x -= deltax; rect[3].y -= deltay;
        rect[4].x += deltax; rect[4].y -= deltay;
        rect[5].x += deltax; rect[5].y += deltay;
        //Check if it's included
        bool included = true;
        point O, O2;
        O.x = (rect[1].x + rect[3].x) * 0.5;
        O.y = (rect[1].y + rect[3].y) * 0.5;
        O2.x = 1 << 30; O2.y = O.y;
        int j, cnt = 0;
        for (j = 1; j < N; ++j)
            if (intersect(O, O2, P[j], P[j + 1]))
                ++cnt;
        included = cnt % 2;
        int k;
        for (j = 1; j <= 4; ++j)
            for (k = 1; k < N && included; ++k)
                if (intersect(rect[j], rect[j + 1], P[k], P[k + 1]))
                    included = false;
        area2 += included * curArea;
    }
    return fabs(area - area2) <= 0.000000001;
}

int main() {
    freopen("hardq.in", "r", stdin);
    freopen("hardq.out", "w", stdout);

    while(isTest()) {
        int val = solveTest();
        printf("%s\n", val ? "YES" : "NO");
    }

    return 0;
}
