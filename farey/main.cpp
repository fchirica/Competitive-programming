#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

inline int gcd(int A, int B) {
    if (!B)
        return A;
    return gcd(B, A % B);
}

struct fraction {
    int x, y;
} f[44444];

inline bool comp(fraction A, fraction B) {
    return A.x * B.y < A.y * B.x;
}

int c[44444];

int doit(int A, int B) {
    int res = 0;
    for (int i = 2; i <= B; ++i)
        c[i] = 0;
    for (int i = 2; i <= B; ++i) {
        c[i] += floor((double)A * i / B);
        for (int j = 2 * i; j <= B; j += i)
            c[j] -= c[i];
        res += c[i];
    }
    return res;
}

int main() {
    freopen("farey.in", "r", stdin);
    freopen("farey.out", "w", stdout);

    int N, K;
    scanf("%d%d", &N, &K);

    int st = 1, dr = N - 1, ret;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (doit(med, N) <= K) {
            ret = med;
            st = med + 1;
        } else
            dr = med - 1;
    }

    int cnt = 0;
    for (int den = 2; den <= N; ++den) {
        int num = ceil((double)ret * den / N);
        if (gcd(num, den) == 1 && num * N < den * (ret + 1)) {
            f[++cnt].x = num;
            f[cnt].y = den;
        }
    }

    sort(f + 1, f + cnt + 1, comp);
    printf("%d %d", f[K - doit(ret, N) + 1].x, f[K - doit(ret, N) + 1].y);
    return 0;
}
