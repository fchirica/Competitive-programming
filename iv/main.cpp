#include <bits/stdc++.h>

using namespace std;

const int kMod = 3210121;

int dp[2][555][555];
char A[555];
char B[555];

int main() {
    freopen("iv.in", "r", stdin);
    freopen("iv.out", "w", stdout);

    gets(A + 1);
    gets(B + 1);
    int n = strlen(A + 1);
    int m = strlen(B + 1);

    dp[0][0][0] = 1;

    int tot = 0;
    for (int prefA = 0; prefA <= n; ++prefA)
        for (int sufA = 0; sufA <= n && prefA + sufA <= n; ++sufA)
            for (int prefB = 0; prefB <= m; ++prefB) {
                int sufB = prefA + prefB - sufA;
                if (sufB < 0 || prefB + sufB > m)
                    continue;
                if (dp[prefA % 2][sufA][prefB] == 0)
                    continue;
                int added = prefA + sufA + prefB + sufB;
                if ((n + m) % 2 == 0 && added == n + m)
                    tot = (tot + dp[prefA % 2][sufA][prefB]) % kMod;
                if ((n + m) % 2 && added == n + m - 1)
                    tot = (tot + dp[prefA % 2][sufA][prefB]) % kMod;

                if (prefA + 1 <= n && n - sufA >= 1 && A[prefA + 1] == A[n - sufA])
                    dp[(prefA + 1) % 2][sufA + 1][prefB] = (dp[(prefA + 1) % 2][sufA + 1][prefB] + dp[prefA % 2][sufA][prefB]) % kMod;
                if (prefA + 1 <= n && m - sufB >= 1 && A[prefA + 1] == B[m - sufB])
                    dp[(prefA + 1) % 2][sufA][prefB] = (dp[(prefA + 1) % 2][sufA][prefB] + dp[prefA % 2][sufA][prefB]) % kMod;
                if (prefB + 1 <= m && n - sufA >= 1 && B[prefB + 1] == A[n - sufA])
                    dp[prefA % 2][sufA + 1][prefB + 1] = (dp[prefA % 2][sufA + 1][prefB + 1] + dp[prefA % 2][sufA][prefB]) % kMod;
                if (prefB + 1 <= m && m - sufB >= 1 && B[prefB + 1] == B[m - sufB])
                    dp[prefA % 2][sufA][prefB + 1] = (dp[prefA % 2][sufA][prefB + 1] + dp[prefA % 2][sufA][prefB]) % kMod;
                dp[prefA % 2][sufA][prefB] = 0;
            }

    printf("%d", tot);
    return 0;
}
