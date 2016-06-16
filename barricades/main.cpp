#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <short> G[3001], L[3001];

int n;
short dp[3001][3001], subTree[3001], vis[3001];

void dfs(int nod) {
    vis[nod] = 1;
    subTree[nod] = 1;

    vector <short> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs(*it);
            L[nod].push_back(*it);
            subTree[nod] += subTree[*it];
        }
}

int _min(short A, short B) {
    return A < B ? A : B;
}

void dfs2(int nod) {
    if (L[nod].size() == 0) {
        dp[nod][1] = 0;
        return ;
    }

    short dp2[2][3001];

    vector <short> :: iterator it;
    for (it = L[nod].begin(); it != L[nod].end(); ++it)
        dfs2(*it);

    for (int j = 0; j <= subTree[nod]; ++j)
        dp2[0][j] = n + 1;
    dp2[0][1] = 0;
    int prev = 0;

    for (it = L[nod].begin(); it != L[nod].end(); ++it) {
        int act = 1 - prev;
        for (int i = 1; i <= subTree[nod]; ++i) {
            dp2[act][i] = 1 + dp2[prev][i];
            for (int j = 1; j <= subTree[*it] && j < i; ++j)
                dp2[act][i] = _min((short) dp2[act][i], (short) dp[*it][j] + (short) dp2[prev][i - j]);
        }
        prev = act;
    }

    for (int i = 1; i <= subTree[nod]; ++i)
        dp[nod][i] = dp2[prev][i];

}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = n + 1;

    dfs(1);
    dfs2(1);

    int q;
    scanf("%d", &q);
    while (q--) {
        int xx, res = n + 1;
        scanf("%d", &xx);
        for (int i = 1; i <= n; ++i)
            res = min(res, dp[i][xx] + (i != 1));
        if (res == n + 1)
            res = -1;
        printf("%d\n", res);
    }

    return 0;
}
