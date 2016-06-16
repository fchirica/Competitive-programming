#include <cstdio>
#include <cstring>
using namespace std;
int lperm[1111], cperm[1111], xswap[1111], yswap[1111];
int x[1111][1111], shit, y[1111][1111], perm[1111 * 1111], cycle[1111 * 1111], rez[1111 * 1111];
bool vis[1111 * 1111];

void swap(int &A, int &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

int main() {
    freopen("matperm2.in", "r", stdin);
    freopen("matperm2.out", "w", stdout);

    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &lperm[i]);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &cperm[i]);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            x[i][j] = (i - 1) * M + j;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            y[i][j] = x[lperm[i]][cperm[j]];

    int Q;
    scanf("%d", &Q);
    for (int i = 1; i <= Q; ++i) {
        int xa, ya, xb, yb;
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        swap(y[xa][ya], y[xb][yb]);
    }


    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            perm[++shit] = y[i][j];

    for (int i = 1; i <= shit; ++i)
        if (!vis[i]) {
            cycle[0] = 0;
            int cur = i;
            do {
                cycle[++cycle[0]] = cur;
                vis[cur] = 1;
                cur = perm[cur];
            } while (cur != i);
            int steps = P % cycle[0];
            cur = i;
            for (int times = 1; times <= steps; ++times)
                cur = perm[cur];
            for (int j = 1; j <= cycle[0]; ++j) {
                rez[cycle[j]] = cur;
                cur = perm[cur];
            }
        }

    shit = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j)
            printf("%d ", rez[++shit]);
        printf("\n");
    }

    return 0;
}
