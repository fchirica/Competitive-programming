#include <stdio.h>
#include <string.h>

int N, R, K, st[100100], dr[100100];
int dp[6][100100];

const int mod = 10007;

int solve(int c, int nod) {
    if (dp[c][nod] != -1)
        return dp[c][nod];

    int left, right;
    if (st[nod] == 0)
        left = (c == 1 || c == 2) ? 1 : 0;
    else {
        if (c == 1 || c == 2)
            left = (K - 1) * solve(3, st[nod]) + (K - 1) * (K - 2) * solve(5, st[nod]);
        else
            left = solve(1, st[nod]) + (K - 2) * solve(2, st[nod]) + (K - 2) * solve(3, st[nod]) + (K - 2) * solve(4, st[nod]) + (K - 2) * (K - 3) * solve(5, st[nod]);
    }
    if (dr[nod] == 0)
        right = (c == 1 || c == 3) ? 1 : 0;
    else {
        if (c == 1 || c == 3)
            right = (K - 1) * solve(2, dr[nod]) + (K - 1) * (K - 2) * solve(5, dr[nod]);
        else
            right = solve(1, dr[nod]) + (K - 2) * solve(2, dr[nod]) + (K - 2) * solve(3, dr[nod]) + (K - 2) * solve(4, dr[nod]) + (K - 2) * (K - 3) * solve(5, dr[nod]);
    }

    return dp[c][nod] = (left % mod) * (right % mod) % mod;
}

int main() {
    freopen("acolor.in", "r", stdin);
    freopen("acolor.out", "w", stdout);

    scanf("%d%d%d", &N, &R, &K);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &st[i], &dr[i]);

    memset(dp, -1, sizeof(dp));

    int res = 1LL * K * solve(1, R) % mod;
    for (int i = 2; i <= 4; ++i)
        res = (res + 1LL * K * (K - 1) * solve(i, R) % mod) % mod;
    res = (res + 1LL * K * (K - 1) * (K - 2) * solve(5, R) % mod) % mod;

    printf("%d", res);
    return 0;
}
