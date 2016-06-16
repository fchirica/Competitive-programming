#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int u[77], t[77], d[77][77], dst[10100], q[10100];
vector <int> G2[10100];

void BFS(int nod) {
    memset(dst, -1, sizeof(dst));
    dst[nod] = 0;
    int p = 1, u = 0; q[++u] = nod;
    while (p <= u) {
        nod = q[p];
        vector <int> :: iterator it;
        for (it = G2[nod].begin(); it != G2[nod].end(); ++it)
            if (dst[*it] == -1) {
                dst[*it] = dst[nod] + 1;
                q[++u] = *it;
            }
        ++p;
    }
}

const int NMAX = 200;

int f[NMAX][NMAX], cap[NMAX][NMAX], cost[NMAX][NMAX];
int dist[NMAX], father[NMAX];
vector <int> G[NMAX];
queue <int> Q;
bool inQ[NMAX];

struct MaxFlowMinCost {
    long long maxFlow, minCost;
    int source, sink, N;

    void init(int S, int T, int n) {
        maxFlow = minCost = 0;
        source = S; sink = T; N = n;
    }

    void addEdge(int x0, int y0, int edgeCap, int edgeCost) {
        cap[x0][y0] = edgeCap;
        cost[x0][y0] = edgeCost;
        cost[y0][x0] = -edgeCost;
        G[x0].push_back(y0);
        G[y0].push_back(x0);
    }

    void initBellmanFord() {
        int i;
        for (i = 0; i <= N; ++i)
            dist[i] = 1 << 30;
        dist[source] = 0; Q.push(source);
    }

    bool BellmanFord() {
        initBellmanFord();
        while (!Q.empty()) {
            int nod = Q.front();
            vector <int> :: iterator it;
            for (it = G[nod].begin(); it != G[nod].end(); ++it)
                if (f[nod][*it] < cap[nod][*it])
                    if (dist[*it] > dist[nod] + cost[nod][*it]) {
                        dist[*it] = dist[nod] + cost[nod][*it];
                        father[*it] = nod;
                        if (!inQ[*it]) {
                            inQ[*it] = true;
                            Q.push(*it);
                        }
                    }
            Q.pop(); inQ[nod] = false;
        }
        return dist[sink] != 1 << 30;
    }

    void augment() {
        int nod = sink, fmin = 1 << 30;
        while (nod != source) {
                if (fmin > cap[father[nod]][nod] - f[father[nod]][nod])
                    fmin = cap[father[nod]][nod] - f[father[nod]][nod];
                nod = father[nod];
            }
        nod = sink;
        while (nod != source) {
            f[father[nod]][nod] += fmin;
            f[nod][father[nod]] -= fmin;
            nod = father[nod];
        }
        minCost += dist[sink] * fmin;
        maxFlow += fmin;
    }

    void solve() {
        while (BellmanFord())
            augment();
    }
};

int main() {
    freopen("atac2.in", "r", stdin);
    freopen("atac2.out", "w", stdout);

    int N, M, K, X;
    scanf("%d%d%d%d", &N, &M, &K, &X);
    for (int i = 1; i <= K; ++i)
        scanf("%d", &u[i]);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G2[xx].push_back(yy);
        G2[yy].push_back(xx);
        if (xx == X)
            t[++t[0]] = yy;
        if (yy == X)
            t[++t[0]] = xx;
    }

    for (int i = 1; i <= K; ++i) {
        BFS(u[i]);
        for (int j = 1; j <= t[0]; ++j)
            d[i][j] = dst[t[j]];
    }

    MaxFlowMinCost network;
    network.init(0, K + t[0] + 1, K + t[0] + 1);

    for (int i = 1; i <= K; ++i)
        network.addEdge(0, i, 1, 0);
    for (int i = K + 1; i <= K + t[0]; ++i)
        network.addEdge(i, K + t[0] + 1, 1, 0);
    for (int i = 1; i <= K; ++i)
        for (int j = 1; j <= t[0]; ++j)
            network.addEdge(i, K + j, 1, d[i][j]);
    network.solve();
    printf("%d", network.minCost);
    return 0;
}
