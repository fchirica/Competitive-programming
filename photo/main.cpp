#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[111][111];

struct point {
    int x, y;
} x[111];

inline bool comp(point A, point B) {
    return A.x < B.x;
}

const int INF = (1 << 29);

inline int chmin(int &A, int B) {
    if (A > B)
        A = B;
}

int A;
int solve(int st, int dr) {
    if (st == dr)
        return 1;
    if (dp[st][dr] != INF)
        return dp[st][dr];
    dp[st][dr] = INF + 1;
    int res = INF;
    for (int i = st; i < dr; ++i)
        chmin(res, solve(st, i) + solve(i + 1, dr));
    int w = x[dr].x - x[st].x;
    bool covered[111];
    for (int i = st; i <= dr; ++i) {
        covered[i] = 0;
        if (w * x[i].y <= A)
            covered[i] = 1;
    }
    int idx = st, cost = 1;
    while (idx <= dr) {
        while (idx <= dr && covered[idx])
            ++idx;
        if (idx > dr)
            break;
        int idx2 = idx;
        while (idx2 <= dr && covered[idx2] == 0)
            ++idx2;
        cost += solve(idx, idx2 - 1);
        idx = idx2;
    }
    chmin(res, cost);
    int i, j;
    for (i = st; i <= dr; ++i)
        if (!covered[i])
            break;
    for (j = dr; j >= st; --j)
        if (!covered[j])
            break;
    if (i <= j)
        chmin(res, 1 + solve(i, j));
    return dp[st][dr] = res;
}

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int n;
    scanf("%d%d", &n, &A);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);
    sort(x + 1, x + n + 1, comp);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = INF;

    printf("%d", solve(1, n));
    return 0;
}
