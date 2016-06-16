#include <stdio.h>
#include <algorithm>

using namespace std;

int x[1000100];

inline bool comp(int A, int B) {
    return A < B;
}

const int mod = 1000000009;

int main() {
    int N, D;

    scanf("%d%d", &N, &D);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &x[i]);

    sort(x + 1, x + N + 1);
    int res = 1;
    for (int i = N; i >= 1; --i) {
        int left = i + 1, right = N, ret = 0;
        while (left <= right) {
            int med = (left + right) / 2;
            if (x[med] <= x[i] + D) {
                ret = med;
                left = med + 1;
            } else
                right = med - 1;
        }
        if (ret)
            ret -= i;
        res = (long long)res * (ret + 1) % mod;
    }

    printf("%d", res);
    return 0;
}
