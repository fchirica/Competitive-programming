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

char s[1000100], S[2 * 1000100];
int ma[2 * 1000100];

int main() {
    freopen("pscpld.in", "r", stdin);
    freopen("pscpld.out", "w", stdout);

    gets(s + 1);
    int n = strlen(s + 1);
    int N = 0;
    FOR(i, n)
        S[++N] = s[i], S[++N] = '#';

    int O = 0, R = 0;
    ll sol = 0;
    FOR(i, N) {
        int r;
        if (i > O + R) {
            for (r = 0; i - r > 0 && i + r <= N && S[i - r] == S[i + r]; ++r); --r;
            ma[i] = r; R = r; O = i;
        } else {
            r = ma[2 * O - i];
            chmin(r, O + R - i);
            if (r == O + R - i) {
                for (; i - r > 0 && i + r <= N && S[i - r] == S[i + r]; ++r); --r;
                R = r; O = i;
            }
            ma[i] = r;
        }
        sol += i % 2 ? (r / 2 + 1) : ((r + 1) / 2);
    }

    printf("%lld", sol);
    return 0;
}

