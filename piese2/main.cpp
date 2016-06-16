#include <stdio.h>

int main() {
    freopen("piese2.in", "r", stdin);
    freopen("piese2.out", "w", stdout);

    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; ++i) {
        int win = 0;
        for (int j = 1; j <= K; ++j) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            win ^= (((yy - xx) % 2) ^ 1);
        }
        printf("%s\n", win ? "Miruna" : "Aglaia");
    }

    return 0;
}
