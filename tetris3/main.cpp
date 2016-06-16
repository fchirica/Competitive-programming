#include <stdio.h>
#define ull unsigned long long

ull pw2[64], mars[400400];

int main() {
    freopen("tetris3.in", "r", stdin);
    freopen("tetris3.out", "w", stdout);

    int n, m, a, b, c, x, y;
    scanf("%d%d%d%d%d%d%d", &n, &m, &a, &b, &c, &x, &y);

    pw2[0] = 1;
    for (int i = 1; i < 64; ++i)
        pw2[i] = pw2[i - 1] * 2;

    if (a <= b) {
        mars[a] += pw2[64 - c];
        mars[b + 1] -= pw2[64 - c];
    } else {
        mars[b] += pw2[64 - c];
        mars[a + 1] -= pw2[64 - c];
    }

    for (int i = 2; i <= m; ++i) {
        a = ((ull) a * i) % 1008989;
		if (a > n)
			a = n;
		b = ((ull) b * i) % 1008989;
		if (b > n)
			b = n;
		c = (c * x + y) % 47 + 1;

        if (a <= b) {
            mars[a] += pw2[64 - c];
            mars[b + 1] -= pw2[64 - c];
        } else {
            mars[b] += pw2[64 - c];
            mars[a + 1] -= pw2[64 - c];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        mars[i] += mars[i - 1];
        ull tmp = mars[i];
        while (tmp > 0) {
            ++res;
            tmp = tmp & (tmp - 1);
        }
    }

    printf("%d", res);
    return 0;
}
