#include <stdio.h>
#include <math.h>

int main() {
    freopen("chiftea.in", "r", stdin);
    freopen("chiftea.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        int radical = sqrt(x);
        if (radical * radical == x) {
            printf("%d\n", 4 * radical);
            continue;
        }
        int lim = (radical + 1) * (radical + 1) - radical;
        if (x < lim)
            printf("%d\n", 4 * radical + 2);
        else
            printf("%d\n", 4 * radical + 4);
    }
    return 0;
}
