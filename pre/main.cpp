#include <stdio.h>

char x[1000100], y[1000100], xx[2 * 1000100];
int R[2000100], f[2000100], best[2000100];

int main() {
    int N;
    scanf("%d\n", &N);
    gets(x + 1);
    int l = 1, rr = N, cnt = 0;
    while (l <= rr) {
        y[++cnt] = x[l];
        if (l != rr)
            y[++cnt] = x[rr];
        ++l; --rr;
    }
    for (int i = 1; i <= N; ++i) {
        xx[2 * i - 1] = y[i];
        xx[2 * i] = '#';
    }

    int c = 0, r = 0;
    for (int i = 1; i <= 2 * N; ++i)
        if (i > c + r) {
            for (r = 0; i - r >= 1 && i + r <= 2 * N && xx[i - r] == xx[i + r]; ++r); --r;
            R[i] = r; c = i;
        } else {
            int tmp = R[2 * c - i];
            if (tmp > c + r - i)
                tmp = c + r - i;
            if (tmp == c + r - i) {
                for (; i - tmp >= 1 && i + tmp <= 2 * N && xx[i - tmp] == xx[i + tmp]; ++tmp); --tmp;
                r = tmp; c = i;
            }
            R[i] = tmp;
        }

    for (int i = 2; i <= 2 * N; i += 2) {
        f[i] = i - R[i];
        best[f[i] - 1] = i;
    }
    for (int i = 1; i <= 2 * N; ++i)
        if (best[i - 1] > best[i])
            best[i] = best[i - 1];
    int res = 0;
    for (int i = 2; i <= 2 * N; i += 2)
        if (f[i] == 1) {
            int firstEnd = i + R[i];
            int bestj = best[firstEnd];
            if (2 * bestj - firstEnd - 1 > res)
                res = 2 * bestj - firstEnd - 1;
        }

    printf("%d", res / 4);
    return 0;
}
