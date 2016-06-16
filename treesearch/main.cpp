#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int x[100100];
vector <int> G[100100], sons[100100];
bool vis[100100];
int up[100100], down[100100], dad[100100], res[100100];

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    down[nod] = x[nod];
    int best = 0;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs(*it);
            dad[*it] = nod;
            if (down[*it] > best)
                best = down[*it];
            sons[nod].push_back(*it);
        }
    down[nod] = x[nod] + best;
}

inline bool comp(int A, int B) {
    return down[A] > down[B];
}

void dfs2(int nod) {
    if (nod != 1) {
        int TT = dad[nod];
        vector <int> :: iterator it;
        int best = 0;
        for (it = sons[TT].begin(); it != sons[TT].end(); ++it)
            if (*it != nod && down[*it] > best)
                best = down[*it];
        up[nod] = x[TT] + max(best, up[TT]);
    }

    vector <int> :: iterator it;
    for (it = sons[nod].begin(); it != sons[nod].end(); ++it)
        dfs2(*it);
}

int main() {
    freopen("treesearch.in", "r", stdin);
    freopen("treesearch.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    for (int i = 1; i < n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    dfs(1);
    for (int i = 1; i <= n; ++i)
        sort(sons[i].begin(), sons[i].end(), comp);

    dfs2(1);

    for (int i = 1; i <= n; ++i) {
        int son1 = 0, son2 = 0, ret = 0;
        vector <int> :: iterator it;
        for (it = sons[i].begin(); it != sons[i].end(); ++it) {
            if (ret == 0)
                son1 = max(son1, down[*it]);
            if (ret == 1)
                son2 = max(son2, down[*it]);
            if (ret == 2)
                break;
            ++ret;
        }
        res[i] = max(son1 + son2, up[i] + son1) + x[i];
    }

    while (q--) {
        int xx;
        scanf("%d", &xx);
        printf("%d\n", res[xx]);
    }

    return 0;
}
