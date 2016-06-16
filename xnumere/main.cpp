#include <stdio.h>

const int mod = 666013;

long long A(long long N, int K) {
    long long res = 1;
    for (long long i = (N - K + 1); i <= N; ++i)
        res = res * (i % mod) % mod;
    return res;
}

long long F[1000100];

long long fact(int X) {
    if (F[X])
        return F[X];
    return F[X] = fact(X - 1) * 1LL * X % mod;
}

long long pw(long long A, long long B) {
    if (B == 0)
        return 1;
    long long res = pw(A, B / 2);
    res = res * res % mod;
    if (B & 1)
        res = res * A % mod;
    return res;
}

long long inv(long long X) {
    return pw(X, mod - 2);
}

long long comb(long long N, long long K) {
    long long res = fact(N);
    res = res * inv(fact(K)) % mod;
    res = res * inv(fact(N - K)) % mod;
    return res;
}

long long S(long long N, int K) {
    long long res = 0;
    for (int i = 0; i < K; ++i) {
        long long cur = 0;
        cur = pw(K - i, N) % mod;
        cur *= comb(K, i) % mod;
        cur *= pw(-1, i);
        res += cur;
    }
    while (res < 0)
        res += mod;
    res = res % mod;
    res = res * inv(fact(K)) % mod;
    return res;
}

int main() {
    freopen("xnumere.in", "r", stdin);
    freopen("xnumere.out", "w", stdout);

    F[0] = F[1] = 1;

    long long N, K;
    int X;
    scanf("%lld%d%lld", &K, &X, &N);

    long long res = A(K, X);
    res = res * S(N, X) % mod;

    printf("%lld", res);
    return 0;
}

