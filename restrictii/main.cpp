#include <stdio.h>
#include <vector>

using namespace std;

const int kMod = 666013;
vector <pair <int, int> > G[55555];
bool vis[55555];
int res[55555];

int mod;
bool good = true;

inline int add(int x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    if (x < 0)
        x += mod;
    return x;
}

void dfs(int nod) {
    if (!good)
        return ;
    vis[nod] = 1;
    vector <pair <int, int> > :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[it -> first]) {
            res[it -> first] = add(res[nod], it -> second);
            dfs(it -> first);
        } else
            if (res[it -> first] != add(res[nod], it -> second))
                good = false;
}

int main() {
    freopen("restrictii.in", "r", stdin);
    freopen("restrictii.out", "w", stdout);

    int n, m;
    scanf("%d%d%d", &n, &m, &mod);
    for (int i = 1; i <= m; ++i) {
        int xx, yy, cc;
        scanf("%d%d%d", &xx, &yy, &cc);

        G[xx - 1].push_back(make_pair(yy, cc));
        G[yy].push_back(make_pair(xx - 1, -cc));
    }

    dfs(0);
    int res = 1;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            res = (long long) res * mod % kMod;
            dfs(i);
        }

    if (!good)
        res = 0;
    printf("%d", res);
    return 0;
}
