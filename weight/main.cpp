#include <stdio.h>

int x[1000100];

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &x[i]);

        long long res = 0, sum = 0, cur = 0;
        for (int i = n; i > 1; --i) {
            sum += x[i];
            cur += sum;
            if (sum < 0) {
                res += cur;
                sum = cur = 0;
            }
        }
        res += cur + x[1];
        for (int i = 2; i <= n; ++i)
            res += x[i];
        printf("%lld\n", res);
    }

    return 0;
}
