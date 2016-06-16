#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
#define x first
#define y second
#define point pair <int, int>

using namespace std;

point x[811];
map <point, int> M;
int idx[811], sol2[811], go[811], deg[811], vis[811], sol[811];

void rot90(point &X) {
    swap(X.x, X.y);
    X.x = -X.x;
}

int dfs(int nod, int c) {
    if (nod == 0 || vis[nod])
        return 0;
    vis[nod] = 1;
    sol[nod] = c;
    return 1 + dfs(go[nod], 1 - c);
}

int is(point X, int N) {
    int st = 1, dr = N, ret = 0;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (x[med] == X) {
            ret = med;
            st = med - 1;
        }
        if (x[med] < X)
            st = med + 1;
        else
            dr = med - 1;
    }
    return ret;
}

bool comp(int A, int B) {
    return x[A] < x[B];
}

int main() {
    freopen("overlap.in", "r", stdin);
    freopen("overlap.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &x[i].x, &x[i].y);
        idx[i] = i;
    }

    sort(idx + 1, idx + N + 1, comp);
    sort(x + 1, x + N + 1);

    for (int rot = 0; rot < 4; ++rot)
        for (int i = 1; i <= N; ++i)
            if (x[i] != x[1]) {
                point tmp = x[1];
                for (int r = 1; r <= rot; ++r)
                    rot90(tmp);
                int dx = x[i].x - tmp.x, dy = x[i].y - tmp.y;
                memset(go, 0, sizeof(go));
                memset(deg, 0, sizeof(deg));
                memset(vis, 0, sizeof(vis));
                for (int j = 1; j <= N; ++j) {
                    point tmp = x[j];
                    for (int r = 1; r <= rot; ++r)
                        rot90(tmp);
                    tmp.x += dx; tmp.y += dy;
                    go[j] = is(tmp, N);
                    ++deg[go[j]];
                }
                bool solution = true;
                for (int j = 1; j <= N && solution; ++j)
                    if (deg[j] == 0 && dfs(j, 1) % 2)
                        solution = false;
                for (int j = 1; j <= N && solution; ++j)
                    if (deg[j] > 0 && dfs(j, 1) % 2)
                        solution = false;
                if (solution) {
                    for (int j = 1; j <= N; ++j)
                        sol2[idx[j]] = sol[j];
                    for (int j = 1; j <= N; ++j)
                        printf("%d\n", sol2[j] + 1);
                    return 0;
                }
            }

    return 0;
}
