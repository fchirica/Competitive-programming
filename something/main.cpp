#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector <int> G[100100], sons[100100];

int cycleX = -1, cycleY = -1, res[100100], dad[100100];
bool vis[100100];

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dad[*it] = nod;
            dfs(*it);
        }
        else if (dad[nod] != *it) {
            cycleY = nod;
            cycleX = *it;
        }
}

void dfs2(int nod, int c) {
    vis[nod] = 1;
    res[nod] = c;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            dfs2(*it, c);
}

int main() {
    freopen("something.in", "r", stdin);
    freopen("something.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        res[i] = 1;
    for (int i = 1; i <= m; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    dfs(1);
    memset(vis, 0, sizeof(vis));

    if (cycleX == -1) {
        printf("-1");
        return 0;
    }

    int nod = cycleX;
    while (1) {
        vis[nod] = 1;
        if (nod == cycleY)
            break;
        nod = dad[nod];
    }

    for (int i = 1; i <= n; ++i)
        res[i] = 1;
    dfs2(cycleX, 2);
    dfs2(cycleY, 3);

    for (int i = 1; i <= n; ++i)
        printf("%d ", res[i]);
    return 0;
}
