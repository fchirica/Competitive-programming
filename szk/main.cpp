#include <stdio.h>
#include <algorithm>

using namespace std;

struct punct {
    int x, y, idx;
    bool corner;
} x[100100], B[300300], diag1[300300], diag2[300300];

bool vis[2][2][300300]; //(type of diagonal, direction of diagonal, point)

bool comp1(punct A, punct B) {
    return A.x + A.y < B.x + B.y;
}

bool comp2(punct A, punct B) {
    return A.x - A.y < B.x - B.y;
}

void go(punct X, int type, int dir) {

}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &x[i].x, &x[i].y);
        x[i].idx = i;
    }

    x[N + 1] = x[1];
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        if (x[i].x == x[i + 1].x)
            for (int j = min(x[i].y, x[i + 1].y) + 1; j < max(x[i].x, x[i + 1].x; ++j) {
                B[++cnt].x = x[i].x;
                B[cnt].y = j;
                B[cnt].corner = 0;
            }
        else
            for (int j = min(x[i].x, x[i + 1].x) + 1; j < max(x[i].y, x[i + 1].y); ++j) {
                B[++cnt].x = j;
                B[cnt].y = x[i].y;
                B[cnt].corner = 0;
            }
    for (int i = 1; i <= N; ++i) {
        B[++cnt] = x[i];
        B[cnt].corner = 1;
    }

    for (int i = 1; i <= cnt; ++i)
        diag1[i] = diag2[i] = B[i];
    sort(diag1 + 1, diag1 + cnt + 1, comp1);
    sort(diag2 + 1, diag2 + cnt + 1, comp2);



    return 0;
}
