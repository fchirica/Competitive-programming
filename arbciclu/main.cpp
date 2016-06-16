#include <stdio.h>
#include <set>

using namespace std;

int deg[100100], q[100100], inQ[100100];
set <int> G[100100];

void baga(int u, int v) {
    if (G[u].find(v) == G[u].end()) {
        G[u].insert(v);
        G[v].insert(u);
        ++deg[u];
        ++deg[v];
    }
}

void scoate(int u, int v) {
    G[u].erase(G[u].find(v));
    G[v].erase(G[v].find(u));
    --deg[u];
    --deg[v];
}

void solveTest() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        deg[i] = 0;
        inQ[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
        G[i].clear();
    for (int i = 1; i <= m; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].insert(yy);
        G[yy].insert(xx);
        ++deg[xx];
        ++deg[yy];
    }
    int killed = 0;
    int p = 1, u = 0;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 2) {
            q[++u] = i;
            inQ[i] = 1;
        }
    while (p <= u) {
        int nod = q[p];
        if (deg[nod] != 2)
            break;
        int nod1 = -1, nod2;
        set <int> :: iterator it;
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            if (nod1 == -1)
                nod1 = *it;
            else
                nod2 = *it;
        scoate(nod, nod1);
        scoate(nod, nod2);
        baga(nod1, nod2);
        if (deg[nod1] == 2 && !inQ[nod1]) {
            inQ[nod1] = 1;
            q[++u] = nod1;
        }
        if (deg[nod2] == 2 && !inQ[nod2]) {
            inQ[nod2] = 1;
            q[++u] = nod2;
        }
        ++killed;
        ++p;
    }
    if (killed == n - 2 && n >= 3 && m >= n)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    freopen("arbciclu.in", "r", stdin);
    freopen("arbciclu.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--)
        solveTest();

    return 0;
}
