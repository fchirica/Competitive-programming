#include <bits/stdc++.h>

using namespace std;

vector <int> G[100010];
vector <int> ans[100010];
vector <int> tree[100010];
int Ex[100010], Ey[100010];
bool inTree[100010];
bool vis[100010];

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it) {
        int otherNode = nod ^ Ex[*it] ^ Ey[*it];
        if (!vis[otherNode]) {
            inTree[*it] = 1;
            tree[nod].push_back(otherNode);
            dfs(otherNode);
        }
    }
}

void dfs2(int nod) {
    vector <int> :: iterator it;
    for (it = tree[nod].begin(); it != tree[nod].end(); ++it) {
        dfs2(*it);
        if (ans[*it].size() % 2)
            ans[*it].push_back(nod);
        else
            ans[nod].push_back(*it);
    }
}

int main() {
    freopen("drumuri.in", "r", stdin);
    freopen("drumuri.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    if (m % 2) {
        printf("0");
        return 0;
    }
    printf("1\n");
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &Ex[i], &Ey[i]);
        G[Ex[i]].push_back(i);
        G[Ey[i]].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= m; ++i)
        if (!inTree[i])
            ans[Ex[i]].push_back(Ey[i]);

    dfs2(1);

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < ans[i].size(); j += 2)
            printf("%d %d %d\n", ans[i][j], i, ans[i][j + 1]);

    return 0;
}
