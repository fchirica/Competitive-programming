#include <stdio.h>
#include <iostream>

using namespace std;

const int mod = 10567201;
int dp1[1024][1024], dp2[1024][1024];

int fastPow(int A, int B) {
    if (B == 0)
        return 1;
    int res = fastPow(A, B / 2);
    res = 1LL * res * res % mod;
    if (B & 1)
        res = 1LL * res * A % mod;
    return res;
}

int fact[11000000], IF[11000000];

int C(int N, int K) { //returns binomial coefficient (2 ^ N, K)
    if (N < K)
        return 0;
    int res = 1LL * fact[N] * IF[K] % mod;
    res = 1LL * res * IF[N - K] % mod;
    return res;
}

int main() {
    int n, m, v;

    fact[0] = 1;
    for (int i = 1; i < mod; ++i)
        fact[i] = 1LL * fact[i - 1] * i % mod;
    IF[mod - 1] = fastPow(fact[mod - 1], mod - 2);
    for (int i = mod - 2; i >= 0; --i)
        IF[i] = ((long long)IF[i + 1] * (i + 1)) % mod;

    for (int i = 1; i <= 1000; ++i) {
        dp1[i][1] = 1;
        dp2[i][1] = 1;
    }

    int curPw = 1;
    for (int i = 1; i <= 1000; ++i) {
        dp1[i][2] = 0;
        dp2[i][2] = curPw;
        curPw = curPw * 2 % mod;
    }

    for (int j = 3; j <= 1000; ++j) {
        int invers = fastPow(j, mod - 2);
        int curPw = 1;
        for (int i = 1; i <= 1000; ++i) {
            curPw *= 2;
            curPw = curPw % mod;
            dp1[i][j] = C(curPw, j - 1);
            long long tmp = curPw - j + 2;
            while (tmp < 0)
                tmp += mod;
            tmp *= dp1[i][j - 2];
            tmp %= mod;
            dp1[i][j] -= tmp;
            while (dp1[i][j] < 0)
                dp1[i][j] += mod;
            dp1[i][j] = (long long)dp1[i][j] * invers % mod;

            dp2[i][j] = C(curPw, j - 1);
            tmp = curPw - j + 2;
            while (tmp < 0)
                tmp += mod;
            tmp *= dp2[i][j - 2];
            tmp %= mod;
            dp2[i][j] -= tmp;
            while (dp2[i][j] < 0)
                dp2[i][j] += mod;
            dp2[i][j] = (long long)dp2[i][j] * invers % mod;
        }
    }

    while (1) {
        scanf("%d%d%d", &n, &m, &v);
        if (!n)
            break;
        if (!v)
            printf("%d\n", dp1[n][m]);
        else
            printf("%d\n", dp2[n][m]);
    }

    return 0;
}
