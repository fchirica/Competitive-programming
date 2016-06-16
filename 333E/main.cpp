#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FOR(i, n) REP(i, 1, n)
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define read(n) int (n); scanf("%d", &(n))
#define read2(n, m) int (n), (m); scanf("%d %d", &(n), &(m))
#define read3(n, m, k) int (n), (m), (k); scanf("%d %d %d", &(n), &(m), &(k))
#define ll long long
#define x first
#define y second
#define mp make_pair
#define point pair <int, int>

using namespace std;

point x[3100], X[3100], H[3100];
int D[3100 * 3100];
int dst[3100][3100];

inline int dist(point A, point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

inline int ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

int N;

void makeHull() {
    int hCnt = 0, cur = 3;
    H[++hCnt] = X[1]; H[++hCnt] = X[2];
    while (cur <= N)
        if (hCnt < 2 || ccw(H[hCnt - 1], H[hCnt], X[cur]) >= 0)
            H[++hCnt] = X[cur++];
        else
            --hCnt;
    H[++hCnt] = X[N - 1];
    cur = N - 2;
    int uppHull = 2;
    while (cur >= 1)
        if (uppHull < 2 || ccw(H[hCnt - 1], H[hCnt], X[cur]) >= 0)
            H[++hCnt] = X[cur--];
        else
            --hCnt, --uppHull;
    N = hCnt - 1;
}

int next(int x) {
    return x == N ? 1 : (x + 1);
}

inline bool possible(int n, int minDist) {
    FOR(i, n) {
        N = 0;
        FOR (j, n)
            if (dst[i][j] >= minDist)
                X[++N] = x[j];
        if (N < 2)
            continue;
        makeHull();
        int maxDist = 0;
        int idx2 = 1;
        FOR(idx1, N) {
            for (; dist(H[idx1], H[idx2]) < dist(H[idx1], H[next(idx2)]); idx2 = next(idx2));
            chmax(maxDist, dist(H[idx1], H[idx2]));
        }
        if (maxDist > minDist)
            return true;
    }
    return false;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    read(n);
    FOR(i, n)
        scanf("%d%d", &x[i].x, &x[i].y);

    sort(x + 1, x + n + 1);

    int cntD = 0;
    FOR(i, n)
        FOR(j, n) {
            dst[i][j] = dist(x[i], x[j]);
            if (i < j)
                D[++cntD] = dist(x[i], x[j]);
        }

    sort(D + 1, D + cntD + 1);

    int left = 1, right = cntD, med;
    double ret;
    while (left <= right) {
        int med = (left + right) / 2;
        if (possible(n, D[med])) {
            ret = D[med];
            left = med + 1;
        }
        else
            right = med - 1;
    }
    printf("%.10lf", sqrt((double)ret) * 0.5);
    return 0;
}
