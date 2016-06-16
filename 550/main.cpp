#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int xx[100010], yy[100010], val[100010];
int res[100010], vis[100010];

struct edge {
    int to;
    int type;
};

vector <edge> G[100010];

edge make(int xx, int yy) {
    edge tmp;
    tmp.to = xx; tmp.type = yy;
    return tmp;
}

void dfs(int nod, int col) {
    vis[nod] = col;
    vector <edge> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (vis[it -> to] == -1)
            dfs(it -> to, col ^ it -> type);
}

int xorSum[100010];

bool checkSolution(int N, int M) {
    for (int i = 1; i <= N; ++i)
        xorSum[i] = xorSum[i - 1] ^ res[i];
    for (int i = 1; i <= M; ++i)
        if ((xorSum[yy[i]] ^ xorSum[xx[i] - 1]) != val[i])
            return 0;
    return 1;
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i)
        scanf("%d%d%d", &xx[i], &yy[i], &val[i]);

    int mx = 0;
    for (int i = 1; i <= M; ++i)
        if (val[i] > mx)
            mx = val[i];

    for (int b = 0; (1 << b) <= mx; ++b) {
        for (int i = 1; i <= M; ++i) {
            int bit = val[i] & (1 << b);
            if (bit > 0)
                bit = 1;
            G[xx[i] - 1].push_back(make(yy[i], bit));
            G[yy[i]].push_back(make(xx[i] - 1, bit));
        }
        memset(vis, -1, sizeof(vis));
        for (int i = 0; i <= N; ++i)
            if (vis[i] == -1)
                dfs(i, 0);
        for (int i = 1; i <= N; ++i)
            if (vis[i] ^ vis[i - 1])
                res[i] |= (1 << b);
        for (int i = 0; i <= N; ++i)
            G[i].clear();
    }

    if (checkSolution(N, M))
        for (int i = 1; i <= N; ++i)
            printf("%d ", res[i]);
    else
        printf("WA Official solution");
    return 0;
}
