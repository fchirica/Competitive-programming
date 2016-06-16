#include <stdio.h>

int fact[1000100], ifact[1000100];

const int mod = 500000003;

int fastPw(int A, int B) {
    if (B == 0)
        return 1;
    long long res = fastPw(A, B / 2);
    res = res * res % mod;
    if (B % 2)
        res = res * A % mod;
    return (int)res;
}

int comb(int N, int K) {
    long long res = fact[N];
    res = res * ifact[K] % mod;
    res = res * ifact[N - K] % mod;
    return (int)res;
}

int main() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);

    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = 1LL * fact[i - 1] * i % mod;
    ifact[n] = fastPw(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;

    int sol = 0;
    for (int a = 0; a <= n; ++a) {
        int b = a - x;
        int sumab = a + b;
        int sumcd = n - sumab;
        int difcd = y;
        int c = (sumcd + difcd) / 2;
        int d = c - y;
        if (b >= 0 && c >= 0 && d >= 0 && c + d == sumcd && c - d == difcd) {
            long long tmp = comb(a + b + c + d, a);
            tmp = tmp * comb(b + c + d, b) % mod;
            tmp = tmp * comb(c + d, c) % mod;
            sol += (int)tmp;
            sol %= mod;
        }
    }

    printf("%d", sol);
    return 0;
}
