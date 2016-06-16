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

pair <int, int> col[1600], cntSort[1600 * 1600];
int x[1600][1600];

void update(int j0, int j1, int xx, int yy) {
    REP(j, j0, j1) {
        chmax(col[j].x, xx);
        chmin(col[j].y, yy);
    }
}

void dfs(int xx, int yy) {
    if (col[yy].x <= xx && xx <= col[yy].y) {
        printf("%d ", x[xx][yy]);
        dfs(xx + 1, yy);
        dfs(xx, yy + 1);
    }
}

int main() {
    freopen("bemo.in", "r", stdin);
    freopen("bemo.out", "w", stdout);

    read2(N, M);
    FOR(i, N)
        FOR(j, M) {
            scanf("%d", &x[i][j]);
            cntSort[x[i][j]] = mp(i, j);
        }

    FOR(j, M)
        col[j] = mp(1, N);

    FOR(val, N * M) {
        int i = cntSort[val].x, j = cntSort[val].y;
        if (col[j].x <= i && i <= col[j].y) {
            update(1, j - 1, 1, i);
            update(j + 1, M, i, N);
        }
    }

    dfs(1, 1);
    return 0;
}
