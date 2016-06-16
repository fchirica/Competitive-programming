#include <stdio.h>
#include <string.h>

int dp[111][111];
char x[111];

bool solve(int st, int dr) {
    if (st > dr)
        return 1;
    if ((dr - st + 1) % 3)
        return 0;
    if (dp[st][dr] != -1)
        return dp[st][dr];
    if (dr == st + 2)
        return dp[st][dr] = (x[st] == x[dr]);

    for (int i = st + 2; i <= dr; ++i)
        if (x[st] == x[i])
            for (int j = st + 1; j < i; ++j)
                if (solve(st + 1, j - 1) && solve(j + 1, i - 1) && solve(i + 1, dr))
                    return dp[st][dr] = 1;
    return dp[st][dr] = 0;
}

void solveTest() {
    memset(dp, -1, sizeof(dp));
    gets(x + 1);
    int n = strlen(x + 1);
    printf("%s\n", solve(1, n) ? "DA" : "NU");
}

int main() {
    freopen("palin3.in", "r", stdin);
    freopen("palin3.out", "w", stdout);

    int T;
    scanf("%d\n", &T);
    while (T--)
        solveTest();
    return 0;
}
