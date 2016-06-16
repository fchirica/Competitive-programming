#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct point {
    long long x, y;
} x[11];

inline long long ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

inline long long getArea(point A, point B, point C) {
    long long area = ccw(A, B, C);
    return area > 0 ? area : -area;
}

bool pointInTri(point P, point A, point B, point C) {
    long long area1 = getArea(P, A, B);
    long long area2 = getArea(P, B, C);
    long long area3 = getArea(P, A, C);
    long long areatot = getArea(A, B, C);
    return area1 + area2 + area3 == areatot;
}

double Ox, Oy;
inline bool comp(int idxA, int idxB) {
    point A = x[idxA], B = x[idxB];
    double ang1 = atan2(A.y - Oy, A.x - Ox);
    double ang2 = atan2(B.y - Oy, B.x - Ox);
    return ang1 - ang2 <= -0.0000000001;
}

void sortClockWise(int i, int j, int k, int l, int m) {
    int index[10];
    index[1] = i;
    index[2] = j;
    index[3] = k;
    index[4] = l;
    index[5] = m;

    Ox = 0; Oy = 0;
    for (i = 1; i <= 5; ++i) {
        Ox += x[index[i]].x;
        Oy += x[index[i]].y;
    }
    Ox = Ox / 5; Oy = Oy / 5;

    sort(index + 1, index + 6, comp);
    for (i = 1; i <= 5; ++i)
        printf("%d ", index[i]);
}

bool isConvex(int i, int j, int k, int l, int m) {
    point cur[6];
    cur[1] = x[i];
    cur[2] = x[j];
    cur[3] = x[k];
    cur[4] = x[l];
    cur[5] = x[m];
    for (i = 1; i <= 5; ++i)
        for (j = 1; j <= 5; ++j)
            for (k = 1; k <= 5; ++k)
                for (l = 1; l <= 5; ++l) {
                    if (l == i || l == j || l == k)
                        continue;
                    if (i == j || j == k || i == k)
                        continue;
                    if (pointInTri(cur[l], cur[i], cur[j], cur[k]))
                        return false;
                }
    return true;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int i, N;
    cin >> N;
    if (N > 10)
        N = 10;
    for (i = 1; i <= N; ++i)
        cin >> x[i].x >> x[i].y;

    int j, k, l, m;
    for (i = 1; i <= N; ++i)
        for (j = i + 1; j <= N; ++j)
            for (k = j + 1; k <= N; ++k)
                for (l = k + 1; l <= N; ++l)
                    for (m = l + 1; m <= N; ++m)
                        if (isConvex(i, j, k, l, m)) {
                            printf("Yes\n");
                            sortClockWise(i, j, k, l, m);
                            return 0;
                        }

    printf("No\n");
    return 0;
}
