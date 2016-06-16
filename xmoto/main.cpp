#include <stdio.h>
#include <algorithm>
#include <cassert>

using namespace std;

struct moto {
    double A, K, B, Q;
    int v;
} x[50100];

inline bool comp(moto A, moto B) {
    return A.v < B.v;
}

double sol[50100];

int main() {
    freopen("xmoto.in", "r", stdin);
    freopen("xmoto.out", "w", stdout);

    int N, sum;
    scanf("%d%d", &N, &sum);
    double xx = 0, yy = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%lf%lf%lf%lf%d", &x[i].A, &x[i].B, &x[i].K, &x[i].Q, &x[i].v);
        xx += x[i].A; yy += x[i].K;
    }

    x[++N].v = 10000;

    sort(x + 1, x + N + 1, comp);
    int cnt = 0;
    for (int i = 1; i <= N + 1; ++i) {
        double cur = ((double)sum - yy) / xx;
        if (x[i - 1].v <= cur && cur <= x[i].v)
            sol[++cnt] = cur;
        xx = xx - x[i].A + x[i].B;
        yy = yy - x[i].K + x[i].Q;
    }

    printf("%d\n", cnt);
    sort(sol + 1, sol + cnt + 1);
    for (int i = 1; i <= cnt; ++i)
        printf("%.6lf ", sol[i]);
    return 0;
}
