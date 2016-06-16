#include <stdio.h>

int val[100100], r[100100];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; ++i) {
        int posx, posy, init, rr;
        scanf("%d%d%d%d", &posx, &posy, &init, &rr);
        val[posx] += init;
        r[posx] += rr;
        val[posy + 1] -= init + (posy - posx + 1) * rr;
        r[posy + 1] -= rr;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", val[i]);
        val[i + 1] += val[i] + r[i];
        r[i + 1] += r[i];
    }
    return 0;
}
