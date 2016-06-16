#include <stdio.h>

int sqr[405 * 405];

int solve(int H, int W) {
    int res = 0;
    for (int A = 1; A <= H; ++A) {
        int delta = W * W - 4 * A * (H - A);
        if (delta < 0)
            continue;
        if (delta == 0)
            res += 1 - W % 2;
        else {
            delta = sqr[delta];
            if (delta == 0)
                continue;
            if ((W - delta) % 2 == 0)
                res += (1 <= (W - delta) / 2 && (W - delta) / 2 <= W);
            if ((W + delta) % 2 == 0)
                res += (1 <= (W + delta) / 2 && (W + delta) / 2 <= W);
        }
    }
    return res;
}

int main() {
    freopen("dreptunghiuri.in", "r", stdin);
    freopen("dreptunghiuri.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    --N; --M;

    for (int i = 1; i <= 400; ++i)
        sqr[i * i] = i;
    long long res = 0;
    for (int h = 1; h <= N; ++h)
        for (int w = 1; w <= M; ++w)
            res += 1LL * solve(h, w) * (N - h + 1) * (M - w + 1);

    printf("%lld", res);
    return 0;
}
