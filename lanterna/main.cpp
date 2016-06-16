#include <stdio.h>
#include <vector>

using namespace std;

bool charge[55];

struct edge {
    int to, T, W;
};

vector <edge> G[55];

edge make(int xx, int yy, int zz) {
    edge tmp;
    tmp.to = xx; tmp.T = yy; tmp.W = zz;
    return tmp;
}

int best[55][1024];

struct pos {
    int x, y;
} Q[55 * 3024];

int calc(int N, int lim) {
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= lim; ++j)
            best[i][j] = 1 << 28;
    int p = 1, u = 0;
    best[1][lim] = 0;
    Q[++u].x = 1; Q[u].y = lim;
    while (p <= u) {
        vector <edge> :: iterator it;
        int nod = Q[p].x;
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            if (Q[p].y >= it -> W) {
                int newEnergy = Q[p].y - it -> W;
                if (charge[it -> to])
                    newEnergy = lim;
                if (best[Q[p].x][Q[p].y] + it -> T < best[it -> to][newEnergy]) {
                    best[it -> to][newEnergy] = best[Q[p].x][Q[p].y] + it -> T;
                    Q[++u].x = it -> to; Q[u].y = newEnergy;
                }
            }
        ++p;
    }
    int sol = 1 << 28;
    for (int i = 0; i <= lim; ++i)
        if (best[N][i] < sol)
            sol = best[N][i];
    return sol;
}

int main() {
    freopen("lanterna.in", "r", stdin);
    freopen("lanterna.out", "w", stdout);

    int N, M, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &charge[i]);
    scanf("%d", &M);
    for (int i = 1; i <= M; ++i) {
        int xx, yy, tt, ww;
        scanf("%d%d%d%d", &xx, &yy, &tt, &ww);
        G[xx].push_back(make(yy, tt, ww));
        G[yy].push_back(make(xx, tt, ww));
    }

    int wanted = calc(N, K), st = 1, dr = K, sol;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (calc(N, med) == wanted) {
            sol = med;
            dr = med - 1;
        } else
            st = med + 1;
    }

    printf("%d %d", wanted, sol);
    return 0;
}
