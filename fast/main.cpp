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
#include <cassert>

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

int x[2 * 1000000];

int main() {
    read(n);
    freopen("text.in", "r", stdin);
    FOR(i, 2 * n)
        scanf("%d", &x[i]);
    REP(i, n + 1, 2 * n)
        if (x[i] != x[i - n])
            cerr << "randul " << i - n << "\n";
    return 0;
}
