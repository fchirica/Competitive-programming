#include <stdio.h>
#include <vector>

using namespace std;

int comp[100100], ord[100100], low[100100];
vector <int> G[100100];
bool art[100100];
int timp;

void dfs(int nod, int keep) {
    low[nod] = ord[nod] = ++timp;
    vector <int> :: iterator it;
    int sons = 0;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (ord[*it] == 0) {
            dfs(*it, 0);
            ++sons;
            if (low[*it] < low[nod])
                low[nod] = low[*it];
            if (low[*it] >= ord[nod])
                art[nod] = 1;
        } else
            if (ord[*it] < low[nod])
                low[nod] = ord[*it];
    if (keep) {
        art[nod] = 0;
        if (sons >= 2)
            art[nod] = 1;
    }
}

int main() {
    freopen("pamant.in", "r", stdin);
    freopen("pamant.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    for (int i = 1; i <= N; ++i)
        if (ord[i] == 0) {
            comp[++comp[0]] = i;
            dfs(i, 1);
        }

    printf("%d\n", comp[0]);
    for (int i = 1; i <= comp[0]; ++i)
        printf("%d ", comp[i]);
    int nr = 0;
    for (int i = 1; i <= N; ++i)
        nr += art[i];
    printf("\n%d\n", nr);
    for (int i = 1; i <= N; ++i)
        if (art[i])
            printf("%d ", i);
    return 0;
}

