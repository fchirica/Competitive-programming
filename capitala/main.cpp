#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector <int> G[200200];
int Arb[200200], sol[200200];
bool vis[200200];

void dfs(int nod, int d) {
    vis[nod] = 1;
    sol[1] += d;
    Arb[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs(*it, d + 1);
            Arb[nod] += Arb[*it];
        }
}

int N;
void dfs2(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            sol[*it] = sol[nod] + N - 2 * Arb[*it];
            dfs2(*it);
        }
}

int main() {
    freopen("capitala.in", "r", stdin);
    freopen("capitala.out", "w", stdout);

    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    dfs2(1);

    int dmin = 1000000000, idx;
    for (int i = 1; i <= N; ++i)
        if (sol[i] < dmin)
            dmin = sol[i], idx = i;
    printf("%d %d", idx, dmin);

    return 0;
}
