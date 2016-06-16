#include <stdio.h>
#include <tr1/unordered_set>

using std::tr1::unordered_set;

unordered_set <long long> H;

int main() {
    freopen("dtcsu.in", "r", stdin);
    freopen("dtcsu.out", "w", stdout);

    for (int i = 1; i <= 276997; ++i) {
        long long x;
        scanf("%lld", &x);
        x = x / (x & -x);
        H.insert(x);
    }

    int Q, res = 0;
    scanf("%d", &Q);
    for (int i = 1; i <= Q; ++i) {
        long long x;
        scanf("%lld", &x);
        if (x)
            x = x / (x & -x);
        res += H.count(x);
    }

    printf("%d", res);
    return 0;
}
