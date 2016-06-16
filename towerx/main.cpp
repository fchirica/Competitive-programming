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

using namespace std;

int dp[2][10100], ret[10100], sol[10100];

int findNext(int pos, int times, int n) {
    while (times) {
        if (sol[pos] == 0)
            --times;
        if (times) {
            ++pos;
            if (pos == n + 1)
                pos = 1;
        }
    }
    return pos;
}

int main() {
    freopen("towerx.in", "r", stdin);
    freopen("towerx.out", "w", stdout);

    read(n);
    FOR(i, n) {
        dp[i & 1][1] = 1;
        REP(j, 2, i) {
            dp[i & 1][j] = dp[i & 1][j - 1] + dp[(i - 1) & 1][j - 1];
            if (dp[i & 1][j] > i)
                dp[i & 1][j] -= i;
        }
        ret[i] = dp[i & 1][i];
    }

    int pos = 1;
    REPD(i, n, 1) {
        pos = findNext(pos, ret[i], n);
        sol[pos] = i;
    }
    FOR(i, n)
        printf("%d ", sol[i]);
    return 0;
}
