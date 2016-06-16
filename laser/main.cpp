#include <stdio.h>
#include <algorithm>
#include <math.h>
#define EPS 0.0000001

using namespace std;

double ang[1024], x[1024];
int A[555], B[555], C[555], D[555], shit[555];
bool change[555][1024], sol[1024];

double getAngle(int xx, int yy) {
    double alfa = (double)180 * atan2(yy, xx) / (2 * acos(0));
    if (alfa < 0)
        alfa += 360;
    return alfa;
}

int main() {
    freopen("laser.in", "r", stdin);
    freopen("laser.out", "w", stdout);

    int N, cnt = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
        ang[++cnt] = getAngle(A[i], B[i]);
        ang[++cnt] = getAngle(C[i], D[i]);
    }
    for (int i = 1; i <= N; ++i)
        scanf("%d", &shit[i]);
    sort(ang + 1, ang + cnt + 1);
    for (int i = 1; i < cnt; ++i) {
        x[i] = (ang[i] + ang[i + 1]) / 2;
        if (x[i] > 360)
            x[i] -= 360;
    }

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j < cnt; ++j) {
            double ang1 = getAngle(A[i], B[i]);
            double ang2 = getAngle(C[i], D[i]);
            if (ang1 > ang2 + EPS)
                swap(ang1, ang2);
            if (ang2 - ang1 - EPS < 180)
                change[i][j] = (ang1 - EPS <= x[j] && x[j] <= ang2 + EPS);
            else
                change[i][j] = (ang2 - EPS <= x[j] || x[j] <= ang1 + EPS);
        }
    for (int i = 1; i <= N; ++i)
        change[i][cnt] = shit[i];

    int i = 1, j = 1;
    while (i <= N && j < cnt) {
        int lin = 0;
        for (int k = i; k <= N; ++k)
            if (change[k][j] == 1) {
                lin = k;
                break;
            }
        if (lin == 0) {
            ++j;
            continue;
        }
        for (int k = 1; k <= cnt; ++k)
            swap(change[i][k], change[lin][k]);
        for (int k = i + 1; k <= N; ++k)
            if (change[k][j] == 1)
                for (int col = 1; col <= cnt; ++col)
                    change[k][col] ^= change[i][col];
        ++i; ++j;
    }

    int cntSol = 0;
    for (int i = N; i >= 1; --i)
        for (int j = 1; j <= cnt; ++j)
            if (change[i][j]) {
                sol[j] = change[i][cnt];
                for (int k = cnt - 1; k > j; --k)
                    sol[j] ^= sol[k] * change[i][k];
                cntSol += sol[j];
                break;
            }

    printf("%d\n", cntSol);
    for (int i = 1; i < cnt; ++i)
        if (sol[i])
            printf("%.6lf\n", x[i]);
    return 0;
}
