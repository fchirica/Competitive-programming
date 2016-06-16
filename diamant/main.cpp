//Toate diamantele n-au valoarea mea
//Si nici aurul din lume si nici platina $$$

#include <stdio.h>
#include <string.h>

int prev[100000], cur[100000];
#define prev (prev + 50000)
#define cur (cur + 50000)

const int mod = 10000;

void baga(int &X, int Y) {
    X += Y;
    if (X >= mod)
        X -= mod;
}

int main() {
    freopen("diamant.in", "r", stdin);
    freopen("diamant.out", "w", stdout);

    int N, M, X, sum = 0;
    scanf("%d%d%d", &N, &M, &X);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            sum += i * j;
    if (-sum <= X && X <= sum) {
        sum = 0;
        cur[0] = 1;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j) {
                for (int k = -50000; k <= 50000; ++k) {
                    prev[k] = cur[k];
                    cur[k] = 0;
                }
                for (int k = -sum; k <= sum; ++k) {
                    baga(cur[k + i * j], prev[k]);
                    baga(cur[k - i * j], prev[k]);
                    baga(cur[k], prev[k]);
                }
                sum += i * j;
            }
        printf("%d", cur[X]);
    } else
        printf("0");
    return 0;
}
