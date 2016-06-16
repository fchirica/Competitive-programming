#include <stdio.h>
#include <math.h>

int main() {
    freopen("sir.out", "w", stdout);

    int n;
    for (int n = 1; n <= 35; ++n) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res += n / i;
        printf("%d,", res);
    }
    printf("\n\n\n");
    for (int n = 1; n <= 15; ++n) {
        int sum = 0;
        for (int i = 1; i <= floor(sqrt(n)); ++i)
            sum += floor(n / i);
        sum -= floor(sqrt(n)) * floor(sqrt(n));
        sum = 2 * sum * sum;
        printf("%d,", sum);
    }
    return 0;
}
