#include <stdio.h>
#include <string.h>

int N, E[300], G[300][300], solSet[300], solCq[300], solIs[300];

void dfs(int nod, int flag, int set[], int vis[]) {
    vis[nod] = flag;
    for (int i = 1; i <= N; ++i)
        if (G[nod][i] && vis[i] == 0 && set[i])
            dfs(i, flag, set, vis);
}

void complement() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (i != j)
                G[i][j] ^= 1;
}

void solve(int set[], int cq[], int is[], int &bestCq, int &bestIs) {
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        if (set[i])
            ++cnt;
    if (cnt == 1)
        for (int i = 1; i <= N; ++i)
            if (set[i]) {
                cq[i] = is[i] = 1;
                bestCq = bestIs = E[i];
                return ;
            }

    cnt = 0;
    int vis[300];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= N; ++i)
        if (vis[i] == 0 && set[i]) {
            ++cnt;
            dfs(i, cnt, set, vis);
        }

    if (cnt == 1) {
        complement();
        solve(set, is, cq, bestIs, bestCq);
        complement();
    } else
        for (int i = 1; i <= N; ++i) {
            if (vis[i] == 0)
                continue;
            int newCq = 0, newIs = 0, cq2[300], is2[300], set2[300];
            memset(cq2, 0, sizeof(cq2));
            memset(is2, 0, sizeof(is2));
            memset(set2, 0, sizeof(set2));
            for (int j = i + 1; j <= N; ++j)
                if (vis[j] && vis[j] == vis[i]) {
                    vis[j] = 0;
                    set2[j] = 1;
                }
            set2[i] = 1;
            solve(set2, cq2, is2, newCq, newIs);
            bestIs += newIs;
            for (int j = 1; j <= N; ++j)
                if (is2[j])
                    is[j] = 1;
            if (bestCq < newCq) {
                bestCq = newCq;
                for (int j = 1; j <= N; ++j)
                    cq[j] = cq2[j];
            }
        }
}

int main() {
    freopen("soc.in", "r", stdin);
    freopen("soc.out", "w", stdout);

    int M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &E[i]);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx][yy] = G[yy][xx] = 1;
    }

    int costCq = 0, costIs = 0;
    for (int i = 1; i <= N; ++i)
        solSet[i] = 1;
    solve(solSet, solCq, solIs, costCq, costIs);

    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        if (solCq[i] == 1)
            ++cnt;
    printf("%d\n%d\n", costCq, cnt);
    for (int i = 1; i <= N; ++i)
        if (solCq[i])
            printf("%d ", i);
    return 0;
}
