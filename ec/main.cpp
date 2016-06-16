#include <stdio.h>
#include <math.h>

int main() {
    int A, B, C;

    scanf("%d%d%d", &A, &B, &C);
    printf("D = %d - 4 * %d * %d\n", B * B, A, C);
    int d = B * B - 4 * A * C;
    double sqr = sqrt(d);
    printf("Delta = %d\nRadical %lf \n", d, sqr);
    printf("x1 = (%d - %lf) / (2 * %d) = %lf\n", -B, sqr, A, (-B - sqr) / (2 * A));
    printf("x2 = (%d + %lf) / (2 * %d) = %lf\n", -B, sqr, A, (-B + sqr) / (2 * A));

    return 0;
}
