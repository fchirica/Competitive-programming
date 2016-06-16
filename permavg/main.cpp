#include <stdio.h>

int res[20000];

void solve(int st, int dr) {
    int N = dr - st + 1;
    if (st > dr)
        return ;
    if (N == 1) {
        res[st] = 1;
        return ;
    }
    int even = N / 2;
    solve(st, st + even - 1);
    for (int i = st; i <= st + even - 1; ++i)
        res[i] *= 2;
    solve(st + even, dr);
    for (int i = st + even; i <= dr; ++i)
        res[i] = res[i] * 2 - 1;
}

int main() {
    freopen("permavg.in", "r", stdin);
    freopen("permavg.out", "w", stdout);

    int N;
    scanf("%d", &N);
    solve(1, N);

    for (int i = 1; i <= N; ++i)
        printf("%d ", res[i]);
    return 0;
}
