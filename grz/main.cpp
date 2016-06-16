#include <stdio.h>

int N, x[1024][1024];
short Qx[1024 * 1024], Qy[1024 * 1024];

bool lo, hi;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline int abs(int X) {
    return X > 0 ? X : -X;
}

void dfs(short xx, short yy) {
    int p = 1, u = 0;
    Qx[++u] = xx; Qy[u] = yy; x[xx][yy] = -x[xx][yy];
    while (p <= u) {
        xx = Qx[p];
        yy = Qy[p];
        for (int d = 0; d < 8; ++d) {
            int nx = Qx[p] + dx[d];
            int ny = Qy[p] + dy[d];
            if (nx < 1 || ny < 1 || nx > N || ny > N)
                continue;
            if (x[nx][ny] > 0 && abs(x[xx][yy]) == abs(x[nx][ny])) {
                Qx[++u] = nx;
                Qy[u] = ny;
                x[nx][ny] = -x[nx][ny];
            }
            if (abs(x[nx][ny]) < abs(x[xx][yy]))
                lo = 1;
            if (abs(x[nx][ny]) > abs(x[xx][yy]))
                hi = 1;
        }
        ++p;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &x[i][j]);
            ++x[i][j];
        }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (x[i][j] > 0) {
                lo = hi = 0;
                dfs(i, j);
                if (!hi)
                    ++cnt1;
                if (!lo)
                    ++cnt2;
            }

    printf("%d %d", cnt1, cnt2);
    return 0;
}
