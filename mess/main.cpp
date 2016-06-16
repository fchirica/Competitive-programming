#include <stdio.h>

int main() {
    freopen("fenrir.in", "r", stdin);
    freopen("fenrir.out", "w", stdout);

    printf("99\n");
    for (int i = 1; i <= 9; ++i)
        for (int j = 10; j <= 20; ++j)
            printf("%d %d\n", i, j);

    return 0;
}
