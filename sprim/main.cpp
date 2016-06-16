#include <stdio.h>

int x[100010];
int fact[1000100], f[30];
int sol[100010], prime[100100];
bool ciur[1000100];

void stieve() {
    for (int i = 2; i * i <= 1000000; ++i)
        if (ciur[i] == 0)
            for (int j = i * i; j <= 1000000; j += i)
                ciur[j] = 1;
    for (int i = 2; i <= 1000000; ++i)
        if (ciur[i] == 0)
            prime[++prime[0]] = i;
}

void desc(int xx) {
    f[0] = 0;
    for (int d = 1; prime[d] * prime[d] <= xx; ++d)
        if (xx % prime[d] == 0) {
            while (xx % prime[d] == 0)
                xx /= prime[d];
            f[++f[0]] = prime[d];
        }
    if (xx > 1)
        f[++f[0]] = xx;
}

int main() {
    freopen("sprim.in", "r", stdin);
    freopen("sprim.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &x[i]);
    stieve();
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        desc(x[i]);
        int pos = 0;
        for (int j = 1; j <= f[0]; ++j)
            if (fact[f[j]] > pos)
                pos = fact[f[j]];
        ++pos;
        for (int j = 1; j <= f[0]; ++j)
            fact[f[j]] = i;
        sol[i] = pos;
        if (sol[i - 1] > pos)
            sol[i] = sol[i - 1];
        res += i - sol[i] + 1;
    }

    printf("%d", res - N);
    return 0;
}
