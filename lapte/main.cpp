#include <bits/stdc++.h>

const int kNMax = 111;

int n, tot, res;
int milkA[kNMax], milkB[kNMax];
int dp[kNMax][kNMax], recon[kNMax][kNMax]; //# de betivi, # de L de lapte A bauti

bool can(int maxTime) {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= tot; ++j) {
            dp[i][j] = -1000;
            recon[i][j] = 0;
        }

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= tot; ++j)
            if (dp[i][j] != -1000)
                for (int drankA = 0; drankA + j <= tot; ++drankA) {
                    int drinkTimeA = milkA[i + 1] * drankA;
                    if (drinkTimeA > maxTime)
                        break;
                    int drankB = (maxTime - drinkTimeA) / milkB[i + 1];
                    if (dp[i + 1][j + drankA] < dp[i][j] + drankB) {
                        dp[i + 1][j + drankA] = dp[i][j] + drankB;
                        recon[i + 1][j + drankA] = j;
                    }
                }
    return dp[n][tot] >= tot;
}

void trace(int n, int sum) {
    if (n == 0)
        return ;
    int drankA = sum - recon[n][sum];
    int drankB = (res - drankA * milkA[n]) / milkB[n];
    trace(n - 1, sum - drankA);
    printf("%d %d\n", drankA, drankB);
}

int main() {
    freopen("lapte.in", "r", stdin);
    freopen("lapte.out", "w", stdout);

    scanf("%d%d", &n, &tot);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &milkA[i], &milkB[i]);

    int st = 0, dr = 100;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (can(med)) {
            res = med;
            dr = med - 1;
        } else
            st = med + 1;
    }

    printf("%d\n", res);
    can(res);
    trace(n, tot);

    return 0;
}
