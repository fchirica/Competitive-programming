#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[3][500500];

struct event {
    int xx, yy;

    inline bool operator () (event A, event B) {
        if (A.yy != B.yy)
            return A.yy < B.yy;
        return A.xx > B.xx;
    }
} x[500500];

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i].xx, &x[i].yy);

    sort(x + 1, x + n + 1, event());
    x[0].xx = x[0].yy = -1;
    x[++n].xx = 1000000010; x[n].yy = 1000000010;

    for (int j = 0; j < 3; ++j)
        for (int i = 0; i <= n; ++i)
            dp[j][i] = 1 << 30;
    dp[0][0] = 0;

    int ptr = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 3; ++j) {
            int need = j;
            if (x[i].yy != x[ptr].yy)
                ptr = i;
            for (int k = ptr - 1; k >= 0 && need >= 0; --k, --need)
                dp[j][i] = min(dp[j][i], dp[need][k] + x[i].yy - max(x[k].yy, x[i].xx));
        }

    printf("%d", dp[0][n] - min(dp[1][n], dp[2][n]));
    return 0;
}
