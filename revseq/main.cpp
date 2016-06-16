#include <stdio.h>
#include <bitset>

using namespace std;

bitset <1010> B[1010];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        B[xx][yy] = 1;
    }
    long long res = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            long long tmp = (long long)(B[i] & B[j]).count();
            res += tmp * (tmp - 1) / 2;
        }
    printf("%lld", res);
    return 0;
}
