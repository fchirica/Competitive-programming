//sursa facuta inspirandu-ma de la briliantul Romaniei, Rares Buhai :)
//http://www.youtube.com/watch?v=tXO2QtjixaM

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp[6][30010], best[30010];
vector <int> V[30010];

const int INF = 1 << 30;

void chmin(int &A, int B) {
    if (B < A)
        A = B;
}

int main() {
    freopen("magazin.in", "r", stdin);
    freopen("magazin.out", "w", stdout);

    int P, N, M, D;
    scanf("%d%d%d%d", &P, &N, &M, &D);
    ++M;
    for (int i = 1; i <= P; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        V[xx].push_back(yy);
    }

    for (int i = 1; i <= N; ++i) {
        if (!V[i].size())
            continue;
        sort(V[i].begin(), V[i].end());
        best[i] = 2 * (M - V[i].front());
        chmin(best[i], 2 * V[i].back());
        for (int j = 0; j < V[i].size() - 1; ++j)
            chmin(best[i], 2 * (V[i][j] + M - V[i][j + 1]));
    }

    if (V[1].size())
        dp[0][1] = 2 * V[1].back();
    dp[1][1] = 2 * M;
    dp[2][1] = best[1];
    dp[3][1] = dp[4][1] = M;
    dp[5][1] = INF;

    for (int i = 2; i <= N; ++i) {
        dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + D;
        if (V[i].size())
            dp[0][i] += 2 * V[i].back();

        dp[1][i] = dp[0][i - 1] + D + 2 * M;
        chmin(dp[1][i], dp[1][i - 1] + 3 * D + best[i]);
        chmin(dp[1][i], dp[2][i - 1] + 3 * D + 2 * M);
        chmin(dp[1][i], dp[3][i - 1] + D + M);
        chmin(dp[1][i], dp[5][i - 1] + 3 * D + M);

        dp[2][i] = dp[0][i - 1] + D + best[i];
        chmin(dp[2][i], dp[2][i - 1] + 3 * D + best[i]);

        dp[3][i] = min(dp[3][i - 1], dp[4][i - 1]) + D;
        if (V[i].size())
            dp[3][i] += 2 * (M - V[i].front());

        dp[4][i] = dp[0][i - 1] + D + M;
        chmin(dp[4][i], dp[2][i - 1] + 3 * D + M);
        chmin(dp[4][i], dp[3][i - 1] + D + 2 * M);
        chmin(dp[4][i], dp[4][i - 1] + 3 * D + best[i]);
        chmin(dp[4][i], dp[5][i - 1] + 3 * D + 2 * M);

        dp[5][i] = dp[3][i - 1] + D + best[i];
        chmin(dp[5][i], dp[5][i - 1] + 3 * D + best[i]);

        chmin(dp[0][i], dp[1][i]);
        chmin(dp[3][i], dp[4][i]);
    }

    printf("%d", min(dp[0][N], dp[1][N]));
    return 0;
}
