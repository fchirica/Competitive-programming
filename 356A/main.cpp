#include <stdio.h>

int f[5];

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++f[tmp]; sum += tmp;
    }

    int best = 1000000000;
    for (int t = 0; t <= N; ++t) {
        if (sum - 3 * t < 0 || (sum - 3 * t) % 4)
            continue;
        int p = (sum - 3 * t) / 4, cst = 0;
        if (f[4] >= p)
            cst = f[4] - p + f[1];
        else
            cst = p - f[4] + f[1];
        if (cst < best)
            best = cst;
    }

    if (best == 1000000000)
        printf("-1");
    else
        printf("%d", best);
    return 0;
}
