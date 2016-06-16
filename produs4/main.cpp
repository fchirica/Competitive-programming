#include <stdio.h>

int d[1000100];
const int mod = 10067;

int main() {
    freopen("data.out", "w", stdout);

    d[1] = 18;
    d[2] = 27;
    d[3] = 39;
    d[4] = 58;

    for (int i = 5; i <= 1000000; ++i) {
            if (i % 2 == 0)
                d[i % 5] = d[(i - 1) % 5] + d[(i - 3) % 5] + 1;
            else
                d[i % 5] = d[(i - 1) % 5] + d[(i - 3) % 5];
            if (d[i % 5] >= mod)
                d[i % 5] -= mod;

            if (i == 1000000) {
                int muie = 0;
                ++muie;
            }

            printf("%d ", d[i % 5]);
            //if (i % 1000000 == 0)
            //   printf("%d, %d, %d, %d,", d[(i - 3) % 5], d[(i - 2) % 5], d[(i - 1) % 5], d[i % 5]);
        }

    return 0;
}
