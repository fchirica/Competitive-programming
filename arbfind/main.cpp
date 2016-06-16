#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[33000], G2[33000];
int from[33000], to[33000], E[33000 * 3], E2[33000 * 3], SP[33000 * 3];
unsigned H[33000 * 3], H2[33000 * 3], pw[33000 * 3];

const int B = 71;

void dfs(int nod) {
    E[++E[0]] = 0;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it) {
        E[++E[0]] = 1;
        dfs(*it);
        E[++E[0]] = 2;
    }
}

void dfs2(int nod) {
    E2[++E2[0]] = 0;
    from[nod] = E2[0];
    vector <int> :: iterator it;
    for (it = G2[nod].begin(); it != G2[nod].end(); ++it) {
        E2[++E2[0]] = 1;
        dfs2(*it);
        E2[++E2[0]] = 2;
    }
    to[nod] = E2[0];
}

void build(unsigned hh[], int ee[]) {
    for (int i = ee[0]; i >= 1; --i)
        hh[i] = B * hh[i + 1] + ee[i];
}

unsigned get(int xx, int yy, unsigned hh[]) {
    return hh[xx] - hh[yy + 1] * pw[yy - xx + 1];
}

int main() {
    freopen("arbfind.in", "r", stdin);
    freopen("arbfind.out", "w", stdout);

    int N, N2;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 1; j <= cnt; ++j) {
            int tmp;
            scanf("%d", &tmp);
            G[i].push_back(tmp);
        }
    }
    scanf("%d", &N2);
    for (int i = 1; i <= N2; ++i) {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 1; j <= cnt; ++j) {
            int tmp;
            scanf("%d", &tmp);
            G2[i].push_back(tmp);
        }
    }

    dfs(1);
    dfs2(1);
    build(H, E);
    build(H2, E2);
    pw[0] = 1;
    for (int i = 1; i < 3 * 33000; ++i)
        pw[i] = pw[i - 1] * B;
    for (int i = 1; i <= E[0]; ++i)
        SP[i] = SP[i - 1] + (E[i] == 0);

    for (int i = 1; i <= N2; ++i) {
        int lmax = to[i] - from[i] + 1;
        if (E[0] < lmax)
            lmax = E[0];
        int st = 1, dr = lmax, res = 0;
        while (st <= dr) {
            int med = (st + dr) / 2;
            if (get(1, med, H) == get(from[i], from[i] + med - 1, H2)) {
                res = med;
                st = med + 1;
            } else
                dr = med - 1;
        }
        printf("%d\n", SP[res]);
    }

    return 0;
}
