#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#define x first
#define y second

using namespace std;

char x[777][777];
bool blocked[777][777];
int DX[] = {-1, 0, 1, 0}, DY[] = {0, 1, 0, -1};
int dy[777][777], dv[777][777];
pair <int, int> Q[777 * 777];
int vBucket[777][777], hBucket[777][777];
int bestV[777 * 777], bestH[777 * 777];

int main() {
    int N, M;
    scanf("%d%d\n\n", &N, &M);
    for (int i = 1; i <= N; ++i)
        gets(x[i] + 1);

    int yx, yy, vx, vy, tx, ty;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (x[i][j] == 'Y')
                yx = i, yy = j;
            else
            if (x[i][j] == 'V')
                vx = i, vy = j;
            else
            if (x[i][j] == 'I')
                blocked[i][j] = 1;
            else
            if (x[i][j] == 'T')
                tx = i, ty = j;

    int cntV = 0, cntH = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (!blocked[i][j]) {
                if (vBucket[i - 1][j])
                    vBucket[i][j] = vBucket[i - 1][j];
                else
                    vBucket[i][j] = ++cntV;
                if (hBucket[i][j - 1])
                    hBucket[i][j] = hBucket[i][j - 1];
                else
                    hBucket[i][j] = ++cntH;
            }

    for (int i = 1; i <= cntV; ++i)
        bestV[i] = 1 << 30;
    for (int i = 1; i <= cntH; ++i)
        bestH[i] = 1 << 30;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dv[i][j] = 1 << 30;
    dv[vx][vy] = 0;
    int p = 1, u = 0;
    Q[++u] = make_pair(vx, vy);
    bestV[vBucket[vx][vy]] = bestH[hBucket[vx][vy]] = 0;

    while (p <= u) {
        pair <int, int> cur = Q[p];
        for (int d = 0; d < 4; ++d) {
            pair <int, int> next;
            next.x = cur.x + DX[d];
            next.y = cur.y + DY[d];
            if (!blocked[next.x][next.y] && dv[next.x][next.y] == 1 << 30) {
                dv[next.x][next.y] = dv[cur.x][cur.y] + 1;
                Q[++u] = next;
                int curVBucket = vBucket[next.x][next.y];
                if (bestV[curVBucket] > dv[next.x][next.y])
                    bestV[curVBucket] = dv[next.x][next.y];
                int curHBucket = hBucket[next.x][next.y];
                if (bestH[curHBucket] > dv[next.x][next.y])
                    bestH[curHBucket] = dv[next.x][next.y];
            }
        }
        ++p;
    }

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            int curHBucket = hBucket[i][j];
            int curVBucket = vBucket[i][j];
            dv[i][j] = min(bestH[curHBucket], bestV[curVBucket]);
        }

    p = 1; u = 0;
    Q[++u] = make_pair(yx, yy);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dy[i][j] = 1 << 30;
    dy[yx][yy] = 0;
    while (p <= u) {
        pair <int, int> cur, next;
        cur = Q[p];
        for (int d = 0; d < 4; ++d) {
            next.x = cur.x + DX[d];
            next.y = cur.y + DY[d];
            if (!blocked[next.x][next.y] && dy[next.x][next.y] == 1 << 30) {
                int potentialDist = dy[cur.x][cur.y] + 1;
                if (potentialDist < dv[next.x][next.y]) {
                    dy[next.x][next.y] = potentialDist;
                    Q[++u] = next;
                }
            }
        }
        ++p;
    }

    printf("%s", dy[tx][ty] != (1 << 30) ? "YES" : "NO");
    return 0;
}
