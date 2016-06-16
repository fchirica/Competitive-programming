#include <bits/stdc++.h>

using namespace std;

const int kMod = 200003;
const int kNMax = 100100;

int dp[kNMax];

int main() {
    freopen("matcnt.in", "r", stdin);
    freopen("matcnt.out", "w", stdout);

    int n;
    scanf("%d", &n);
    dp[3] = 1;
    for (int i = 4; i <= n; ++i)
        dp[i] = ((long long) (i - 1) * (i - 2) / 2 % kMod * dp[i - 3] % kMod + (long long)(i - 1) * dp[i - 1] % kMod) % kMod;

    int res = dp[n];
    for (int i = 2; i <= n; ++i)
        res = (long long) res * i % kMod;

    printf("%d", res);
    return 0;
}
