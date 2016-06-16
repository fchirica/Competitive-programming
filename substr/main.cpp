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

char x[100100];
int idx[100100], SA[19][100100];
ll key[100100];

struct comp {
    bool operator () (int i, int j) {
        return key[i] < key[j];
    }
};

void suffixArrays(int n) {
    for (int pw = 0; (1 << pw) <= 2 * n; ++pw) {
        FOR(i, n)
            SA[pw][i] = 0;
        if (pw)
            FOR(i, n) {
                key[i] = 1LL * SA[pw - 1][i] * max(n, 10000);
                if (i + (1 << (pw - 1)) <= n)
                    key[i] += SA[pw - 1][i + (1 << (pw - 1))];
                idx[i] = i;
            }
        if (pw == 0)
            FOR(i, n)
                key[i] = x[i], idx[i] = i;
        sort(idx + 1, idx + n + 1, comp());
        int cur = 0;
        FOR(i, n)
            if (i > 1 && key[idx[i]] == key[idx[i - 1]])
                SA[pw][idx[i]] = cur;
            else
                SA[pw][idx[i]] = ++cur;
    }
}

char word[1024];

inline int check(int which, int n, int cntW) {
    FOR(i, cntW) {
        if (which + i - 1 == n + 1)
            return -1;
        if (word[i] < x[which + i - 1])
            return 1;
        if (word[i] > x[which + i - 1])
            return -1;
    }
    return 0;
}

int main() {
    read(tests);
    scanf("\n");
    FOR(test, tests) {
        gets(x + 1);
        int n = strlen(x + 1);
        suffixArrays(n);
        read(Q); scanf("\n");
        FOR(query, Q) {
            gets(word + 1);
            int cntW = strlen(word + 1);
            int st = 1, dr = n, med;
            bool fount = false;
            while (st <= dr) {
                med = (st + dr) / 2;
                if (check(idx[med], n, cntW) == 0) {
                    fount = true;
                    break;
                }
                if (check(idx[med], n, cntW) < 0)
                    st = med + 1;
                else
                    dr = med - 1;
            }
            printf("%c\n", fount ? 'y' : 'n');
        }
    }
    return 0;
}
