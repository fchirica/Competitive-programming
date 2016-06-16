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
#define REPD(i, a, b) for(int i = a; i >= b; --i)
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
#define pb push_back
#define pair <int, int> pii

using namespace std;

int mars[2012][2012], lg[2012];
bool RMQ[12][2012][2012];

inline bool possible(int i, int j, int len) {
    int pw = lg[len];
    int val = RMQ[pw][i][j] & RMQ[pw][i - (1 << pw) + 1][j] & RMQ[pw][i][j - (1 << pw) + 1] & RMQ[pw][i - (1 << pw) + 1][j - (1 << pw) + 1];
    return val;
}

inline int gauss(int X) {
    return X * (X + 1) / 2;
}

int main() {
    freopen("rectangles.in", "r", stdin);
    freopen("rectangles.out", "w", stdout);

    read(n);
    FOR(i, n) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        swap(x1, y1); swap(x2, y2);
        if (x1 > x2)
            swap(x1, x2), swap(y1, y2);
        if (y1 > y2)
            swap(y1, y2);
        ++x1; ++y1;
        ++mars[x1][y1]; --mars[x2 + 1][y1]; --mars[x1][y2 + 1]; ++mars[x2 + 1][y2 + 1];
    }

    int maxSize = 2001;
    REP(i, 2, maxSize)
        lg[i] = lg[i / 2] + 1;

    FOR (i, maxSize)
        FOR (j, maxSize) {
            mars[i][j] += mars[i - 1][j] + mars[i][j - 1] - mars[i - 1][j - 1];
            RMQ[0][i][j] = mars[i][j] ? 1 : 0;
        }

    FOR(pw, 11)
        FOR(i, maxSize)
            FOR(j, maxSize) {
                if ((1 << pw) + i - 1 > maxSize || (1 << pw) + j - 1 > maxSize)
                    break;
                RMQ[pw][i][j] = RMQ[pw - 1][i][j] & RMQ[pw - 1][i + (1 << (pw - 1))][j] &
                                RMQ[pw - 1][i][j + (1 << (pw - 1))] & RMQ[pw - 1][i + (1 << (pw - 1))][j + (1 << (pw - 1))];
            }

    ll res = 0;
    FOR(i, maxSize)
        FOR(j, maxSize) {
            int st = 1, dr = maxSize, med, sol = 0;
            while (st <= dr) {
                med = (st + dr) / 2;
                if (possible(i, j, med))
                    sol = med, st = med + 1;
                else
                    dr = med - 1;
            }
            res += gauss(sol);
        }

    printf("%lld", res);
    return 0;
}
