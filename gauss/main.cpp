//Eliminare gaozara

#include <stdio.h>
#include <algorithm>
#define EPS 0.0000001

using namespace std;

double x[305][305], sol[305];

int main() {
    freopen("gauss.in", "r", stdin);
    freopen("gauss.out", "w", stdout);

    int i, j, k, N, M;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M + 1; ++j)
            scanf("%lf", &x[i][j]);

    i = 1; j = 1;
    while (i <= N && j <= M) {
        for (k = i; k <= N; ++k)
            if (!(-EPS <= x[k][j] && x[k][j] <= EPS))
                break;
        if (k == N + 1) {
            ++j;
            continue;
        }
        int ret;
        for (ret = 1; ret <= M + 1; ++ret)
            swap(x[k][ret], x[i][ret]);
        double tmp = x[i][j];
        for (k = 1; k <= M + 1; ++k)
            x[i][k] = x[i][k] / tmp;
        for (k = i + 1; k <= N; ++k) {
            for (ret = 1; ret <= M + 1; ++ret)
                if (ret != j)
                    x[k][ret] = x[k][ret] - x[i][ret] * x[k][j];
            x[k][j] = 0;
        }
        ++i; ++j;
    }

    for (i = N; i >= 1; --i) {
        for (j = 1; j <= M + 1; ++j)
            if (!(-EPS <= x[i][j] && x[i][j] <= EPS))
                break;
            if (j == M + 1)
                if (x[i][j]) {
                    printf("Imposibil");
                    return 0;
                }
                else
                    continue;
            sol[j] = x[i][M + 1];
            for (k = M; k >= j + 1; --k)
                sol[j] = sol[j] - x[i][k] * sol[k];
    }

    for (i = 1; i <= M; ++i)
        printf("%.8lf ", sol[i]);
    return 0;
}
