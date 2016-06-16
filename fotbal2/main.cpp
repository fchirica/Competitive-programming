#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair <int, int> > G[100100];
bool usedV[100100], usedE[100100];
int grad[100100], win[100100];

void dfs(int nod) {
    usedV[nod] = 1;
    vector <pair <int, int > > :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it) {
        int son = it -> first;
        int cntE = it -> second;
        if (usedE[cntE])
            continue;
        usedE[cntE] = 1;
        dfs(son);
        win[cntE] = son;
    }
}

int main() {
    freopen("fotbal2.in", "r", stdin);
    freopen("fotbal2.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(make_pair(yy, i));
        G[yy].push_back(make_pair(xx, i));
        ++grad[xx]; ++grad[yy];
    }

    ++N;
    int maxDif = 0, shit = M;
    for (int i = 1; i < N; ++i)
        if (grad[i] % 2) {
            maxDif = 2;
            ++shit;
            G[i].push_back(make_pair(N, shit));
            G[N].push_back(make_pair(i, shit));
        }

    for (int i = 1; i <= N; ++i)
        if (!usedV[i])
            dfs(i);
    printf("%d\n", maxDif);
    for (int i = 1; i <= M; ++i)
        printf("%d\n", win[i]);
    return 0;
}
