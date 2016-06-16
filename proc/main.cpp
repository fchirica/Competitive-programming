#include <stdio.h>

int left[70000];

int proc(int T, int t1, int t2, int lim) {
    for (int i = 1; i <= lim; ++i)
        left[i] = T;
    for (int i = 1; i <= lim; ++i) {
        int can = T / (2 * i);
        if (can > t2)
            can = t2;
        left[i] = left[i] - can * 2 * i;
        t2 = t2 - can;
    }
    for (int i = 1; i <= lim; ++i) {
        int can = left[i] / i;
        if (can > t1)
            can = t1;
        t1 = t1 - can;
    }
    return (t1 == 0 && t2 == 0);
}

int main() {
    freopen("proc.in", "r", stdin);
    freopen("proc.out", "w", stdout);

    int N, K, P;
    scanf("%d%d%d", &N, &K, &P);
    int t1 = K, t2 = N - K;

    long long st = 0, dr = 1LL << 31, med;
    int sol;
    while (st <= dr) {
        med = (st + dr) / 2;
        if (proc(med, t1, t2, P))
            sol = (int)med, dr = med - 1;
        else
            st = med + 1;
    }

    printf("%d", sol);
    return 0;
}
