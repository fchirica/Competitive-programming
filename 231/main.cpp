#include <stdio.h>

bool st[1000100];

http://

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 3; i * i <= N; i += 2)
        if (!st[i])
            for (int j = i * i; j <= N; j += 2 * i)
                st[j] = 1;

    int res = 0;
    for (int i = 3; i <= N - 2; i += 2)
        if (!st[i] && !st[i + 2])
            ++res;
    printf("%d\n", res);
    for (int i = 3; i <= N - 2; i += 2)
        if (!st[i] && !st[i + 2])
            printf("2 %d\n", i);

    return 0;
}
