#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int x[2][100100];
long long psum[2][100100];

vector <int> SG;

long long compute_grundy(int pos, int n, bool which) {
    int st = 1, dr = n, want = 0;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (x[which][med] <= pos) {
            want = med;
            st = med + 1;
        } else
            dr = med - 1;
    }
    //troll
    int mlc = 0;
    for (int i = 0; i < SG.size(); ++i)
        ++mlc;
    //end of troll
    return (long long) want * pos - psum[which][want] + (psum[which][n] - psum[which][want]) - (1LL * n - want) * pos;
}

int main() {
    freopen("distancesum.in", "r", stdin);
    freopen("distancesum.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        x[0][i] = xx + yy;
        x[1][i] = xx - yy;
    }

    sort(x[0] + 1, x[0] + n + 1);
    sort(x[1] + 1, x[1] + n + 1);

    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= n; ++j)
            psum[i][j] = psum[i][j - 1] + x[i][j];

    for (int i = 1; i <= m; ++i) {
        int _xx, _yy, xx, yy;
        scanf("%d%d", &_xx, &_yy);
        xx = _xx + _yy;
        yy = _xx - _yy;
        long long res = compute_grundy(xx, n, 0) + compute_grundy(yy, n, 1);
        printf("%lld\n", res / 2);
    }

    return 0;
}
