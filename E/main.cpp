#include <stdio.h>
#include <algorithm>

using namespace std;

const int mod = 1000000009;
int dp[1 << 24], a[25], unlucky[3];
long long sum[1 << 24];

int main() {
    int i, j, N, K;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &K);
    for (i = 1; i <= K; ++i)
        scanf("%d", &unlucky[i]);

    dp[0] = 1;

    for (i = 0; i < (1 << N); ++i) {
        int j = __builtin_ctz(i);
        sum[i] = sum[i ^ (1 << j)] + a[j + 1];
    }

    for (i = 0; i < (1 << N); ++i) {
        long long currentSum = sum[i];
        if (dp[i] == 0)
            continue;
        for (j = 0; j < N; ++j)
            if ((i & (1 << j)) == 0) {
                bool goodAddition = true;
                for (int k = 1; k <= K && goodAddition; ++k)
                    if (currentSum + a[j + 1] == unlucky[k])
                        goodAddition = false;
                if (goodAddition) {
                    dp[i | (1 << j)] += dp[i];
                    if (dp[i | (1 << j)] >= mod)
                        dp[i | (1 << j)] -= mod;
                }
            }
    }

    printf("%d", dp[(1 << N) - 1]);
    return 0;
}
