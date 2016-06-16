#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> A[500500];
int take[500500], ntake[500500], chosen[500500];
int sol[500500];

void DFS(int nod) {
    vector <int> :: iterator it;
    take[nod] = 1; ntake[nod] = 0;
    int bestDif = 0, idx = 1 << 30;
    for (it = A[nod].begin(); it != A[nod].end(); ++it) {
        DFS(*it);
        take[nod] += ntake[*it]; ntake[nod] += ntake[*it];
        if (take[*it] - ntake[*it] > bestDif) {
            bestDif = take[*it] - ntake[*it];
            idx = *it;
        }
    }
    chosen[nod] = idx;
    ntake[nod] += bestDif;
}

void recon(int nod, bool take) {
    vector <int> :: iterator it;
    if (take) {
        sol[++sol[0]] = nod;
        for (it = A[nod].begin(); it != A[nod].end(); ++it)
            recon(*it, 0);
    } else
        for (it = A[nod].begin(); it != A[nod].end(); ++it)
            recon(*it, chosen[nod] == *it);
}

int main() {
    freopen("grant.in", "r", stdin);
    freopen("grant.out", "w", stdout);

    int i, N;
    scanf("%d", &N);
    for (i = 2; i <= N; ++i) {
        int father;
        scanf("%d", &father);
        A[father].push_back(i);
    }

    DFS(1);
    //if (take[1] > ntake[1]) {
    //printf("%I64d\n", 1LL * take[1] * 1000);
    //    recon(1, 1);
    //} else {
        printf("%I64d\n", 1LL * ntake[1] * 1000);
        recon(1, 0);
    //}
    sort(sol + 1, sol + sol[0] + 1);
    for (i = 1; i <= sol[0]; ++i)
        printf("%d ", sol[i]);
    return 0;
}
