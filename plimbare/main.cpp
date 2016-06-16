#include <stdio.h>
#include <string.h>

int N, G[111][111], rf[111][111], next[111];
bool vis[111], go = 1;

void dfs(int nod, int target) {
    vis[nod] = 1;
    for (int i = 1; i <= N; ++i)
        if (G[nod][i] && go) {
            next[nod] = i;
            if (vis[i] == 0)
                dfs(i, target);
            else
                if (i == target)
                    go = 0;
        }

}

bool add1(int nod) {
    for (int i = 1; i <= N; ++i)
        if (!vis[i] && G[nod][i] && G[i][next[nod]]) {
            vis[i] = 1;
            next[i] = next[nod];
            next[nod] = i;
            return 1;
        }
    return 0;
}

bool add2(int nod) {
    for (int i = 1; i <= N; ++i)
        if (!vis[i] && G[nod][i])
            for (int j = 1; j <= N; ++j)
                if (!vis[j] && i != j)
                    if (G[i][j] && G[j][next[nod]]) {
                        vis[i] = vis[j] = 1;
                        next[i] = j;
                        next[j] = next[nod];
                        next[nod] = i;
                        return 1;
                    }
    return 0;
}

int main() {
    freopen("plimbare.in", "r", stdin);
    freopen("plimbare.out", "w", stdout);

    scanf("%d", &N);
    for (int i = 1; i <= N * (N - 1) / 2; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx][yy] = 1;
        rf[xx][yy] = 1;
    }

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                rf[i][j] |= rf[i][k] * rf[k][j];

    int bestComp = 0, bestNod;
    for (int i = 1; i <= N; ++i)
        if (!vis[i]) {
            int comp = 1;
            vis[i] = 1;
            for (int j = i + 1; j <= N; ++j)
                if (rf[i][j] && rf[j][i]) {
                    ++comp;
                    vis[j] = 1;
                }
            if (comp > bestComp)
                bestComp = comp, bestNod = i;
        }

    memset(vis, 0, sizeof(vis));
    dfs(bestNod, bestNod);
    memset(vis, 0, sizeof(vis));


    vis[bestNod] = 1;
    for (int i = next[bestNod]; i != bestNod; i = next[i])
        vis[i] = 1;
    bool supply = true;
    while (supply) {
        supply = false;
        for (int i = next[bestNod]; i != bestNod; i = next[i])
            supply |= add1(i);
        supply |= add1(bestNod);
    }
    supply = true;
    while (supply)
        supply = add2(bestNod);

    printf("%d\n%d ", bestComp, bestNod);
    for (int i = next[bestNod]; i != bestNod; i = next[i])
        printf("%d ", i);

    return 0;
}
