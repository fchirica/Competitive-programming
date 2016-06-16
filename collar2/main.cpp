#include <stdio.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int rmq1[17][132000], rmq2[17][132000];
int x[132000], lg[132000];

void build(int N) {
    for (int i = 1; i <= N; ++i)
        rmq1[0][i] = rmq2[0][i] = x[i];
    for (int i = 1; (1 << i) < N; ++i)
        for (int j = 1; j + (1 << i) - 1 <= N; ++j) {
            rmq1[i][j] = max(rmq1[i - 1][j], rmq1[i - 1][j + (1 << (i - 1))]);
            rmq2[i][j] = min(rmq2[i - 1][j], rmq2[i - 1][j + (1 << (i - 1))]);
        }

    lg[1] = 0;
    for (int i = 2; i < 132000; ++i)
        lg[i] = lg[i / 2] + 1;
}

int get(int xx, int yy, int type) {
    int len = lg[yy - xx + 1];
    if (type == 0)
        return max(rmq1[len][xx], rmq1[len][yy - (1 << len) + 1]);
    return min(rmq2[len][xx], rmq2[len][yy - (1 << len) + 1]);
}

void solve(int N, int d, long long &res) {
    int times = N / d;
    for (int i = 1; i <= d; ++i) {
        long long sum = 0;
        int cur = i;
        for (int j = 1; j <= times; ++j) {
            sum += get(cur, cur + d - 1, 0) - get(cur, cur + d - 1, 1);
            cur += d;
        }
        if (sum > res)
            res = sum;
    }
}

int main() {
    freopen("collar.in", "r", stdin);
    freopen("collar.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    for (int i = n + 1; i <= n + n; ++i)
        x[i] = x[i - n];
    int N = 2 * n;

    build(N);

    long long res = (-1LL) << 62;
    for (int d = 1; d * d <= n; ++d)
        if (n % d == 0) {
            solve(n, d, res);
            solve(n, n / d, res);
        }

    printf("%lld", res);
    return 0;
}
