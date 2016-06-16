#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int kNMax = 200001;
const int babenco = 5;

vector <int> G[kNMax], nodes_for_color[kNMax];
int col[kNMax], lg[2 * kNMax + babenco], E[2 * kNMax + babenco], rmqLev[2 * kNMax + babenco], nodeLev[kNMax], firstSeen[kNMax];
int disjoint_set[kNMax], cnt_disjoint[kNMax], rmq[19][2 * kNMax + babenco];
bool vis[kNMax];

struct LCA_node {
    int from1, from2, node;
} lcaSet[kNMax];

void dfs(int nod, int curLevel) {
    vis[nod] = 1;
    nodes_for_color[col[nod]].push_back(nod);
    E[++E[0]] = nod;
    nodeLev[nod] = curLevel;
    rmqLev[++rmqLev[0]] = curLevel;
    firstSeen[nod] = E[0];

    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs(*it, curLevel + 1);
            E[++E[0]] = nod;
            rmqLev[++rmqLev[0]] = curLevel;
        }
}

void buildRMQ() {
    for (int i = 1; i <= E[0]; ++i)
        rmq[0][i] = i;
    for (int i = 2; i <= E[0]; ++i)
        lg[i] = lg[i / 2] + 1;
    for (int pw = 1; (1 << pw) <= E[0]; ++pw) {
        int POWER = 1 << (pw - 1);
        for (int i = 1; i + (1 << pw) - 1 <= E[0]; ++i)
            if (rmqLev[rmq[pw - 1][i]] < rmqLev[rmq[pw - 1][i + POWER]])
                rmq[pw][i] = rmq[pw - 1][i];
            else
                rmq[pw][i] = rmq[pw - 1][i + POWER];
    }
}

int LCA(int xx, int yy) {
    xx = firstSeen[xx];
    yy = firstSeen[yy];
    if (xx > yy) {
        int tmp = xx;
        xx = yy;
        yy = tmp;
    }
    int len = lg[yy - xx + 1];
    if (rmqLev[rmq[len][xx]] < rmqLev[rmq[len][yy - (1 << len) + 1]])
        return E[rmq[len][xx]];
    return E[rmq[len][yy - (1 << len) + 1]];
}

int father(int node) {
    return disjoint_set[node] = (node == disjoint_set[node] ? node : father(disjoint_set[node]));
}

void unite(int node1, int node2) {
    cnt_disjoint[father(node2)] += cnt_disjoint[father(node1)];
    disjoint_set[father(node1)] = father(node2);
}

inline bool comp(LCA_node A, LCA_node B) {
    return nodeLev[A.node] > nodeLev[B.node];
}

long long solveColor(int current_col) {
    if (nodes_for_color[current_col].size() <= 1)
        return 0;

    vector <int> :: iterator it;
    long long res = 0;
    for (it = nodes_for_color[current_col].begin(); it != nodes_for_color[current_col].end(); ++it)
        res += 1LL * (nodes_for_color[current_col].size() - 1) * nodeLev[*it];

    int cnt = 0;
    for (int i = 1; i < nodes_for_color[current_col].size(); ++i) {
        lcaSet[++cnt].from1 = nodes_for_color[current_col][i];
        lcaSet[cnt].from2 = nodes_for_color[current_col][i - 1];
        lcaSet[cnt].node = LCA(lcaSet[cnt].from1, lcaSet[cnt].from2);
    }

    sort(lcaSet + 1, lcaSet + cnt + 1, comp);
    for (int i = 1; i <= cnt; ++i) {
        res -= 2LL * nodeLev[lcaSet[i].node] * cnt_disjoint[father(lcaSet[i].from1)] * cnt_disjoint[father(lcaSet[i].from2)];
        unite(lcaSet[i].from1, lcaSet[i].from2);
    }
    return res;
}

int main() {
    freopen("kdist.in", "r", stdin);
    freopen("kdist.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &col[i]);

    dfs(1, 1);
    buildRMQ();

    for (int i = 1; i <= n; ++i) {
        disjoint_set[i] = i;
        cnt_disjoint[i] = 1;
    }

    for (int i = 1; i <= k; ++i)
        printf("%lld\n", solveColor(i));

    return 0;
}
