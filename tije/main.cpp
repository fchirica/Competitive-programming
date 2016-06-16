#include <stdio.h>

int main() {
    freopen("tije.in", "r", stdin);
    freopen("tije.out", "w", stdout);

    int N;
    scanf("%d", &N);

    for (int move = N - 1; move >= 1; --move) {
        for (int i = 1; i <= move; ++i)
            printf("1 %d\n", N + 1);
        for (int i = 2; i <= N + 1; ++i)
            for (int times = 1; times <= move; ++times)
                printf("%d %d\n", i, i - 1);
    }

    return 0;
}
