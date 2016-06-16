#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)

int x[3000], grup[3000], len[3000];

int calc(int K1) {
    int len = 1;
    for (int i = 2; i <= grup[0]; ++i)
        if (grup[i] != grup[i - 1])
            ++len;
    if (len > K1)
        len = K1;
    return len;
}

int dp[2][2511];
int sdmax[2511];

void chmax(int &A, int B) {
    if (A < B)
        A = B;
}

int main() {
    freopen("concert2.in", "r", stdin);
    freopen("concert2.out", "w", stdout);

    int n, K1, K2;
    scanf("%d%d%d", &n, &K1, &K2);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    if (K1 == 1) {
        for (int i = 1; i <= n; ++i) {
            sdmax[i] = 0;
            for (int j = 1; j < i; ++j)
                if (sdmax[j] > sdmax[i] && x[j] > x[i])
                    sdmax[i] = sdmax[j];
            ++sdmax[i];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
            chmax(res, sdmax[i]);
        if (res > K2)
            res = K2;
        printf("%d", res);
        return 0;
    }

    grup[++grup[0]] = x[1];
    for (int i = 2; i <= n; ++i)
        if (x[i] >= x[i - 1])
            grup[++grup[0]] = x[i];
        else {
            len[++len[0]] = calc(K1);
            grup[0] = 0;
            grup[++grup[0]] = x[i];
        }
    len[++len[0]] = calc(K1);

    for (int i = 1; i <= len[0]; ++i) {
        int cur = i % 2, prev = (i + 1) % 2;
        for (int j = 1; j < K2; ++j) {
            if (len[i] == 1)
                chmax(dp[cur][j + 1], dp[prev][j] + 1);
            else
                chmax(dp[cur][1], dp[prev][j] + len[i]);
            chmax(dp[cur][j], dp[prev][j]);
        }
        if (i == len[0])
            break;
        memset(dp[cur], 0, sizeof(cur));
    }

    int res = 0;
    for (int i = 1; i <= K2; ++i)
        res = max(res, dp[len[0] % 2][i]);

    printf("%d", res);
    return 0;
}
