#include <stdio.h>

int main() {
    freopen("cmmdc.in", "r", stdin);
    freopen("cmmdc.out", "w", stdout);

    int A, B;
    scanf("%d%d", &A, &B);
    int sol = 0;
    for (int d = 30000; d > 1; --d)
        if (A % d == 0 && B % d == 0) {
            sol = d;
            break;
        }
    printf("%d", sol);
    return 0;
}
