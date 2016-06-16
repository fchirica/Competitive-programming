#include <stdio.h>

int main() {
    freopen("joc5.in", "r", stdin);
    freopen("joc5.out", "w", stdout);

    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0)
            break;
        int xorsum = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)  {
                int tmp;
                scanf("%d", &tmp);
                if (i == j)
                    xorsum ^= tmp;
            }
        printf("%d\n", xorsum ? 1 : 2);
    }

    return 0;
}
