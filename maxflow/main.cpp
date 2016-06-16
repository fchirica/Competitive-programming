#include <bits/stdc++.h>

using namespace std;

const int kNMax = 1024;

int n;
int cap[kNMax][kNMax], flow[kNMax][kNMax];
bool vis[kNMax];

int dfs(int source, int sink, int curFlow) {
    if (source == sink)
        return curFlow;

    vis[source] = 1;
    for (int i = 1; i <= n; ++i)
        if (flow[source][i] < cap[source][i] && !vis[i]) {
            int myFlow = dfs(i, sink, min(curFlow, cap[source][i] - flow[source][i]));
            if (myFlow) {
                flow[source][i] += myFlow;
                flow[i][source] -= myFlow;
                return myFlow;
            }
        }

    return 0;
}

int main() {
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);

    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int xx, yy, cc;
        scanf("%d%d%d", &xx, &yy, &cc);
        cap[xx][yy] += cc;
    }

    int res = 0;
    int current_flow;
    do {
        memset(vis, 0, sizeof(vis));
        current_flow = dfs(1, n, 1 << 30);
        res += current_flow;
    } while (current_flow);

    printf("%d", res);
    return 0;
}
