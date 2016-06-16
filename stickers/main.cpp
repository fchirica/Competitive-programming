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
#define REPD(i, a, b) for(int i = a; i >= b; --i)
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
#define INF (1 << 30)

using namespace std;

char pat[55][55];
char S[10100];
int pref[10100], suf[10100], bet[10100], dp2[10100], dp[10100];

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int N, M;
    scanf("%d%d\n", &N, &M);
    FOR(i, N)
        gets(pat[i] + 1);
    gets(S + 1);
    int cnt = strlen(S + 1);

    FOR(i, cnt - M + 1)
        FOR(j, N) {
            int idxi = i;
            FOR(k, M)
                if (pat[j][k] == S[idxi])
                    ++idxi;
                else
                    break;
            chmax(pref[i], idxi - i);
        }

    REP(i, M, cnt)
        FOR(j, N) {
            int sf = 0;
            for (int k = i; sf < M; --k)
                if (S[k] == pat[j][M - sf])
                    ++sf;
                else
                    break;
            chmax(suf[i], sf);
        }

    FOR(i, cnt)
        FOR(j, N)
            FOR(k, M) {
                if (i - (k - 1) <= 0)
                    continue;
                if (i - (k - 1) + M - 1 > cnt)
                    continue;
                int matched = 0;
                for (int l = k; l >= 1; --l)
                    if (S[i - matched] == pat[j][l])
                        ++matched;
                    else
                        break;
                chmax(bet[i], matched);
            }

    FOR(i, cnt) {
        dp[i] = dp2[i] = 1 << 30;
        if (suf[i] == M)
            chmin(dp[i], 1 + dp2[i - M]);
        FOR(j, suf[i])
           chmin(dp[i], 1 + dp[i - j]);
        if (i < M)
            dp[i] = 1 << 30;
        dp2[i] = dp[i];
        for (int j = i - M + 1; j <= i; ++j)
            if (j + pref[j] >= i)
                chmin(dp2[i], 1 + dp[j - 1]);
        FOR(j, bet[i])
            chmin(dp2[i], 1 + dp[i - j]);
    }

    if (dp[cnt] == 1 << 30)
        printf("NO");
    else
        printf("%d", dp[cnt]);
    return 0;
}
