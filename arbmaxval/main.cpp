#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

vector <int> G[300300];
vector <int> queries[300300];

int take[300300], ntake[300300], val[300300];
bool vis[300300];

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            take[*it] = max(take[nod], val[nod]);
            dfs(*it);
        }
}

struct comp {
    inline bool operator () (int A, int B) {
        return A > B;
    }
};

multiset <int, comp> pq;

void dfs2(int nod) {
    vis[nod] = 1;
    pq.erase(pq.find(val[nod]));
    ntake[nod] = *pq.begin();
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            dfs2(*it);
    pq.insert(val[nod]);
}

int main() {
    freopen("arbvalmax.in", "r", stdin);
    freopen("arbvalmax.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int dad;
        scanf("%d", &dad);
        G[dad].push_back(i + 1);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);

    dfs(1);

    for (int i = 1; i <= n; ++i)
        pq.insert(val[i]);
    memset(vis, 0, sizeof(vis));

    dfs2(1);
    while (q--) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        printf("%d\n", max(take[xx], ntake[yy]));
    }
    return 0;
}
