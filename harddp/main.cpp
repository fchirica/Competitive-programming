/* Florin Chirica
   solutie cu complexitate proasta - TLE
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[2][701][701];
char A[701];

int recurse(int i, int j, int c) {
    if (i == 0) {
        for (int i = 1; i <= j; ++i)
            printf("1");
    }

    if ((char) c + '0' == A[i]) {
        if (dp[0][i - 1][j - 1] + 1 == dp[c][i][j])
            recurse(i - 1, j - 1, 0);
        else
            recurse(i - 1, j - 1, 1);
        printf("%d", c);
    } else {
        if (dp[c][i - 1][j] == dp[c][i][j])
            recurse(i - 1, j, c);
        else {
            if (dp[0][i][j - 1] == dp[c][i][j])
                recurse(i, j - 1, 0);
            else
                recurse(i, j - 1, 1);
            printf("%d", c);
        }
    }
}

int main() {
    freopen("harddp.in", "r", stdin);
    freopen("harddp.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d\n", &n);
        gets(A + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                for (int c = 0; c <= 1; ++c)
                    if ((char) c + '0' == A[i])
                        dp[c][i][j] = 1 + min(dp[0][i - 1][j - 1], dp[1][i - 1][j - 1]);
                    else {
                        dp[c][i][j] = min(dp[0][i][j - 1], dp[1][i][j - 1]);
                        dp[c][i][j] = max(dp[c][i][j], dp[c][i - 1][j]);
                    }
        if (dp[0][n][n] < dp[1][n][n])
            recurse(n, n, 0);
        else
            recurse(n, n, 1);
        printf("\n");
    }

    return 0;
}
