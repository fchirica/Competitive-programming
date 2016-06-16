#include <stdio.h>
#define pw (1 << K)

int solve(int K, int x, int y) {
    if (K == 0)
        return 0;
    --K;
    if (x <= pw && y <= pw)
        return solve(K, y, x);
    if (x > pw && y <= pw)
        return pw * pw + solve(K, x - pw, y);
    if (x > pw && y > pw)
        return 2 * pw * pw + solve(K, x - pw, y - pw);
    return 3 * pw * pw + solve(K, 2 * pw - y + 1, pw - x + 1);
}

int main() {
    freopen("fractal.in", "r", stdin);
    freopen("fractal.out", "w", stdout);

    int K, x, y;
    scanf("%d%d%d", &K, &y, &x);
    printf("%d", solve(K, x, y));
    return 0;
}
