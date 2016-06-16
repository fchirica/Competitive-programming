#include <stdio.h>
#include <algorithm>

using namespace std;

struct sum {
    int idx;
    int val;
} x[100010], A[100010], B[100010];

inline bool comp(sum A, sum B) {
    return A.val < B.val;
}

inline bool comp2(sum A, sum B) {
    return A.idx < B.idx;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i].val);
        x[i].idx = i;
    }

    sort(x + 1, x + n + 1, comp);
    int bucket = n / 3;
    if (n % 3)
        ++bucket;

    for (int i = 1; i <= n; ++i)
        A[i].idx = B[i].idx = x[i].idx;
    for (int i = 1; i <= bucket; ++i) {
        A[i].val = 0;
        B[i].val = x[i].val;
    }
    for (int i = bucket + 1; i <= 2 * bucket; ++i) {
        A[i].val = x[i].val;
        B[i].val = 0;
    }
    int val = bucket - 1;
    for (int i = 2 * bucket + 1; i <= n; ++i) {
        A[i].val = val;
        B[i].val = x[i].val - val;
        --val;
    }
    sort(A + 1, A + n + 1, comp2);
    sort(B + 1, B + n + 1, comp2);

    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", A[i].val);
    printf("\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", B[i].val);
    return 0;
}
