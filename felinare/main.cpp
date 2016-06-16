#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector <int> G[9000];
int L[9000], R[9000];
bool U[9000], isL[9000], isR[9000];

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

void support(int nod) {
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!isR[*it]) {
            isR[*it] = true;
            isL[R[*it]] = false;
            support(R[*it]);
        }
}

int main() {
    freopen("felinare.in", "r", stdin);
    freopen("felinare.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
    }

    bool match = true;
    int cnt = 0;
    while (match) {
        match = false;
        memset(U, 0, sizeof(U));
        for (int i = 1; i <= N; ++i)
            if (!L[i] && pairup(i)) {
                ++cnt;
                match = true;
            }
    }

    printf("%d\n", 2 * N - cnt);

    for (int i = 1; i <= N; ++i)
        if (L[i])
            isL[i] = true;
    for (int i = 1; i <= N; ++i)
        if (!isL[i])
            support(i);
    for (int i = 1; i <= N; ++i) {
        int res = 0;
        if (!isL[i])
            res |= 1;
        if (!isR[i])
            res |= 2;
        printf("%d\n", res);
    }

    return 0;
}
