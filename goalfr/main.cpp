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
#define point pair <double, double>

using namespace std;

inline bool intersect(point A, point O, double r, point B) {
    A.x -= O.x; A.y -= O.y; B.x -= O.x; B.y -= O.y;
    double m = -(A.y - B.y) / (B.x - A.x);
    double n = -(A.x * B.y - A.y * B.x) / (B.x - A.x);
    double a = 1 + m * m;
    double b = 2 * m * n;
    double c = n * n - r * r;
    double delta = b * b - 4 * a * c;
    if (delta >= 0)
        return true;
    return false;
}

int main() {
    read(testCnt);
    FOR(test, testCnt) {
        point from, O, to = mp(52.5, 3.66), to2 = mp(52.5, -3.66);
        double R;
        scanf("%lf %lf %lf %lf %lf", &from.x, &from.y, &O.x, &O.y, &R);
        if (intersect(from, O, R, to) && intersect(from, O, R, to2))
            printf("No goal...\n");
        else
            printf("Goal!\n");
    }
    return 0;
}
