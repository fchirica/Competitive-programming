#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[110][16100];

struct worker {
    int L, P, S;
} x[110];

int Q[20000];

inline bool comp(worker A, worker B) {
    return A.S < B.S;
}

int main() {
    freopen("gard.in", "r", stdin);
    freopen("gard.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i)
        scanf("%d%d%d", &x[i].L, &x[i].P, &x[i].S);
    sort(x + 1, x + M + 1, comp);
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j)
            dp[i][j] = dp[i - 1][j];
        int p = 1, u = 0;
        for (int j = x[i].S - x[i].L; j < x[i].S + x[i].L && j <= N; ++j) {
            if (j < 0)
                continue;
            while (p <= u && dp[i - 1][j] >= dp[i - 1][Q[u]] + (j - Q[u]) * x[i].P)
                --u;
            if (j <= x[i].S - 1)
                Q[++u] = j;
            if (j >= x[i].S && dp[i - 1][Q[p]] + x[i].P * (j - Q[p]) >= dp[i][j])
                dp[i][j] = dp[i - 1][Q[p]] + x[i].P * (j - Q[p]);
            if (Q[p] + x[i].L == j)
                ++p;
        }
        int mx = dp[i][1];
        for (int j = 2; j <= N; ++j)
            if (dp[i][j] > mx)
                mx = dp[i][j];
            else
                dp[i][j] = mx;
    }

    printf("%d", dp[M][N]);
    return 0;
}
