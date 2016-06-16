#include <stdio.h>

int main() {
    freopen("triplet.in", "r", stdin);
    freopen("triplet.out", "w", stdout);

    int n;
    scanf("%d", &n);
    if (n % 2)
        printf("%d %d 0", n - n / 2, -n / 2);
    else
        printf("%d %d -1", n / 2 + 1, -n / 2);

    return 0;
}
