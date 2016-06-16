#include <stdio.h>
#include <vector>

using namespace std;

//PRE WRITTEN CODE

const int NMAX = 1000;
int C[NMAX][NMAX], F[NMAX][NMAX];

struct flowSolver
{
    int source, sink, maxflow, N;

    int father[NMAX], vis[NMAX], Q[NMAX], p, u;

    vector <int> G[NMAX];

    void initFlow (int sursa, int dest, int _N)
    {
        source = sursa; sink = dest; N = _N;
    }

    void addEdge(int x0, int y0, int cost, bool isDirected)
    {
        G[x0].push_back(y0);
        G[y0].push_back(x0);
        C[x0][y0] = cost;
        if (isDirected == false)
            G[y0][x0] = cost;
    }

    void initBFS()
    {
        int i;

        for (i = 0; i <= N; i ++)
            father[i] = 0, vis[i] = 0;
        p = 1; u = 0;
    }

    bool BFS()
    {
        initBFS();
        Q[++ u] = source; vis[source] = 1; father[source] = -1;
        vector <int> :: iterator it;

        while (p <= u)
        {
            int nod = Q[p];
            for (it = G[nod].begin(); it != G[nod].end(); it ++)
                if (vis[*it] == 0 && F[nod][*it] < C[nod][*it])
                {
                    father[*it] = nod;
                    vis[*it] = 1;
                    Q[++ u] = *it;
                }

            p ++;
        }

        return vis[sink];
    }

    void augment()
    {
        vector <int> :: iterator it;
        int nod, fmin;

        for (it = G[sink].begin(); it != G[sink].end(); it ++)
        {
            fmin = C[*it][sink] - F[*it][sink]; nod = *it;
            while (nod != source && fmin > 0)
            {
                if (C[father[nod]][nod] - F[father[nod]][nod] < fmin)
                    fmin = C[father[nod]][nod] - F[father[nod]][nod];
                nod = father[nod];
            }

            if (fmin)
            {
                nod = *it;
                F[*it][sink] += fmin; F[sink][*it] -= fmin;
                while (nod != source)
                {
                    F[father[nod]][nod] += fmin; F[nod][father[nod]] -= fmin;
                    nod = father[nod];
                }
                maxflow += fmin;
            }
        }
    }

    int solve()
    {
        maxflow = 0;
        while (BFS())
            augment();
        return maxflow;
    }
};

//END OF PRE WRITTEN CODE

int x0[100000], y0[100000], lw[100000], up[100000], dem[100000];

int main() {
    freopen("cooling.in", "r", stdin);
    freopen("cooling.out", "w", stdout);

    int i, N, M;
    scanf("%d%d", &N, &M);

    for (i = 1; i <= M; ++i) {
        scanf("%d%d%d%d", &x0[i], &y0[i], &lw[i], &up[i]);
        dem[x0[i]] -= lw[i]; dem[y0[i]] += lw[i];
    }

    int posSum = 0, negSum = 0;
    for (i = 1; i <= N; ++i)
        if (dem[i] > 0)
            posSum += dem[i];
        else
            negSum -= dem[i];

    if (posSum != negSum) {
        printf("NO");
        return 0;
    }

    flowSolver myFlow;
    myFlow.initFlow(0, N + 1, N + 1);
    for (i = 1; i <= M; ++i)
        myFlow.addEdge(x0[i], y0[i], up[i] - lw[i], 1);
    for (i = 1; i <= N; ++i) {
        if (dem[i] > 0)
            myFlow.addEdge(0, i, dem[i], 1);
        else
            myFlow.addEdge(i, N + 1, -dem[i], 1);
    }

    int receivedFlow = myFlow.solve();
    if (receivedFlow != posSum) {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    for (i = 1; i <= M; ++i)
        printf("%d\n", F[x0[i]][y0[i]] + lw[i]);

    return 0;
}
