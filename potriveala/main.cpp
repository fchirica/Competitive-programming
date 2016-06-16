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

using namespace std;

const unsigned B = 73;

int N, M[22];
char x[3][250010];
unsigned hsh[22][250010], pw[250010];

unsigned get(int i, int j, int len) {
    return hsh[i][j] - hsh[i][j + len] * pw[len];
}

unsigned tmp[250010], H[250010];

inline bool possible(int len) {
    int cntH = 0;
    FOR(i, N) {
        tmp[0] = 0;
        FOR(j, M[i] - len + 1) {
            unsigned curhsh = get(i, j, len);
            tmp[++tmp[0]] = curhsh;
        }
        sort(tmp + 1, tmp + tmp[0] + 1);
        H[++cntH] = tmp[1];
        REP(j, 2, tmp[0])
            if (tmp[j] != tmp[j - 1])
                H[++cntH] = tmp[j];
    }
    sort(H + 1, H + cntH + 1);
    int same = 1;
    FOR(i, cntH) {
        if (H[i] == H[i + 1]) {
            ++same;
            if (same == N)
                return true;
        } else
            same = 1;
    }
    return false;
}

int main() {
    freopen("potriveala.in", "r", stdin);
    freopen("potriveala.out", "w", stdout);

    pw[0] = 1;
    FOR(i, 250000)
        pw[i] = pw[i - 1] * B;

    int tests = 1;
    FOR(test, tests) {
        N = 2;
        int right = 100000;
        FOR(i, N) {
            gets(x[i] + 1);
            M[i] = strlen(x[i] + 1);
        }
        right = M[1];
        FOR(i, right)
            if (i > M[2])
                x[2][i] = x[2][i - M[2]];
        M[2] = right;

        FOR(i, N) {
            hsh[i][M[i] + 1] = 0;
            REPD(j, M[i], 1)
                hsh[i][j] = x[i][j] + B * hsh[i][j + 1];
        }
        int left = 1, med, best = 0;
        while (left <= right) {
            med = (left + right) / 2;
            if (possible(med))
                best = med, left = med + 1;
            else
                right = med - 1;
        }
        printf("%d\n", best);
    }

    return 0;
}

