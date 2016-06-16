#include <stdio.h>
#include <algorithm>

using namespace std;

struct query {
    int x0, y0, x1, y1, i, res;
} Q[20200];

int x[310][310], dj[310][310];

struct elem {
    int x, y;
} E[310 * 310];

inline bool comp(elem A, elem B) {
    return x[A.x][A.y] > x[B.x][B.y];
}

inline bool comp2(query A, query B) {
    return A.res > B.res;
}

inline bool comp3(query A, query B) {
    return A.i < B.i;
}

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int kkt[310 * 310];

int father(int X) {
    return kkt[X] = (X == kkt[X]) ? X : father(kkt[X]);
}

void unite2(int X, int Y) {
    kkt[father(X)] = kkt[father(Y)];
}

void unite(int X, int Y) {
    for (int i = 0; i < 4; ++i)
        if (dj[X + dx[i]][Y + dy[i]])
            unite2(dj[X][Y], dj[X + dx[i]][Y + dy[i]]);
}

int main() {
    freopen("matrice2.in", "r", stdin);
    freopen("matrice2.out", "w", stdout);

    int N, M, cnt = 0;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &x[i][j]);
            E[++cnt].x = i; E[cnt].y = j;
        }

    sort(E + 1, E + cnt + 1, comp);

    for (int i = 1; i <= M; ++i) {
        scanf("%d%d%d%d", &Q[i].x0, &Q[i].y0, &Q[i].x1, &Q[i].y1);
        Q[i].i = i; Q[i].res = 0;
    }

    for (int i = 19; i >= 0; --i) {
        sort(Q + 1, Q + M + 1, comp2);
        for (int ii = 1; ii <= N; ++ii)
            for (int j = 1; j <= N; ++j)
                dj[ii][j] = 0;
        for (int ii = 1; ii <= N * N; ++ii)
            kkt[ii] = ii;
        int added = 1;
        cnt = 0;
        for (int j = 1; j <= M; ++j) {
            for (; added <= N * N && x[E[added].x][E[added].y] >= (Q[j].res + (1 << i)); ++added) {
                dj[E[added].x][E[added].y] = ++cnt;
                unite(E[added].x, E[added].y);
            }
            int dad1 = father(dj[Q[j].x0][Q[j].y0]), dad2 = father(dj[Q[j].x1][Q[j].y1]);
            if (dad1 == dad2 && dad1)
                Q[j].res += (1 << i);
        }
    }

    sort(Q + 1, Q + M + 1, comp3);
    for (int i = 1; i <= M; ++i)
        printf("%d\n", Q[i].res);

    return 0;
}
