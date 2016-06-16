#include <stdio.h>
#include <vector>

using namespace std;

int mod, V[20000], sol[20000], vis[20000], vis2[20000];
vector <int> G[20000];

int next(int A, int B) {
    int res = (B - A) % mod;
    while (res < 0)
        res += mod;
    return res;
}

int dfs1(int nod, int sum, int val) {
    vector <int> :: iterator it;
    vis[nod] = 1;
    int res = val;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            int cur = next(sum, V[*it]);
            res += dfs1(*it, (sum + cur) % mod, cur);
        }
    return res;
}

void dfs2(int nod) {
    vis2[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis2[*it]) {
            sol[*it] = sol[nod] - V[nod] - next(V[nod], V[*it]) + V[*it] + next(V[*it], V[nod]);
            dfs2(*it);
        }
}

int main() {
    freopen("asmin.in", "r", stdin);
    freopen("asmin.out", "w", stdout);

    int N;
    scanf("%d%d", &N, &mod);
    for (int i = 1; i < N; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    for (int i = 1; i <= N; ++i)
        scanf("%d", &V[i]);

    sol[1] = dfs1(1, V[1], V[1]);
    dfs2(1);

    int mx = 1 << 30, cnt = 0;
    for (int i = 1; i <= N; ++i)
        if (sol[i] < mx) {
            mx = sol[i];
            cnt = 1;
        } else
            if (sol[i] == mx)
                ++cnt;
    printf("%d %d\n", mx, cnt);
    for (int i = 1; i <= N; ++i)
        if (sol[i] == mx)
            printf("%d ", i);
    return 0;
}
