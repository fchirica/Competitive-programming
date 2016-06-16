//sa cheltuim banii banii ca ni se duc anii anii..

#include <stdio.h>

int N, M, S, F, c[15][15];
int dp[115];

int solveDP(int xx, int yy, int sum) {
    for (int i = 1; i <= sum; ++i)
        dp[i] = -1000000;
    dp[0] = 0;
    for (int i = 1; i <= M; ++i) {
        int A = c[xx][i];
        int B = c[yy][i];
        for (int j = sum; j >= 0; --j) {
            int go = j + A;
            if (go > sum)
                continue;
            if (dp[j] + B > dp[go])
                dp[go] = dp[j] + B;
        }
    }
    int res = 0;
    for (int i = 1; i <= sum; ++i)
        if (dp[i] + sum - i > res)
            res = dp[i] + sum - i;
    return res;
}

int solve(int sum) {
    int best = sum;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            int cur = solveDP(i, j, sum);
            if (cur > best)
                best = cur;
        }
    return best;
}

int main() {
    freopen("piete.in", "r", stdin);
    freopen("piete.out", "w", stdout);

    scanf("%d%d%d%d", &N, &M, &S, &F);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &c[i][j]);

    int sol = 0;
    while (S < F) {
        ++sol;
        int newS = solve(S);
        if (newS <= S) {
            printf("-1");
            return 0;
        }
        S = newS;
    }

    printf("%d", sol);
    return 0;
}
