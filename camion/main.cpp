#include <stdio.h>

int x0[30000], x1[30000], y0[30000], y1[30000];

int main() {
    freopen("camion.in", "r", stdin);
    freopen("camion.out", "w", stdout);

    int N, M, op, col;
    scanf("%d%d%d%d", &N, &M, &op, &col);
    for (int i = 1; i <= op; ++i)
        scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]);
    for (int i = 1; i <= N; ++i)  {
        int pos = col;
        for (int j = op; j >= 1; --j)
            if (x0[j] <= i && i <= x1[j])
                if (y0[j] <= pos)
                    pos += y1[j] - y0[j] + 1;
        if (pos > M)
            pos = 0;
        printf("%d\n", pos);
    }
    return 0;
}
