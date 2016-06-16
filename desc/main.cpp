#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

long long D[3000];
int dp[3000][3000];

map <long long, int> M;

void recon(int N, int left, int d) {
    if (N == 1)
        return ;
    for (; dp[N][d] - dp[N][d + 1] < left; ++d)
        left = left - (dp[N][d] - dp[N][d + 1]);
    printf("%d ", D[d]);
    recon(M[D[N] / D[d]], left, d);
}

int main() {
    freopen("desc.in", "r", stdin);
    freopen("desc.out", "w", stdout);

    long long n, k;
    scanf("%lld%d", &n, &k);

    int N = 0;
    for (int i = 1; 1LL * i * i <= n; ++i)
        if (n % i == 0) {
            D[++N] = i;
            if (1LL * i * i != n)
                D[++N] = n / i;
        }

    sort(D + 1, D + N + 1);
    for (int i = 1; i <= N; ++i)
        M[D[i]] = i;

    for (int j = N; j >= 1; --j) {
        dp[j][j] = 1;
        for (int i = j + 1; i <= N; ++i) {
            dp[i][j] = dp[i][j + 1];
            if (D[i] % D[j] == 0 && D[i] / D[j] >= D[j])
                dp[i][j] += dp[M[D[i] / D[j]]][j];
        }
    }

    printf("%d\n", dp[N][2]);
    recon(N, k, 2);
    return 0;
}
