#include <stdio.h>
#include <vector>

using namespace std;

int L[130], R[130], U[130];
vector <int> G[130];

bool pairup(int nod) {
    vector <int> :: iterator it;
    if (U[nod])
        return 0;
    U[nod] = 1;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (R[*it] == 0 || pairup(R[*it])) {
            L[nod] = *it;
            R[*it] = nod;
            return 1;
        }
    return 0;
}

int main() {
    freopen("revolutie.in", "r", stdin);
    freopen("revolutie.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp)
                G[i].push_back(j);
        }

    bool ok = true;
    int cnt = 0;
    while (ok) {
        ok = false;
        for (int i = 1; i <= N; ++i)
            U[i] = 0;
        for (int i = 1; i <= N; ++i)
            if (L[i] == 0 && pairup(i)) {
                ++cnt;
                ok = true;
            }
    }

    if (cnt != N) {
        printf("-1");
        return 0;
    }

    printf("%d\n", N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            if (L[j] == i) {
                int tmp = L[i];
                L[i] = L[j];
                L[j] = tmp;
                printf("L %d %d\n", i, j);
                break;
            }
    }

    return 0;
}
