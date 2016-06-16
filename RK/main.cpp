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
#define B 73
#define MOD1 100007
#define MOD2 100021

using namespace std;

char pat[2000100], S[2000100];
int matches[2000100];

int main() {
    freopen("strmatch.in", "r", stdin);
    freopen("strmatch.out", "w", stdout);

    gets(pat + 1); gets(S + 1);
    int cntP = strlen(pat + 1), cntS = strlen(S + 1);
    if (cntP > cntS) {
        printf("0");
        return 0;
    }

    unsigned hash1 = 0, cur1 = 0, pw1 = 1, cpw1;
    for (int i = cntP; i >= 1; --i) {
        cpw1 = pw1;
        hash1 += pw1 * pat[i];
        cur1 += pw1 * S[i];
        pw1 *= B;
    }

    pw1 = cpw1;
    REP(i, cntP, cntS) {
        if (cur1 == hash1)
            matches[++matches[0]] = i - cntP;
        cur1 = (cur1 - pw1 * S[i - cntP + 1]) * B + S[i + 1];
    }

    printf("%d\n", matches[0]);
    chmin(matches[0], 1000);
    FOR(i, matches[0])
        printf("%d ", matches[i]);
    return 0;
}
