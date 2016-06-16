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

vector <int> G[22000];
int dist[22000], Q[22000];

int main() {
    freopen("amici2.in", "r", stdin);
    freopen("amici2.out", "w", stdout);

    read(t);
    FOR(test, t) {
        read2(n, m);
        FOR (i, n) {
            G[i].clear();
            dist[i] = 0;
        }
        FOR (i, m) {
            read2(X0, Y0);
            G[X0].pb(Y0);
            G[Y0].pb(X0);
        }
        int p = 1, u = 0, ans = 0;
        Q[++u] = 1; dist[1] = 1;
        while (p <= u) {
            for (auto it : G[Q[p]])
                if (dist[it] == 0) {
                    dist[it] = dist[Q[p]] + 1;
                    Q[++u] = it;
                    chmax(ans, dist[it] - 1);
                }
            ++p;
        }
        int pw = 0;
        for (; (1 << pw) < ans; ++pw);
        printf("%d\n", pw);
    }

    return 0;
}
