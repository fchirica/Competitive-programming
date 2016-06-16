#include <stdio.h>
#include <vector>
#include <cassert>

using namespace std;

vector <int> fact;
const int mod = 666013;

int pw(int A, int B) {
    if (B == 0)
        return 1;
    int res = pw(A, B / 2);
    res = (long long)res * res % mod;
    if (B % 2)
        res = (long long)res * A % mod;
    return res;
}

int invers(int val) {
    return pw(val, mod - 2);
}

int C(int N, int K) {
    long long res = fact[N];
    res = res * (long long)invers(fact[K]) % mod;
    res = res * (long long)invers(fact[N - K]) % mod;
    return res;
}

int main() {
    freopen("lant2.in", "r", stdin);
    freopen("lant2.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);

    fact.push_back(1);
    for (int i = 1; i <= n - k - 2; ++i)
        fact.push_back(1LL * fact[i - 1] * i % mod);

    int res = C(n - k - 2, 2 * k - 2);
    res += C((n - k - 2) / 2, k - 1);
    res = 1LL * res * invers(2) % mod;

    printf("%d", res);
    return 0;
}
