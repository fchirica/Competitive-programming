#include <stdio.h>
#include <vector>

using namespace std;

struct graf {
    int y, cost;
};

graf make(int A, int B) {
    graf tmp;
    tmp.y = A; tmp.cost = B;
    return tmp;
}

vector <graf> G[100100];
int dist[100100];
bool vis[100100];

void dfs(int nod) {
    vector <graf> :: iterator it;
    vis[nod] = 1;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[it -> y]) {
            dist[it -> y] = dist[nod] ^ it -> cost;
            dfs(it -> y);
        }
}

int main() {
    freopen("plopi.in", "r", stdin);
    freopen("plopi.out", "w", stdout);

    int N;
    scanf("%d", &N);

    for (int i = 1; i < N; ++i) {
        int xx, yy, cost;
        scanf("%d%d%d", &xx, &yy, &cost);
        cost = cost % 2;
        G[xx].push_back(make(yy, cost));
        G[yy].push_back(make(xx, cost));
    }

    dfs(1);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= N; ++i)
        if (dist[i] == 0)
            ++cnt1;
        else
            ++cnt2;
    printf("%lld", 1LL * cnt1 * cnt2);
    return 0;
}
