#include <stdio.h>

int x[22];

int main() {
    freopen("subsecvente.in", "r", stdin);
    freopen("subsecvente.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    while (N) {
        x[++x[0]] = N % 10;
        N /= 10;
    }
    int st = 1, dr = x[0];
    while (st <= dr) {
        int tmp = x[st];
        x[st] = x[dr];
        x[dr] = tmp;
        ++st; --dr;
    }

    int res = 0;
    for (int i = 1; i <= x[0]; ++i)
        if (x[i]) {
            int cur = 0;
            for (int j = i; j <= x[0]; ++j) {
                cur = cur * 10 + x[j];
                if (cur > M)
                    break;
                ++res;
            }
        }
    printf("%d", res);
    return 0;
}
