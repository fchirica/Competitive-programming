#include <stdio.h>

using namespace std;

int getPw(int A, int B, int md) {
    if (B == 0)
        return 1;
    int res = getPw(A, B / 2, md);
    res = (long long)res * res % md;
    if (B % 2)
        res = (long long)res * A % md;
    return res;
}

int legendre(int N, long long P) {
    int res = 0, ini = P;
    while (N >= P) {
        res += N / P;
        P = P * ini;
    }
    return res;
}

void gcd(int a, int &x, int b, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return ;
    }
    int x0, y0;
    gcd(b, x0, a % b, y0);
    x = y0; y = x0 - (a / b) * y0;
}

int inv(int N, int md) {
    int xx, yy;
    gcd(N, xx, md, yy);
    while (xx < 0)
        xx += md;
    return xx;
}

int fact[200200];

int get(int N, int md) {
    int res = (long long)fact[2 * N] * inv(fact[N], md) % md;
    res = (long long)res * inv(fact[N], md) % md;
    int P[4];
    P[1] = 2; P[2] = 41; P[3] = 148721;
    for (int i = 1; i <= 3; ++i) {
        int tmp = legendre(2 * N, P[i]) - 2 * legendre(N, P[i]);
        res = (long long)res * getPw(P[i], tmp, md) % md;
    }
    return res;
}

int drop(int X) {
    while (X % 2 == 0)
        X = X / 2;
    while (X % 41 == 0)
        X = X / 41;
    while (X % 148721 == 0)
        X = X / 148721;
    return X;
}

int main() {
    int T;

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 200000; ++i)
        fact[i] = 1LL * fact[i - 1] * drop(i) % 500000002;

    scanf("%d", &T);
    while (T--) {
        int N, A, B;
        scanf("%d%d%d", &A, &B, &N);
        if (B == 0) {
            printf("1\n");
            continue;
        }
        int twoPw = B % 2;
        int otherPw = getPw(B, get(N, 500000002), 500000003);
        int res = 0;
        for (int i = 0; i < 2; ++i)
            if ((otherPw + 500000003 * i) % 2 == twoPw) {
                res = otherPw + 500000003 * i;
                break;
            }
        printf("%d\n", (int)getPw(A, res, 1000000007));
    }
    return 0;
}
