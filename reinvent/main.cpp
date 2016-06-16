#include <stdio.h>
#include <vector>

using namespace std;

int d[100100], r[100100], q[100100];
vector <int> G[100100];

int main() {
    freopen("reinvent.in", "r", stdin);
    freopen("reinvent.out", "w", stdout);

    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    int p = 1, u = 0;
    for (int i = 1; i <= N; ++i)
        d[i] = 500000;
    for (int i = 1; i <= K; ++i) {
        int tmp;
        scanf("%d", &tmp);
        q[++u] = tmp; r[tmp] = tmp; d[tmp] = 0;
    }

    while (p <= u) {
        vector <int> :: iterator it;
        int nod = q[p];
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            if (d[*it] == 500000) {
                d[*it] = d[nod] + 1;
                r[*it] = r[nod];
                q[++u] = *it;
            }
        ++p;
    }

    int sol = 500000;
    for (int i = 1; i <= N; ++i) {
        vector <int> :: iterator it;
        int r1 = r[i];
        for (it = G[i].begin(); it != G[i].end(); ++it) {
            int r2 = r[*it];
            if (r1 == r2)
                continue;
            if (d[i] + d[*it] + 1 < sol)
                sol = d[i] + d[*it] + 1;
        }
    }

    printf("%d", sol);
    return 0;
}
