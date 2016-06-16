#include <stdio.h>

int main() {
    freopen("data.out", "w", stdout);

    int n = 1000, m = 1000;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            printf("100000");
            if (j == m)
                printf("\n");
            else
                printf(" ");
        }

    return 0;
}
