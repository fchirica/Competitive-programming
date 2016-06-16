#include <stdio.h>
#include <assert.h>
#include <set>
#include <algorithm>

using namespace std;

multiset <int> S, Sini;
int N, tmp[311 * 311], x[311];

bool can(int x23, int N) {
    S = Sini;

    int x12 = *S.begin();
    S.erase(*S.begin());
    int x13 = *S.begin();
    S.erase(*S.begin());
    if ((x12 + x13 + x23) % 2)
        return 0;
    int x123 = (x12 + x13 + x23) / 2;
    int small = x123 - x23;
    int x2 = x123 - x13;
    x[1] = small; x[2] = x2;

    for (int i = 3; i <= N; ++i) {
        x[i] = *S.begin() - small;
        S.erase(*S.begin());

        for (int j = 2; j < i; ++j) {
            if (S.find(x[i] + x[j]) == S.end())
                return 0;
            S.erase(S.lower_bound(x[i] + x[j]));
        }
    }

    return 1;
}

int main() {
    freopen("sume.in", "r", stdin);
    freopen("sume.out", "w", stdout);

    int nn;
    scanf("%d", &N);
    for (nn = 1; nn * (nn - 1) / 2 <= N; ++nn); --nn;
    if (nn * (nn - 1) / 2 != N) {
        printf("-1");
        return 0;
    }
    N = nn;
    for (int i = 1; i <= N * (N - 1) / 2; ++i) {
        scanf("%d", &tmp[i]);
        Sini.insert(tmp[i]);
    }

    sort(tmp + 1, tmp + N * (N - 1) / 2 + 1);
    for (int i = 3; i <= N; ++i) {
        if ((i == 1 || tmp[i] != tmp[i - 1]) && can(tmp[i], N)) {
            printf("%d\n", N);
            for (int j = 1; j <= N; ++j)
                printf("%d ", x[j]);
            return 0;
        }
    }

    printf("-1");
    return 0;
}
