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
#define EPS 0.000000001
#define PI 3.141

using namespace std;

point T1, T2, x[1024];

double dist(point A, point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

inline bool comp(point A, point B) {
    return dist(T1, A) - dist(T1, B) <= -EPS;
}

inline bool pointInCircle(point A, point O, double R) {
    return dist(O, A) - R < -EPS || fabs(dist(O, A) - R) <= EPS;
}

int main() {
    read(n);
    int testCnt = 0;
    while (n) {
        ++testCnt;
        double area;
        scanf("%lf%lf%lf%lf%lf", &T1.x, &T1.y, &T2.x, &T2.y, &area);
        FOR(i, n)
            scanf("%lf%lf", &x[i].x, &x[i].y);
        x[0] = T1;
        sort(x, x + n + 1, comp);
        int sol = n + 1;
        REP(i, 0, n) {
            double chosenR = dist(x[i], T1);
            if (PI * chosenR * chosenR - area > EPS)
                break;
            double otherR = sqrt(area / PI - chosenR * chosenR);
            int missed = 0;
            REP(j, i + 1, n)
                if (pointInCircle(x[j], T2, otherR) == false)
                    ++missed;
            chmin(sol, missed);
        }
        printf("%d. %d\n", testCnt, sol);
        scanf("%d", &n);
    }
    return 0;
}
