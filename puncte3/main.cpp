#include <stdio.h>
#include <algorithm>

using namespace std;

long long x[1000001];

struct comp {
    inline bool operator () (long long A, long long B) {
        return A < B;
    }
};

int N, M;

bool solve(long long res) {
    long long seg = 1, last = x[1];
    for (int i = 2; i <= N; ++i)
        if (x[i] - last > res) {
            ++seg;
            last = x[i];
            if (seg > M)
                return 0;
        }
    return 1;
}

int main() {
    freopen("puncte3.in", "r", stdin);
    freopen("puncte3.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        long long A, B, C;
        scanf("%d%d%lld%lld%lld", &N, &M, &A, &B, &C);
        x[1] = 1;
        for (int i = 2; i <= N; ++i)
            x[i] = (x[i - 1] * A + B * i) % C;
        sort(x + 1, x + N + 1, comp());
        long long st = 1, dr = x[N] - x[1], mlc;
        while (st <= dr) {
            int med = (st + dr) / 2;
            if (solve(med)) {
                mlc = med;
                dr = med - 1;
            } else
                st = med + 1;
        }
        printf("%lld\n", mlc);
    }

    return 0;
}
