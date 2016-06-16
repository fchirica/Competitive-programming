#include <stdio.h>
#include <string.h>

char A[10], B[10], pat[115];
int single[30], two[30][30], dp[115][115];
int x[30], y[30];

void get(int X[], int mask) {
    X[0] = 0;
    for (int b = 0; (1 << b) <= mask; ++b)
        if (mask & (1 << b))
            X[++X[0]] = b;
}

int split(int mask1, int mask2) {
    get(x, mask1);
    get(y, mask2);
    int res = 0;
    for (int i = 1; i <= x[0]; ++i)
        for (int j = 1; j <= y[0]; ++j)
            res |= two[x[i]][y[j]];
    return res;
}

int main() {
    freopen("minerale.in", "r", stdin);
    freopen("minerale.out", "w", stdout);

    int N, M;
    scanf("%d%d\n", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%s %s\n", &A, &B);
        if ('a' <= B[0] && B[0] <= 'z')
            single[B[0] - 'a'] |= (1 << (A[0] - 'A'));
        else
            two[B[0] - 'A'][B[1] - 'A'] |= (1 << (A[0] - 'A'));
    }

    while (M--) {
        gets(pat + 1);
        int n = strlen(pat + 1);
        for (int i = 1; i <= n; ++i)
            dp[i][i] = single[pat[i] - 'a'];
        for (int len = 2; len <= n; ++len)
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                dp[i][j] = 0;
                for (int k = i; k < j; ++k)
                    dp[i][j] |= split(dp[i][k], dp[k + 1][j]);
            }
        if (dp[1][n] & (1 << ('S' - 'A')))
            printf("1\n");
        else if (dp[1][n])
            printf("2\n");
        else
            printf("0\n");
    }

    return 0;
}
