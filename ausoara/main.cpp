#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define FOR(i, n) REP(i, 1, n)
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

int x[1024], ap[1000100], aptot[1000100], times[1000100];

int main() {
    freopen("ausoara.in", "r", stdin);
    freopen("ausoara.out", "w", stdout);

    read(n);
    FOR(i, n) {
        read(m);
        FOR(j, m) {
            scanf("%d", &x[j]);
            ++ap[x[j]];
        }
        FOR(j, m)
            if (ap[x[j]]) {
                if (times[x[j]] == i - 1) {
                    if (i == 1) aptot[x[j]] = ap[x[j]];
                    else chmin(aptot[x[j]], ap[x[j]]);
                    ++times[x[j]];
                }
                ap[x[j]] = 0;
            }
    }

    int sol = 0;
    FOR(i, 1000000)
        if (times[i] == n)
            sol += aptot[i];
    printf("%d ", sol);
    FOR(i, 1000000)
        if (times[i] == n)
            FOR(j, aptot[i])
                printf("%d ", i);
    return 0;
}
