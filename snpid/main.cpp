#include <bits/stdc++.h>

using namespace std;

const int kNMax = 100100;

int n;
int x[kNMax];
int bigger[kNMax];
long long res[kNMax], F[kNMax];

int lsb(int x) {
    return x & -x;
}

void update(int pos, int am) {
    for (; pos <= n; pos += lsb(pos))
        F[pos] += am;
}

long long query(int pos) {
    long long res = 0;
    for (; pos > 0; pos -= lsb(pos))
        res += F[pos];
    return res;
}

int main() {
    freopen("snpid.in", "r", stdin);
    freopen("snpid.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    for (int i = n; i >= 1; --i) {
        bigger[i] = query(n) - query(x[i]);
        update(x[i], 1);
    }

    memset(F, 0, sizeof(F));
    for (int i = n; i >= 1; --i) {
        res[i] = query(n) - query(x[i]);
        update(x[i], bigger[i]);
    }

    for (int i = 1; i <= n; ++i)
        printf("%lld\n", res[i]);

    return 0;
}
