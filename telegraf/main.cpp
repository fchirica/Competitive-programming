#include <bits/stdc++.h>

using namespace std;

int n, frequences[40], psum[40];
int dp[40][40][40];

int solve(int curIntern, int prevIntern, int curLeafs) {
    if (curLeafs == n && curIntern == 1 && prevIntern == 0)
        return 0;
    if (dp[curIntern][prevIntern][curLeafs] != -1)
        return dp[curIntern][prevIntern][curLeafs];
    dp[curIntern][prevIntern][curLeafs] = 1 << 30;
    int res = 1 << 29;
    for (int leafs = curLeafs; leafs <= n; ++leafs) {
        int level_leafs = leafs - curLeafs;
        int nextIntern = curIntern + level_leafs - prevIntern;
        if (nextIntern < 0)
            continue;
        int foo = solve(prevIntern, nextIntern, leafs) + psum[leafs];
        res = min(res, foo);
    }
    return dp[curIntern][prevIntern][curLeafs] = res;
}

int main() {
    freopen("telegraf.in", "r", stdin);
    freopen("telegraf.out", "w", stdout);

    for (int i = 1; i <= 36; ++i) {
        int foo;
        scanf("%d", &foo);
        if (foo)
            frequences[++n] = foo;
    }

    sort(frequences + 1, frequences + n + 1);
    for (int i = 1; i <= n; ++i)
        psum[i] = psum[i - 1] + frequences[i];
    memset(dp, -1, sizeof(dp));

    int res = 1 << 29;
    for (int i = 0; i <= n; ++i)
        res = min(res, solve(0, i, 0));
    printf("%d", res);
    return 0;
}
