#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[20000];
bool vis[20000], vis2[20000], down[20000], up[20000];
int sol[20000];

void dfs1(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    bool win = true;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs1(*it);
            if (down[*it])
                win = false;
        }
    down[nod] = win;
}

void dfs2(int nod) {
    vis2[nod] = 1;
    vector <int> :: iterator it;
    int xorsum = 0;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis2[*it])
            xorsum ^= *it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis2[*it]) {
            up[*it] = 1 - up[nod];
            int son = xorsum ^ *it;
            if (down[son])
                up[*it] = 1;
            dfs2(*it);
        }
}

int main() {
    freopen("color2.in", "r", stdin);
    freopen("color2.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    up[1] = 1;
    dfs1(1);
    dfs2(1);

    for (int i = 1; i <= N; ++i) {
        bool win = up[i];
        if (down[i] < win)
            win = down[i];
        if (win)
            sol[++sol[0]] = i;
    }

    for (int i = 0; i <= sol[0]; ++i)
        printf("%d%c", sol[i], (i == 0) ? '\n' : ' ');
    return 0;
}
