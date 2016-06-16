#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> G[1024];
int x[1024], vis[1024], comp[1024];

void dfs(int nod) {
    vis[nod] = 1;
    comp[++comp[0]] = nod;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            dfs(*it);
}

void bubbleSort() {
    bool sorted = false;
    sort(comp + 1, comp + comp[0] + 1);
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < comp[0]; ++i)
            if (x[comp[i]] > x[comp[i + 1]]) {
                sorted = false;
                swap(x[comp[i]], x[comp[i + 1]]);
            }
    }
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &x[i]);
        for (int i = 1; i <= M; ++i) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            G[xx].push_back(yy);
            G[yy].push_back(xx);
        }
        for (int i = 1; i <= N; ++i)
            if (!vis[i]) {
                comp[0] = 0;
                dfs(i);
                bubbleSort();
            }
        for (int i = 1; i <= N; ++i)
            printf("%d ", x[i]);
        printf("\n");
        for (int i = 1; i <= N; ++i)
            vis[i] = 0, G[i].clear();
    }

    return 0;
}
