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
char x[22][10010];
unsigned hash[22][10010], pw[10100];

unsigned get(int i, int j, int len) {
    return hash[i][j] - hash[i][j + len] * pw[len];
}

unsigned tmp[10100], H[100100];
int pos[10100];

inline bool comp(int A, int B) {
    return tmp[A] < tmp[B];
}

inline bool possible(int len) {
    int cntH = 0;
    FOR(i, N) {
        tmp[0] = 0;
        FOR(j, M[i] - len + 1) {
            unsigned curHash = get(i, j, len);
            tmp[++tmp[0]] = curHash;
            pos[tmp[0]] = j;
        }
        sort(pos + 1, pos + tmp[0] + 1, comp);
        int same = 1, mi = pos[1], ma = pos[1];
        pos[tmp[0] + 1] = tmp[0] + 1; tmp[tmp[0] + 1] = tmp[tmp[0]] + 1;
        REP(j, 1, tmp[0])
            if (tmp[pos[j]] == tmp[pos[j + 1]]) {
                ++same;
                chmin(mi, pos[j + 1]);
                chmax(ma, pos[j + 1]);
            }
            else {
                if (same > 1 && mi + len <= ma)
                    H[++cntH] = tmp[pos[j]];
                same = 1;
                mi = pos[j + 1];
                ma = pos[j + 1];
            }
    }
    sort(H + 1, H + cntH + 1);
    int same = 1;
    H[cntH + 1] = H[cntH] + 1;
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
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    pw[0] = 1;
    FOR(i, 10000)
        pw[i] = pw[i - 1] * B;
    read(tests);
    FOR(test, tests) {
        scanf("%d\n", &N);
        int right = 100000;
        FOR(i, N) {
            gets(x[i] + 1);
            M[i] = strlen(x[i] + 1);
            chmin(right, M[i]);
        }
        FOR(i, N) {
            hash[i][M[i] + 1] = 0;
            REPD(j, M[i], 1)
                hash[i][j] = x[i][j] + B * hash[i][j + 1];
        }
        possible(2);
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
