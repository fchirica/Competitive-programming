#include <stdio.h>
#include <string.h>

int N;
int x[555], y[555], ans[555], A[555], B[555], tmp[555], goodB[555][555];

int next[555], col[555];

void getNext(int xx[]) {
    next[1] = xx[N];
    for (int i = 2; i <= N; ++i)
        next[i] = xx[i - 1];
}

void inm(int res[], int xx[], int yy[]) {
    for (int i = 1; i <= N; ++i)
        col[i] = yy[i];
    for (int i = 1; i <= N; ++i) {
        res[i] = 0;
        for (int j = 1; j <= N; ++j)
            res[i] ^= (xx[j] & col[j]);
        getNext(col);
        memcpy(col, next, sizeof(next));
    }
}

void fastPow(int r) {
    if (r == 1) {
        memcpy(B, A, sizeof(A));
        return ;
    }
    fastPow(r / 2);
    memcpy(tmp, B, sizeof(tmp));
    inm(B, tmp, tmp);
    if (r % 2) {
        inm(tmp, B, A);
        memcpy(B, tmp, sizeof(tmp));
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, r, mx = 0;
        scanf("%d%d", &n, &r);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x[i]);
            ans[i] = 0;
            if (x[i] > mx)
                mx = x[i];
        }

        memset(A, 0, sizeof(A));
        A[1] = A[2] = A[n] = 1;
        N = n;
        fastPow(r);

        memcpy(goodB[1], B, sizeof(goodB));
        for (int i = 2; i <= n; ++i) {
            getNext(goodB[i - 1]);
            memcpy(goodB[i], next, sizeof(goodB[i]));
        }

        for (int b = 0; (1 << b) <= mx; ++b) {
            for (int i = 1; i <= n; ++i)
                y[i] = (x[i] & (1 << b)) ? 1 : 0;
            for (int i = 1; i <= n; ++i) {
                int val = 0;
                for (int j = 1; j <= n; ++j)
                    val = (val + goodB[i][j] * y[j]) % 2;
                if (val)
                    ans[i] += (1 << b);
            }
        }
        for (int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}
