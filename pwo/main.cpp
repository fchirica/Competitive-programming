#include <stdio.h>

int N, M, x[1024][1024];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool used[1024][1024];

inline int abs(int X) {
    return X > 0 ? X : -X;
}

void dfs(int xx, int yy) {
    used[xx][yy] = 1;
    for (int d = 0; d < 4; ++d) {
        int nx = xx + dx[d];
        int ny = yy + dy[d];
        if (nx <= 0 || ny <= 0 || nx > N || ny > M)
            continue;
        if (!used[nx][ny] && abs(x[nx][ny]) >= abs(x[xx][yy]))
            dfs(nx, ny);
    }
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &x[i][j]);

    int res = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (!used[i][j] && x[i][j] > 0) {
                ++res;
                dfs(i, j);
            }

    printf("%d", res);
    return 0;
}
