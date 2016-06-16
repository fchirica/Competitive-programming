#include <stdio.h>
#include <vector>
#define x first
#define y second

using namespace std;

int x[1024][1024], toDisjoint[1024][1024], F[1024 * 1024], C[1024 * 1024], R[1024 * 1024];
vector <pair <int, int> > V[2000];

int N, M, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

inline int abs(int X) {
    return X > 0 ? X : -X;
}

int father(int nod) {
    return F[nod] = ((nod == F[nod]) ? nod : father(F[nod]));
}

void unite(int xx, int yy) {
    if (father(xx) == father(yy))
        return ;
    if (R[father(xx)] > R[father(yy)])
        swap(xx, yy);
    C[father(yy)] |= C[father(xx)];
    F[father(xx)] = father(yy);
    if (R[father(xx)] == R[father(yy)])
        ++R[father(yy)];
}

int main() {
    scanf("%d%d", &N, &M);
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &x[i][j]);
            V[abs(x[i][j])].push_back(make_pair(i, j));
            toDisjoint[i][j] = ++cnt;
        }
    for (int i = 1; i <= cnt; ++i) {
        F[i] = i;
        C[i] = 0;
        R[i] = 1;
    }

    int res = 0;
    for (int val = 0; val <= 1000; ++val) {
        vector <pair <int, int> > :: iterator it;
        for (it = V[val].begin(); it != V[val].end(); ++it)
            for (int d = 0; d < 4; ++d) {
                int xx = it -> x, yy = it -> y;
                int nx = xx + dx[d];
                int ny = yy + dy[d];
                if (nx < 1 || ny < 1 || nx > N || ny > M)
                    continue;
                if (abs(x[nx][ny]) <= abs(x[xx][yy]))
                    unite(toDisjoint[nx][ny], toDisjoint[xx][yy]);
            }
        for (it = V[val].begin(); it != V[val].end(); ++it) {
            int root = father(toDisjoint[it -> x][it -> y]);
            if (C[root] == 0 && x[it -> x][it -> y] > 0) {
                ++res;
                C[root] = 1;
            }
        }
    }

    printf("%d", res);
    return 0;
}
