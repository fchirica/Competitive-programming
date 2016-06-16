#include <stdio.h>

int quit[25], ord[25], x[25];

int nxt(int X, int N) {
    ++X;
    if (X == N + 1)
        X = 1;
    return X;
}

int __gcd(long long A, long long B) {
    long long r;
    while (B) {
        r = A % B;
        A = B;
        B = r;
    }
    return A;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &quit[i]);
        ord[quit[i]] = i;
    }
    for (int i = 1; i < N; ++i) {
        int tmp = 1;
        for (int j = nxt(ord[i - 1], N); j != ord[i]; j = nxt(j, N))
            if (quit[j] >= i)
                ++tmp;
         x[N - i + 1] = tmp % (N - i + 1);
    }

    long long res = x[2], M = 2;
    for (int i = 3; i <= N; ++i) {
        bool good = false;
        for (int j = 0; j < i; ++j)
            if ((res + j * M) % i == x[i]) {
                good = true;
                res = res + j * M;
                break;
            }
        if (!good) {
            printf("NIE");
            return 0;
        }
        M = M * i / __gcd(M, i);
    }

    if (res == 0)
        res = M;
    printf("%lld", res);
    return 0;
}

