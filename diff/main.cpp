#include <stdio.h>

int x[100100], A[200200], B[200200];

#define A (A + 100000)
#define B (B + 100000)

int main() {
    freopen("diff.in", "r", stdin);
    freopen("diff.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &x[i]);
        if (x[i] == 0)
            x[i] = -1;
    }

    int smin = 0, smax = 0, idxmin = 0, idxmax = 0, sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += x[i];
        if (A[sum - smax] == 0) {
            A[sum - smax] = idxmax + 1;
            B[sum - smax] = i;
        }
        if (A[sum - smin] == 0) {
            A[sum - smin] = idxmin + 1;
            B[sum - smin] = i;
        }
        if (sum > smax) {
            smax = sum;
            idxmax = i;
        }
        if (sum < smin) {
            smin = sum;
            idxmin = i;
        }
    }

    for (int i = 1; i <= M; ++i) {
        int tmp, xx = -1, yy = -1;
        scanf("%d", &tmp);
        if (-N <= tmp && tmp <= N) {
            if (A[tmp])
                xx = A[tmp], yy = B[tmp];
        }
        printf("%d", xx);
        if (xx != -1)
            printf(" %d", yy);
        printf("\n");
    }

    return 0;
}
