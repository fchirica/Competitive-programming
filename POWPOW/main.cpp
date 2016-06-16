#include <stdio.h>

const int mod = 1000000007;
int fact[200010];

int pw(int A, int B, int md) {
    if (B == 0)
        return 1;
    int res = pw(A, B / 2, md);
    res = 1LL * res * res % md;
    if (B & 1)
        res = 1LL * res * A % md;
    return res;
}

int legendre(int N) {
    int num = 2, sum = 0;
    while (num <= N) {
        sum += N / num;
        num *= 2;
    }
    return sum;
}

int catalan(int N, int md) {
    if (md == 2)
        return legendre(2 * N) == 2 * legendre(N);
    int res = fact[2 * N];
    res = 1LL * res * pw(fact[N], md - 2, md) % md;
    res = 1LL * res * pw(fact[N], md - 2, md) % md;
    return res;
}

int main() {
    int T;
    scanf("%d", &T);

    fact[0] = 1;
    for (int i = 1; i <= 200000; ++i)
        fact[i] = 1LL * fact[i - 1] * i % 500000003;

    for (int test = 1; test <= T; ++test) {
        int A, B, N;
        scanf("%d%d%d", &A, &B, &N);
        int twoRem = catalan(N, 2);
        int otherRem = catalan(N, 500000003), exp;
        for (int i = 0; i <= 1; ++i)
            if ((otherRem + i * 500000003) % 2 == twoRem)
                exp = otherRem + i * 500000003;
        int upperRes = pw(exp, B, mod - 1);
        int res = pw(A, upperRes, mod);
        printf("%d\n", res);
    }

    return 0;
}
