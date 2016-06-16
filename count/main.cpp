#include <stdio.h>
#include <set>

using namespace std;

set <int> G[30100];
int deg[30100], Q[31000];
int sol[5];

void updateSol(int nod) {
    set <int> :: iterator it1, it2, it3;
    for (it1 = G[nod].begin(); it1 != G[nod].end(); ++it1)
        for (it2 = it1; it2 != G[nod].end(); ++it2) {
            if (it2 == it1 || G[*it1].find(*it2) == G[*it1].end())
                continue;
            ++sol[3];
            for (it3 = it2; it3 != G[nod].end(); ++it3) {
                if (it3 == it2 || G[*it1].find(*it3) == G[*it1].end() || G[*it2].find(*it3) == G[*it2].end())
                    continue;
                ++sol[4];
            }
        }
}

int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        ++deg[xx]; ++deg[yy];
        G[xx].insert(yy);
        G[yy].insert(xx);
    }

    int p = 1, u = 0;
    for (int i = 1; i <= N; ++i)
        if (deg[i] < 6)
            Q[++u] = i;

    sol[1] = N; sol[2] = M;
    while (p <= u) {
        updateSol(Q[p]);
        set <int> :: iterator it;
        for (it = G[Q[p]].begin(); it != G[Q[p]].end(); ++it) {
            --deg[*it];
            if (deg[*it] == 5)
                Q[++u] = *it;
            G[*it].erase(Q[p]);
        }
        G[Q[p]].clear();
        ++p;
    }

    for (int i = 4; i >= 1; --i)
        if (sol[i]) {
            printf("%d %d", i, sol[i]);
            return 0;
        }

    return 0;
}
