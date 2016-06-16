#include <stdio.h>
#include <string.h>

int f[10], X[111], Y[111], xx[111], yy[111], bX[111], bY[111];

inline int max(int A, int B) {
    return A > B ? A : B;
}

int ff[10];

bool baga(int a[], int pos) {
    int pos2 = a[0] - pos + 1;
    int start = 0;
    if (pos == 1)
        start = 1;
    if (pos == pos2) {
        for (int c = start; c <= 9; ++c)
            if (ff[c] % 2) {
                a[pos] = c; --ff[c];
                return 1;
            }
        for (int c = start; c <= 9; ++c)
            if (ff[c]) {
                a[pos] = c; --ff[c];
                return 1;
            }
    }
    for (int c = start; c <= 9; ++c)
        if (ff[c] >= 2) {
            a[pos] = c, a[pos2] = c, ff[c] -= 2;
            return 1;
        }
    return 0;
}

bool good(int cnt1, int cnt2) {
    bool shit = 1;
    xx[0] = cnt1; yy[0] = cnt2;
    for (int i = 0; i <= 9; ++i)
        ff[i] = f[i];
    int px = xx[0] - max(xx[0], yy[0]) + 1, py = yy[0] - max(xx[0], yy[0]) + 1;
    for (int i = 1; i <= xx[0] || i <= yy[0]; ++i) {
        if (xx[0] >= yy[0]) {
            if (px > 0 && px <= xx[0] - px + 1)
                shit &= baga(xx, px);
            if (py > 0 && py <= yy[0] - py + 1)
                shit &= baga(yy, py);
        } else {
            if (py > 0 && py <= yy[0] - py + 1)
                shit &= baga(yy, py);
            if (px > 0 && px <= xx[0] - px + 1)
                shit &= baga(xx, px);
        }
        ++px; ++py;
    }
    for (int i = 0; i <= 9; ++i)
        if (ff[i])
            return 0;
    return shit;
}

int main() {
    freopen("pal.in", "r", stdin);
    freopen("pal.out", "w", stdout);

    int L;
    scanf("%d", &L);
    int sum = 0;
    for (int i = 0; i <= 9; ++i) {
        scanf("%d", &f[i]);
        sum += f[i];
    }
    int mx = 1000000000;
    for (int i = L; i < sum; ++i)
        if (good(i, sum - i))
            if (max(i, sum - i) < mx) {
                mx = max(i, sum - i);
                memcpy(X, xx, sizeof(X));
                memcpy(Y, yy, sizeof(Y));
            }

    for (int i = 1; i <= X[0]; ++i)
        printf("%d", X[i]);
    printf("\n");
    for (int i = 1; i <= Y[0]; ++i)
        printf("%d", Y[i]);
    return 0;
}
