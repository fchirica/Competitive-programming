#include <stdio.h>
#include <algorithm>

using namespace std;

struct arr {
    int val, idx;
} x[33333];

inline bool comp1(arr A, arr B) {
    return A.val > B.val;
}

inline bool comp2(arr A, arr B) {
    return A.val < B.val;
}

inline bool comp3(arr A, arr B) {
    return A.idx < B.idx;
}

int split(int val, int len) {
    if (val % len == 0)
        return val / len;
    return val / len + 1;
}

int main() {
    freopen("abc.in", "r", stdin);
    freopen("abc.out", "w", stdout);

    int n, lim, sum, mySum = 0;
    scanf("%d%d%d", &n, &lim, &sum);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i].val);
        x[i].idx = i;
        mySum += x[i].val;
    }

    if (mySum == sum) {
        for (int i = 1; i <= n; ++i)
            printf("%d ", x[i].val);
        return 0;
    }

    if (mySum < sum) {
        sort(x + 1, x + n + 1, comp1);
        int extra = sum - mySum;
        x[0].val = lim + 1;
        for (int i = 1; i <= n; ++i) {
            int supply = split(extra, n - i + 1);
            if (supply > x[i - 1].val - x[i].val - 1)
                supply = x[i - 1].val - x[i].val - 1;
            extra -= supply;
            x[i].val += supply;
        }
    } else {
        sort(x + 1, x + n + 1, comp2);
        int extra = mySum - sum;
        for (int i = 1; i <= n; ++i) {
            int supply = split(extra, n - i + 1);
            if (supply > x[i].val - x[i - 1].val - 1)
                supply = x[i].val - x[i - 1].val - 1;
            extra -= supply;
            x[i].val -= supply;
        }
    }

    sort(x + 1, x + n + 1, comp3);
    for (int i = 1; i <= n; ++i)
        printf("%d ", x[i].val);
    return 0;
}
