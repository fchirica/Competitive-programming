#include <stdio.h>

void gcd(int a, int &x, int b, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return ;
    }
    int x0, y0;
    gcd(b, x0, a % b, y0);
    x = y0; y = x0 - (a / b) * y0;
}

int main() {
    freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);

    int A, M;
    scanf("%d%d", &A, &M);

    int xx, yy;
    gcd(A, xx, M, yy);
    while (xx < 0)
        xx += M;
    printf("%d", xx);

    return 0;
}
