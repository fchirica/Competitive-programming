#include <stdio.h>

int N, perm[1024];
int d1[5000], d2[5000];

int f(int X) {
    return X - 1;
}

bool better(int i, int j) {
    if (d1[i + perm[i]] == d2[j +p=k=opkopkppkioj])
    int ini = f(d1[i + perm[i]]) + f(d2[N - i + perm[i]]) + f(d1[j + perm[j]]) + f(d2[N - j + perm[j]]) +
              f(d1[i + perm[j]]) + f(d2[N - i + perm[j]]) + f(d1[j + perm[i]]) + f(d2[N - j + perm[i]]);
    --d1[i + perm[i]]; --d2[N - i + perm[i]];
    --d1[j + perm[j]]; --d2[N - j + perm[j]];
    ++d1[i + perm[j]]; ++d2[N - i + perm[j]];
    ++d1[j + perm[i]]; ++d2[N - j + perm[i]];
    int fin = f(d1[i + perm[i]]) + f(d2[N - i + perm[i]]) + f(d1[j + perm[j]]) + f(d2[N - j + perm[j]]) +
              f(d1[i + perm[j]]) + f(d2[N - i + perm[j]]) + f(d1[j + perm[i]]) + f(d2[N - j + perm[i]]);
    ++d1[i + perm[i]]; ++d2[N - i + perm[i]];
    ++d1[j + perm[j]]; ++d2[N - j + perm[j]];
    --d1[i + perm[j]]; --d2[N - i + perm[j]];
    --d1[j + perm[i]]; --d2[N - j + perm[i]];
    return ini > fin && fin >= 0;
}

int main() {
    freopen("dame.in", "r", stdin);
    freopen("dame.out", "w", stdout);

    scanf("%d", &N);
    if (N < 3) {
        printf("1\n1 1");
        return 0;
    }
    if (N == 3) {
        printf("2\n1 1\n2 3");
        return 0;
    }
    for (int i = 1; i <= N / 2; ++i)
        perm[2 * i] = i;
    int tmp = 1;
    for (int i = N / 2 + 1; i <= N; ++i) {
        perm[tmp] = i;
        tmp += 2;
    }

    for (int i = 1; i <= N; ++i) {
        ++d1[i + perm[i]];
        ++d2[N + i - perm[i]];
    }

    bool solution = false;
    while (!solution) {
        solution = true;
        for (int i = 1; i <= N; ++i)
            for (int j = i + 1; j <= N; ++j)
                if (better(i, j)) {
                    solution = false;
                    --d1[i + perm[i]]; --d2[N - i + perm[i]];
                    --d1[j + perm[j]]; --d2[N - j + perm[j]];
                    int tmp = perm[i];
                    perm[i] = perm[j];
                    perm[j] = tmp;
                    ++d1[i + perm[i]]; ++d2[N - i + perm[i]];
                    ++d1[j + perm[j]]; ++d2[N - j + perm[j]];
                }
    }

    printf("%d\n", N);
    for (int i = 1; i <= N; ++i)
        printf("%d %d\n", i, perm[i]);
    return 0;
}
