#include <stdio.h>
#include <algorithm>

using namespace std;

int x[1024];

int main() {
    freopen("prieteni.in", "r", stdin);
    freopen("prieteni.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    sort(x + 1, x + n + 1);

    int res = 0, i = n;
    while (i) {
        if (i == 1) {
            res += x[1];
            --i;
            printf("%d\n", x[1]);
        }
        else if (i == 2) {
            res += x[2];
            i -= 2;
            printf("%d %d\n", x[1], x[2]);
        } else if (i == 3) {
            res += x[1] + x[2] + x[3];
            i -= 3;
            printf("%d %d\n", x[1], x[3]);
            printf("%d\n", x[1]);
            printf("%d %d\n", x[1], x[2]);
        }
        else {
            int separate = 2 * x[1] + x[i] + x[i - 1];
            int together = x[1] + 2 * x[2] + x[i];
            if (together > separate) {
                printf("%d %d\n", x[1], x[i]);
                printf("%d\n", x[1]);
                printf("%d %d\n", x[1], x[i - 1]);
                printf("%d\n", x[1]);
            } else {
                printf("%d %d\n", x[1], x[2]);
                printf("%d\n", x[2]);
                printf("%d %d\n", x[i - 1], x[i]);
                printf("%d\n", x[1]);
            }
            i -= 2;
            res += min(together, separate);
        }
    }

    printf("%d", res);
    return 0;
}
