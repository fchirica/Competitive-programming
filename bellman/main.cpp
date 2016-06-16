#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector <pair <int, int> > G[50500];
int dist[50500], pathSize[50500];
bool inQ[50500];
queue <int> Q;

int main() {
    freopen("bellmanford.in", "r", stdin);
    freopen("bellmanford.out", "w", stdout);

    int i, N, M;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= M; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        G[x].push_back(make_pair(y, c));
    }

    dist[1] = 0; Q.push(1); inQ[1] = true;
    for (i = 2; i <= N; ++i)
        dist[i] = 1 << 30;

    while (!Q.empty()) {
        int nod = Q.front();
        if (pathSize[nod] > N) {
            printf("Ciclu negativ!");
            return 0;
        }
        vector <pair <int, int> > :: iterator it;
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            if (dist[it -> first] > dist[nod] + it -> second) {
                dist[it -> first] = dist[nod] + it -> second;
                pathSize[it -> first] = pathSize[nod] + 1;
                if (!inQ[it -> first]) {
                    Q.push(it -> first);
                    inQ[it -> first] = true;
                }
            }
        Q.pop();
        inQ[nod] = false;
    }

    for (i = 2; i <= N; ++i)
        printf("%d ", dist[i]);
    return 0;
}
