#include <stdio.h>

int op;

void recon(int A, int B) {
    if (A == 0 || B == 0) {
        printf("%d\n", op);
        return ;
    }
    if (A < B) {
        ++op;
        recon(B - A, 2 * A);
        printf("0\n");
    } else {
        ++op;
        recon(2 * B, A - B);
        printf("1\n");
    }
}

int main() {
    freopen("timp.in", "r", stdin);
    freopen("timp.out", "w", stdout);

    int N, K;
    scanf("%d%d", &N, &K);
    recon(K, N - K);

    return 0;
}
