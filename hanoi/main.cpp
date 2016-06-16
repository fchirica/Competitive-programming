#include <stdio.h>

int dp[69][69];
int tp[69][69];
bool used[69];

void chmin(int &A, long long B) {
    if (A > B)
        A = B;
}

void move(int disk, int from, int to) {
    printf("move %d from %d to %d", disk, from, to);
    if (tp[to][0] > 0)
        printf(" atop %d", tp[to][tp[to][0]]);
    printf("\n");
    --tp[from][0]; tp[to][++tp[to][0]] = disk;
}

void recon(int cnt, int heaps, int supply, int from, int to) {
    int take, freeHeap;
    if (cnt == 1) {
        move(cnt + supply, from, to);
        return ;
    }
    for (take = 1; ; ++take)
        if (dp[cnt][heaps] == 2LL * dp[take][heaps] + dp[cnt - take][heaps - 1])
            break;
    for (freeHeap = 1; ; ++freeHeap)
        if (used[freeHeap] == 0 && freeHeap != from && freeHeap != to)
            break;
    recon(take, heaps, supply, from, freeHeap);
    used[freeHeap] = true;
    recon(cnt - take, heaps - 1, supply + take, from, to);
    used[freeHeap] = false;
    recon(take, heaps, supply, freeHeap, to);
}

int main() {
    freopen("hanoi.in", "r", stdin);
    freopen("hanoi.out", "w", stdout);

    int i, j, k, N, M;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M; ++j)
            dp[i][j] = 1 << 30;
    for (i = 2; i <= M; ++i)
        dp[1][i] = 1;
    for (i = 2; i <= N; ++i)
        for (j = 3; j <= M; ++j)
            for (k = 1; k < i; ++k)
                chmin(dp[i][j], 2LL * dp[k][j] + dp[i - k][j - 1]);
    printf("%d\n", dp[N][M]);
    for (i = 1; i <= N; ++i)
        tp[1][++tp[1][0]] = N - i + 1;
    recon(N, M, 0, 1, M);
    return 0;
}
