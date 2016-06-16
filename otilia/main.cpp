#include <bits/stdc++.h>

using namespace std;

const int kPMax = 11;
const int kNMax = 5000100;
const int kInf = 1e9;

int nmax[kPMax], dp[kNMax], stk[kNMax];

struct query {
    int n, k, p, ans;
} q[33333];

int main() {
    freopen("otilia.in", "r", stdin);
    freopen("otilia.out", "w", stdout);

    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &q[i].n, &q[i].k, &q[i].p);
        nmax[q[i].p] = max(nmax[q[i].p], q[i].n);
    }

    for (int p = 1; p <= 10; ++p) {
        int len = 0;
        for (int i = 1; i <= nmax[p]; ++i) {
            while (len > 0 && dp[stk[len]] <= p * (i - stk[len]))
                --len;
            if (len)
                dp[i] = i - stk[len];
            else
                dp[i] = kInf;
            stk[++len] = i;
        }
        for (int i = 1; i <= m; ++i)
            if (q[i].p == p)
                q[i].ans = (dp[q[i].n] <= q[i].k) ? 1 : 0;
    }

    for (int i = 1; i <= m; ++i)
        printf("%d\n", q[i].ans);
    return 0;
}
