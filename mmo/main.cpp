#include <stdio.h>
#include <vector>

using namespace std;

struct edge {
    int to, cost;
};

vector <edge> G[22];
int rf[22][22], deg[22], dp[1 << 18];

edge make(int xx, int yy) {
    edge tmp;
    tmp.to = xx;
    tmp.cost = yy;
    return tmp;
}

inline void chmin(int &A, int B) {
    if (A > B)
        A = B;
}

int main() {
    freopen("mmo.in", "r", stdin);
    freopen("mmo.out", "w", stdout);

    int n, m, res = 0;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            rf[i][j] = (i == j) ? 0 : (1 << 29);

    for (int i = 1; i <= m; ++i) {
        int xx, yy, cc;
        scanf("%d%d%d", &xx, &yy, &cc);
        ++deg[xx]; ++deg[yy];
        G[xx].push_back(make(yy, cc));
        G[yy].push_back(make(xx, cc));
        rf[xx][yy] = rf[yy][xx] = cc;
        res += cc;
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                chmin(rf[i][j], rf[i][k] + rf[k][j]);

    int target = 0;
    for (int i = 0; i < n; ++i)
        if (deg[i + 1] % 2)
            target += (1 << i);

    for (int i = 1; i <= target; ++i)
        dp[i] = 1 << 30;
    for (int mask = 0; mask <= target; ++mask)
        for (int pair1 = 1; pair1 <= n; ++pair1)
            if (deg[pair1] % 2 && (mask & (1 << (pair1 - 1))) == 0)
                for (int pair2 = 1; pair2 <= n; ++pair2)
                    if (deg[pair2] % 2 && (mask & (1 << (pair2 - 1))) == 0)
                        if (pair1 != pair2)
                            chmin(dp[mask ^ (1 << (pair1 - 1)) ^ (1 << (pair2 - 1))], dp[mask] + rf[pair1][pair2]);

    res -= dp[target];
    printf("%d", res);

    return 0;
}
