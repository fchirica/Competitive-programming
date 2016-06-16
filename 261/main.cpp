#include <stdio.h>
#include <math.h>
#include <map>
#include <set>

using namespace std;

long long D[100000];

long long pw(long long A, long long B, long long md) {
    if (B == 0)
        return 1;
    long long res = pw(A, B / 2, md);
    res = (long long)res * res % md;
    if (B & 1)
        res = (long long)res * A % md;
    return res;
}

bool isRoot(long long g, long long P) {
    for (long long d = 1; d <= D[0]; ++d)
        if (pw(g, D[d], P) == 1)
            return 0;
    return 1;
}

long long discreteLog(long long A, long long B, long long P) {
    long long m = sqrt(P);
    map <long long, long long> M;
    long long cur = 1;
    for (long long i = 0; i < m; ++i) {
        M[cur] = i;
        cur = (long long)cur * A % P;
    }
    long long cur2 = pw(A, m, P);
    cur2 = pw(cur2, P - 2, P);
    cur = 1;
    for (long long i = 0; i <= m; ++i) {
        long long cur3 = (long long)cur * B % P;
        if (M[cur3] || cur3 == 1)
            return i * m + M[cur3];
        cur = (long long)cur * cur2 % P;
    }
    return -1;
}

long long gcd(long long A, long long B, long long &X, long long &Y) {
    if (B == 0) {
        X = 1; Y = 0;
        return A;
    }
    long long xx, yy;
    long long d = gcd(B, A % B, xx, yy);
    X = yy; Y = xx - (A / B) * yy;
    return d;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int _P, _K, _A;
    scanf("%d%d%d", &_P, &_K, &_A);
    long long P = _P, K = _K, A = _A;

    if (P == 2) {
        printf("1\n%d", _A);
        return 0;
    }
    if (A == 0) {
        printf("1\n0");
        return 0;
    }

    for (long long d = 1; (long long)d * d <= P - 1; ++d)
        if ((P - 1) % d == 0) {
            D[++D[0]] = d;
            long long d2 = (P - 1) / d;
            if (d2 != d && d2 != P - 1)
                D[++D[0]] = d2;
        }

    long long g;
    for (g = 2; g < P; ++g)
        if (isRoot(g, P))
            break;

    long long j = discreteLog(g, A, P);
    if (j == -1) {
        printf("0");
        return 0;
    }

    long long x, y, d = gcd(K, P - 1, x, y);
    if (j % d) {
        printf("0");
        return 0;
    }
    x = x * (j / d);
    long long tmp = (P - 1) / d;
    while (x < 0)
        x += tmp;
    set <long long> sol;

    long long cur = pw(g, x, P);
    while (sol.find(cur) == sol.end()) {
        sol.insert(cur);
        x += tmp;
        cur = pw(g, x, P);
    }

    printf("%d\n", sol.size());
    set <long long> :: iterator it;
    for (it = sol.begin(); it != sol.end(); ++it)
        printf("%d\n", (int)*it);
    return 0;
}
