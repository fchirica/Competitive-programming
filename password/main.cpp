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

char x[20020];

int main() {
    read(tests); scanf("\n");
    FOR(test, tests) {
        gets(x + 1);
        int n = strlen(x + 1);
        REP(i, n + 1, 2 * n)
            x[i] = x[i - n];

        int best = 1, i = 2, L = 0;
        while (i <= n && best + L + 1 <= n) {
            if (x[i + L] == x[best + L])
                ++L;
            if (x[i + L] > x[best + L])
                i = i + L + 1, L = 0;
            if (x[i + L] < x[best + L])
                best = max(best + L + 1, i), i = best + 1, L = 0;
        }
        printf("%d\n", best);
    }

    return 0;
}
