#include <bits/stdc++.h>

using namespace std;

int cost[1300];
int got[1300];
int bought[1300];
int largest[1300];
int prime[20];

int m;
int lim;

inline bool isPrime(int foo) {
    if (foo < 2)
        return 0;
    for (int d = 2; d * d <= foo; ++d)
        if (foo % d == 0)
            return 0;
    return 1;
}

int res = (1LL << 31) - 1;

void doit(int c, int last) {
    bool ok = 1;
    int supply = 0;
    for (int i = 1; i <= m; ++i)
        if (got[i] && !bought[i]) {
            if (largest[i] == 0)
                ok = 0;
            else {
                if (!bought[largest[i]]) {
                    bought[largest[i]] = -1;
                    supply += cost[largest[i]];
                }
            }
        }
    if (ok && supply + c < res)
        res = supply + c;
    for (int i = 1; i <= m; ++i)
        if (bought[i] == -1)
            bought[i] = 0;
    for (int i = last + 1; i <= prime[0]; ++i) {
        for (int j = prime[i]; j <= m; j += prime[i])
            if (!bought[j])
                bought[j] = i;
        doit(c + cost[prime[i]], i);
        for (int j = prime[i]; j <= m; j += prime[i])
            if (bought[j] == i)
                bought[j] = 0;
    }
}

int main() {
    freopen("numerologie.in", "r", stdin);
    freopen("numerologie.out", "w", stdout);

    int n;
    scanf("%d%d", &n, &m);
    lim = sqrt(m);
    for (int i = 1; i <= n; ++i) {
        int foo;
        scanf("%d", &foo);
        got[foo] = 1;
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d", &cost[i]);
    for (int i = 2; i <= lim; ++i)
        if (isPrime(i))
            prime[++prime[0]] = i;
    for (int d = lim + 1; d <= m; ++d)
        if (isPrime(d))
            for (int i = d; i <= m; i += d)
                largest[i] = d;
    doit(0, 0);
    printf("%d", res);
    return 0;
}
