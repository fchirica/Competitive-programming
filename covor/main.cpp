#include <stdio.h>

int x[2012][2012], up[2012][2012];
int st[2012], cnt[2012];
char tmp[2012];

int main() {
    freopen("covor.in", "r", stdin);
    freopen("covor.out", "w", stdout);

    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i) {
        gets(tmp + 1);
        for (int j = 1; j <= n; ++j)
            x[i][j] = tmp[j] - '0';
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (x[i][j] == 1)
                up[i][j] = 0;
            else
                up[i][j] = 1 + up[i - 1][j];

    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        st[0] = 0;
        long long sum = 0;
        for (int j = 1; j <= n; ++j) {
            int len = 1;
            while (st[0] > 0 && st[st[0]] >= up[i][j]) {
                len += cnt[st[0]];
                sum -= (long long) cnt[st[0]] * st[st[0]];
                --st[0];
            }
            st[++st[0]] = up[i][j];
            cnt[st[0]] = len;
            sum += (long long) st[st[0]] * cnt[st[0]];
            res += sum;
        }
    }

    printf("%lld", res);
    return 0;
}
