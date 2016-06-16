#include <stdio.h>
#include <string.h>

char x[55];
int f[10];
long long fact[22];

long long calc() {
    long long sum = 0;
    for (int i = 1; i <= 9; ++i)
        sum += f[i];
    sum = fact[sum];
    for (int i = 1; i <= 9; ++i)
        sum /= fact[f[i]];
    return sum;
}

int main() {
    freopen("numere7.in", "r", stdin);
    freopen("numere7.out", "w", stdout);

    long long N;
    scanf("%lld %s", &N, &x);
    for (int i = 0; i < strlen(x); ++i)
        ++f[x[i] - '0'];
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 20; ++i)
        fact[i] = i * fact[i - 1];

    for (int i = 1; i <= strlen(x); ++i) {
        for (int c = 1; c <= 9; ++c)
            if (f[c]) {
                --f[c];
                long long tmp = calc();
                if (tmp >= N) {
                    printf("%d", c);
                    break;
                }
                else {
                    ++f[c];
                    N = N - tmp;
                }
            }
    }
    return 0;
}
