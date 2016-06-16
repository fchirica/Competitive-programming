#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector <int> G[100100];
int val[100100];
map <int, int> M[100100];
bool vis[100100];
int bestC[100100], bestAp[100100], whichLeaf[100100], mapSize[100100];

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    vector <int> sons;

    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs(*it);
            sons.push_back(*it);
        }

    if (sons.size() == 0) {
        whichLeaf[nod] = nod;
        bestC[nod] = val[nod];
        bestAp[nod] = 1;
        M[nod][val[nod]] = 1;
    } else {
        whichLeaf[nod] = whichLeaf[sons[0]];
        bestC[nod] = bestC[sons[0]];
        bestAp[nod] = bestAp[sons[0]];

        for (int i = 1; i < sons.size(); ++i) {
            int leaf1 = whichLeaf[nod];
            int leaf2 = whichLeaf[sons[i]];
            if (mapSize[leaf1] > mapSize[leaf2]) {
                int tmp = leaf1;
                leaf1 = leaf2;
                leaf2 = tmp;
            }

            map <int, int> :: iterator it;
            for (it = M[leaf1].begin(); it != M[leaf1].end(); ++it) {
                int cval = it -> first;
                M[leaf2][cval] += M[leaf1][cval];
                if (M[leaf2][cval] > bestAp[nod] || (M[leaf2][cval] == bestAp[nod] && cval < bestC[nod])) {
                    bestC[nod] = cval;
                    bestAp[nod] = M[leaf2][cval];
                }
            }

            mapSize[leaf2] += mapSize[leaf1];
            whichLeaf[nod] = leaf2;
        }

        int cval = val[nod];
        int sTree = whichLeaf[nod];
        ++M[sTree][cval];
        ++mapSize[sTree];
        int cap = M[sTree][cval];
        if (cap > bestAp[nod] || (cap == bestAp[nod] && cval < bestC[nod])) {
            bestAp[nod] = cap;
            bestC[nod] = cval;
        }
    }
}

int main() {
    freopen("egal.in", "r", stdin);
    freopen("egal.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);

    dfs(1);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", bestC[i], bestAp[i]);
    return 0;
}
