//Florin Chirica

#include <bits/stdc++.h>

using namespace std;

struct obiect {
    int weight;
    int profit;
} x[100010], new_x[100010];

inline bool comp(obiect A, obiect B) {
    if (A.weight == B.weight)
        return A.profit > B.profit;
    return A.weight < B.weight;
}

int dp[1111];

int main() {
    freopen("ruksak.in", "r", stdin);
    freopen("ruksak.out", "w", stdout);

    int n, g;
    scanf("%d%d", &n, &g);
    int delta = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x[i].weight, &x[i].profit);
        if (x[i].weight == 0)
            delta += x[i].profit;
    }
    sort(x + 1, x + n + 1, comp);
    int len = 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (x[i].weight == x[i + 1].weight)
            ++len;
        else {
            if (x[i].weight != 0) {
                int lim = g / x[i].weight;
                for (int j = i - len + 1; j <= i && lim > 0; ++j, --lim)
                    if (x[j].weight != 0)
                        new_x[++cnt] = x[j];
            }
            len = 1;
        }
    }
    for (int i = 1; i <= cnt; ++i)
        for (int j = g; j >= 0; --j)
            if (new_x[i].weight + j <= g)
                dp[new_x[i].weight + j] = max(dp[new_x[i].weight + j], dp[j] + new_x[i].profit);
    int res = 0;
    for (int j = 0; j <= g; ++j)
        if (dp[j] > res)
            res = dp[j];
    printf("%d", res + delta);
    return 0;
}
