#include <stdio.h>

int f[50], pw[50], sol[1000000];

void extend(int idx, int lim) {
    int fact = f[idx];
    for (int i = 1; i <= pw[idx]; ++i) {
        if (i % 2 == 0)
            for (int j = 1; j <= lim; ++j)
                sol[++sol[0]] = fact * sol[j];
        else
            for (int j = lim; j >= 1; --j)
                sol[++sol[0]] = fact * sol[j];
        fact = fact * f[idx];
    }
}

int main() {
    freopen("divizori.in", "r", stdin);
    freopen("divizori.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            f[++f[0]] = i;
            ++pw[0];
            while (n % i == 0) {
                ++pw[pw[0]];
                n /= i;
            }
        }

    if (n > 1) {
        f[++f[0]] = n;
        pw[++pw[0]] = 1;
    }

    sol[++sol[0]] = 1;
    for (int i = 1; i <= pw[0]; ++i)
        extend(i, sol[0]);
    printf("%d\n", sol[0]);

    for (int i = 1; i <= sol[0]; ++i)
        printf("%d ", sol[i]);
    return 0;
}
