#include <stdio.h>
#define ll long long

ll dp[1000100];

inline ll max(ll A, ll B) {
    return A > B ? A : B;
}

int main() {
    int n;
    ll vmin = -(1LL << 60), vmax = -(1LL << 60);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        dp[i] = max(x + vmin, -x + vmax);

        if (dp[i] < dp[i - 1])
            dp[i] = dp[i - 1];
        vmin = max(vmin, -x + dp[i - 1]);
        vmax = max(vmax, x + dp[i - 1]);
    }

    printf("%I64d", dp[n]);
    return 0;
}
