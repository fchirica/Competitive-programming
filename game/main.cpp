#include <stdio.h>
#include <algorithm>
#define point pair <int, int>
#define x first
#define y second

using namespace std;

point x[222], slope[222 * 222];

inline int gcd(int A, int B) {
    while (B) {
        int r = A % B;
        A = B;
        B = r;
    }
    return A;
}

point getSlope(point A, point B) {
    int ret1 = B.y - A.y;
    int ret2 = B.x - A.x;
    int sgn = 1;
    if (ret1 < 0)
        ret1 = -ret1, sgn = -sgn;
    if (ret2 < 0)
        ret2 = -ret2, sgn = -sgn;
    int gc = gcd(ret1, ret2);
    return make_pair(sgn * ret1 / gc, ret2 / gc);
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    while (true) {
        int N;
        scanf("%d", &N);
        if (N == 0)
            break;
        int i, j;
        for (i = 1; i <= N; ++i)
            scanf("%d%d", &x[i].x, &x[i].y);

        bool vertical = false;
        int cnt = 0;
        for (i = 1; i <= N; ++i)
            for (j = i + 1; j <= N; ++j)
                if (x[i].x == x[j].x)
                    vertical = true;
                else
                    slope[++cnt] = getSlope(x[i], x[j]);
        sort(slope + 1, slope + cnt + 1);
        int sol = 0;
        for (i = 1; i <= cnt; ++i)
            if (slope[i] != slope[i - 1])
                ++sol;
        printf("%d\n", sol + vertical);
    }

    return 0;
}

