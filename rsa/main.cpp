#include <stdio.h>
#include <assert.h>

int x[115];
int primes[1024];
int A[115][115];

void swap(int &A, int &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

bool isPrime(int x) {
    int d;
    for (d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int free;

void gauss(int N, int M) {
    int i = 1, j = 1;
    free = M;
    while (i <= N && j <= M) {
        int k;
        for (k = i; k <= N; ++k)
            if (A[k][j])
                break;
        if (k == N + 1) {
            ++j;
            continue;
        }
        int l;
        --free;
        for (l = 1; l <= M; ++l)
            swap(A[i][l], A[k][l]);
        for (k = i + 1; k <= N; ++k)
            if (A[k][j])
                for (l = 1; l <= M; ++l)
                    A[k][l] = A[k][l] ^ A[i][l];
        ++i;
        ++j;
    }
}

int H[110];

int main() {
    freopen("rsa.in", "r", stdin);
    freopen("rsa.out", "w", stdout);

    int i, j, primesCnt, N;
    scanf("%d%d", &primesCnt, &N);
    for (i = 1; i <= N; ++i)
        scanf("%d", &x[i]);

    int currentPrime = 3, cnt = 1;
    primes[1] = 2;
    while (cnt < primesCnt) {
        if (isPrime(currentPrime))
            primes[++cnt] = currentPrime;
        currentPrime += 2;
    }

    for (i = 1; i <= cnt; ++i)
        for (j = 1; j <= N; ++j) {
            int tmp = x[j];
            while (tmp % primes[i] == 0) {
                A[i][j] = 1 - A[i][j];
                tmp = tmp / primes[i];
            }
        }

    gauss(cnt, N);

    H[0] = H[1] = 1;
    int tr;
    for (i = 1; i <= free; ++i) {
        tr = 0;
        for (j = 1; j <= H[0]; ++j) {
            H[j] = H[j] * 2 + tr;
            tr = H[j] / 10;
            H[j] = H[j] % 10;
        }
        if (tr)
            H[++H[0]] = 1;
    }

    --H[1];
    for (i = H[0]; i >= 1; --i)
        printf("%d", H[i]);
    return 0;
}
