#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[1000100];
bool prime[1000100];
int Q[1000100], seen[1000100];
int sticky[100100], solD[1000100], solidx[1000100], D[1000100], idx[1000100];

void precalc(int uppBound) {
    for (int i = 2; i <= uppBound; ++i)
        if (!prime[i]) {
            G[1].push_back(i);
            G[i].push_back(1);
            int ret = 0;
            for (int j = i; j <= uppBound; j += i) {
                prime[j] = true;
                G[j].push_back(++ret);
                G[ret].push_back(j);
                //E1.push_back(j);
                //E2.push_back(j / i);
                //E1.push_back(j / i);
                //E2.11push_back(j);
            }
        }
}

const int INF = (1 << 29);

int main() {
    //freopen("distance.in", "r", stdin);
    //freopen("distance.out", "w", stdout);

    int i, n, M = 0;
    scanf("%d", &n);
    for (i = 1; i <= 1000000; ++i)
        D[i] = idx[i] = solD[i] = solidx[i] = INF;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &sticky[i]);
        if (seen[sticky[i]]) {
            solD[i] = 0;
            solidx[i] = seen[sticky[i]];
            if (solD[seen[sticky[i]]] == INF) {
                solD[seen[sticky[i]]] = 0;
                solidx[seen[sticky[i]]] = i;
            }
            sticky[i] = -1;
        }
        else {
            seen[sticky[i]] = i;
            if (sticky[i] > M)
                M = sticky[i];
        }
    }
    precalc(M);

    int p = 1, u = 0;
    for (i = 1; i <= n; ++i)
        if (sticky[i] != -1) {
            D[sticky[i]] = 0;
            idx[sticky[i]] = i;
            Q[++u] = sticky[i];
        }
    vector <int> :: iterator it;
    while (p <= u) {
        int nod = Q[p];
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            if (*it <= M)
                if (D[nod] + 1 < D[*it] || (D[nod] + 1 == D[*it] && idx[nod] < idx[*it])) {
                    D[*it] = D[nod] + 1;
                    idx[*it] = idx[nod];
                    Q[++u] = *it;
                }
            ++p;
        }

    for (i = 1; i <= M; ++i)
        for (it = G[i].begin(); it != G[i].end(); ++it) {
            if (i == 6) {
                int mortiiMatii = 0;
                ++mortiiMatii;
            }
            int nod1 = idx[i];
            int nod2 = idx[*it];
            if (nod1 == nod2)
                continue;
            int dist = D[i] + D[*it] + 1;
            if (dist < solD[nod1] || (dist == solD[nod1] && nod2 < solidx[nod1])) {
                solD[nod1] = dist;
                solidx[nod1] = nod2;
            }
        }

    for (i = 1; i <= n; ++i)
        printf("%d\n", solidx[i]);
    return 0;
}

