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
#define B 73

using namespace std;

int N;
char S[1024];
unsigned hash[1024], pw[1024];
pair <unsigned, int> cnt[1024];

void buildHash() {
    hash[N + 1] = 0;
    REPD(i, N, 1)
        hash[i] = S[i] + B * hash[i + 1];
}

unsigned get(int i, int len) {
    return hash[i] - hash[i + len] * pw[len];
}

bool isBetter(int pos1, int pos2, int len) {
    int st = 1, dr = len, med, lcp = 0;
    while (st <= dr) {
        med = (st + dr) / 2;
        if (get(pos1, med) == get(pos2, med)) {
            lcp = med;
            st = med + 1;
        }
        else
            dr = med - 1;
    }
    return S[pos1 + lcp] < S[pos2 + lcp];
}

void solve(int len) {
    int cnt0 = 0;
    FOR(i, N - len + 1)
        cnt[++cnt0] = mp(get(i, len), i);
    sort(cnt + 1, cnt + cnt0 + 1);
    int cur = 1, pos, best = 0;
    FOR(i, cnt0)
        if (cnt[i].x == cnt[i + 1].x)
            ++cur;
        else {
            if (cur == best) {
                int pos2 = cnt[i].y;
                if (isBetter(pos2, pos, len))
                    pos = pos2;
            }
            if (cur > best) {
                best = cur;
                pos = cnt[i].y;
            }
            cur = 1;
        }
    printf("%d ", best);
    REP(i, pos, pos + len - 1)
        printf("%c", S[i]);
    printf("\n");
}

int main() {
    pw[0] = 1;
    FOR(i, 1000)
        pw[i] = pw[i - 1] * B;

    while (gets(S + 1)) {
        N = strlen(S + 1);
        FOR(i, N)
            if (isupper(S[i]))
                S[i] = tolower(S[i]);
        buildHash();
        int M;
        if (scanf("%d", &M) == EOF)
            break;
        while (M--) {
            read(len);
            solve(len);
        }
    }

    return 0;
}
