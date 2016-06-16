#include <stdio.h>
#include <vector>

using namespace std;

int x[11][1111], pos[11][1111];
vector <int> G[1111];
int dp[1111], vis[1111];

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it) {
        if (!vis[*it])
            dfs(*it);
        if (dp[nod] < dp[*it])
            dp[nod] = dp[*it];
    }
    ++dp[nod];
}

int main() {
    freopen("permlcs.in", "r", stdin);
    freopen("permlcs.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &x[i][j]);
            pos[i][x[i][j]] = j;
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            bool allOk = true;
            for (int k = 1; allOk && k <= m; ++k)
                if (pos[k][i] >= pos[k][j])
                    allOk = false;
            if (allOk)
                G[i].push_back(j);
        }

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);

    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (dp[i] > res)
            res = dp[i];
    printf("%d", res);
    return 0;
}
