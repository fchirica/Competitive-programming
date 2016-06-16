#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <cmath>
#include <iostream>
#define point pair <int, int>
#define x first
#define y second
#define PI 2 * acos(0)

using namespace std;

point x[100100], P_N[200200];

inline int ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

inline double dist(point A, point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

inline int sccw(point A, point B, point C) {
    int _ccw = ccw(A, B, C);
    if (_ccw > 0)
        return _ccw;
    return -_ccw;
}

inline bool pointInSegm(point A, point B, point X) {
    return fabs(dist(A, X) + dist(X, B) - dist(A, B)) <= 0.0000001;
}

bool check(point A, point B, point C) {
    if (ccw(A, B, C) == 0)
        return pointInSegm(A, B, C);
    point O = make_pair(0, 0);
    int area1 = sccw(O, C, A);
    int area2 = sccw(A, C, B);
    int area3 = sccw(B, C, O);
    int area4 = sccw(O, A, B);
    return area1 + area2 + area3 == area4;
}

double angle(point A) {
    //Special cases
    if (A.y == 0)
        if (A.x >= 0)
            return 0;
        else
            return PI;
    if (A.x == 0)
        if (A.y > 0)
            return PI / 2;
        else
            return 3 * PI / 2;
    //
    double slope = fabs((double)A.y / A.x), alpha = atan(slope);
    if (A.x > 0 && A.y > 0)
        return alpha;
    if (A.x < 0 && A.y > 0)
        return PI - alpha;
    if (A.x < 0 && A.y < 0)
        return PI + alpha;
    return 2 * PI - alpha;
}

void solveTest() {
    int i, N, M, n = 0;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= N; ++i) {
        ++n;
        scanf("%d%d", &P_N[n].x, &P_N[n].y);
        if (n >= 3 && ccw(P_N[n - 2], P_N[n - 1], P_N[n]) == 0) {
            P_N[n - 1] = P_N[n];
            --n;
        }
    }
    //x[n - 1], x[n], x[1] collinear
    if (ccw(P_N[n - 1], P_N[n], P_N[1]) == 0)
        --n;
    N = n;

    //I change the order of polygon, such as x[1] is the one with lower angle
    for (i = N + 1; i <= 2 * N; ++i)
        P_N[i] = P_N[i - N];
    int where = 1;
    double ang = angle(P_N[1]);
    for (i = 2; i <= N; ++i)
        if (angle(P_N[i]) - ang <= -0.0000001) {
            where = i;
            ang = angle(P_N[i]);
        }
    for (i = 0; i < N; ++i)
        x[i + 1] = P_N[where + i];
    x[N + 1] = x[1];
    int sol = 0;
    point O = make_pair(0, 0);
    for (i = 1; i <= M; ++i) {
        point cur;
        scanf("%d%d", &cur.x, &cur.y);
        int left = 1, right = N - 1, med, idx = N;
        double wantedAngle = angle(cur);
        while (left <= right) {
            med = (left + right) / 2;
            int med2;
            for (med2 = med - 3; med2 <= med + 3; ++med2)
                if (med2 >= left && med2 <= right)
                    if (ccw(O, x[med2], x[med2 + 1]) != 0) {
                        med = med2;
                        break;
                    }
            if (angle(x[med]) - wantedAngle >= 0.000000001)
                right = med - 1;
            else if (wantedAngle - angle(x[med + 1]) >= 0.000000001)
                left = med + 1;
            else {
                idx = med;
                break;
            }
        }
        //Colinarity again
        //if (ccw(O, x[idx], cur) == 0 || ccw(O, x[idx + 1], cur) == 0) {
            for (int idx2 = idx - 3; idx2 <= idx + 3; ++idx2)
                if (idx2 > 0 && idx2 <= N)
                    if ((ccw(O, x[idx2], cur) == 0 && pointInSegm(O, x[idx2], cur))
                        || check(x[idx2], x[idx2 + 1], cur)) {
                            ++sol;
                            break;
                        }

        //else
        //    sol += check(x[idx], x[idx + 1], cur);
    }
    printf("%d\n", sol);
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
        solveTest();

    return 0;
}
