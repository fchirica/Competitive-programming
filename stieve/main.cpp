#include <stdio.h>

int stieve[10000001];

int main() {
    freopen("data.out", "w", stdout);

    int i;
    for (i = 2; i <= 10000000; ++i)
        stieve[i] = 1;
    for (i = 2; i <= 10000000; ++i)
        if (stieve[i])
            for (long long j = 1LL * i * i; j <= 10000000; j += i)
                stieve[j] = 0;
    int cnt = 0;
    for (i = 1; i <= 10000000; ++i)
        if (stieve[i])
            printf("%d ", i);

    printf("%d", cnt);
    return 0;
}
