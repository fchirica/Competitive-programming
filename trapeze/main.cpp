#include <stdio.h>
#include <string.h>

int p[30], d[30], st[30];

bool isPrime(int x) {
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return 0;
    return 1;
}

int n, tmp[100], best[100];

void inm(int term) {
    int tr = 0;
    for (int i = 1; i <= tmp[0]; ++i) {
        tmp[i] = tmp[i] * term + tr;
        tr = tmp[i] / 10;
        tmp[i] = tmp[i] % 10;
    }
    while (tr) {
        tmp[++tmp[0]] = tr % 10;
        tr = tr / 10;
    }
}

bool better() {
    if (tmp[0] < best[0])
        return 1;
    for (int i = tmp[0]; i >= 1; --i) {
        if (best[i] > tmp[i])
            return 1;
        if (best[i] < tmp[i])
            return 0;
    }
    return 0;
}

void back(int lev, int prod) {
    if (prod > n)
        return ;
    if (prod == n) {
        tmp[0] = tmp[1] = 1;
        for (int i = 1; i < lev; ++i)
            for (int j = 1; j < d[st[i]]; ++j)
                inm(p[i]);
        if (better())
            memcpy(best, tmp, sizeof(best));
        return ;
    }

    for (int i = st[lev - 1]; i <= d[0]; ++i) {
        st[lev] = i;
        back(lev + 1, prod * d[i]);
    }
}

int main() {
    freopen("trapeze.in", "r", stdin);
    freopen("trapeze.out", "w", stdout);

    int curPrime = 1;
    for (int i = 1; i <= 30; ++i) {
        do curPrime += 2; while (!isPrime(curPrime));
        p[i] = curPrime;
    }

    scanf("%d", &n);
    for (int i = n; i >= 2; --i)
        if (n % i == 0)
            d[++d[0]] = i;

    best[0] = 1 << 30; st[0] = 1;
    back(1, 1);

    for (int i = best[0]; i >= 1; --i)
        printf("%d", best[i]);
    return 0;
}
