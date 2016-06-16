#include <stdio.h>

void openfiles() {
    #ifndef ONLINE_JUDGE
        freopen ("data.in", "r", stdin);
        freopen ("data.out", "w", stdout);
    #endif
}

long long d[100010];
int x[100010], x0[100010], y0[100010];
long long times[100010], mars[100010];

int main() {
    openfiles();

    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    int i;
    for (i = 1; i <= N; ++i)
        scanf("%d", &x[i]);
    for (i = 1; i <= M; ++i)
        scanf("%d%d%I64d", &x0[i], &y0[i], &d[i]);
    for (i = 1; i <= K; ++i) {
        int tmpx, tmpy;
        scanf("%d%d", &tmpx, &tmpy);
        ++times[tmpx]; --times[tmpy + 1];
    }
    for (i = 1; i <= M; ++i)
        times[i] += times[i - 1];
    for (i = 1; i <= M; ++i)
        d[i] = d[i] * times[i];

    for (i = 1; i <= M; ++i)
        mars[x0[i]] += d[i], mars[y0[i] + 1] -= d[i];
    for (i = 1; i <= N; ++i)
        mars[i] += mars[i - 1];

    for (i = 1; i <= N; ++i)
        printf("%I64d ", mars[i] + x[i]);
    return 0;
}

