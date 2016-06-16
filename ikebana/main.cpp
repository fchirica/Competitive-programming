#include <stdio.h>
#include <string.h>

int lim;
int mat[69][69], A[69][69], C[69][69], vect[69], res[69];

const int mod = 666013;

inline int get(int _A, int _B) {
    return 3 * _A + 1 + _B;
}

void inm(int _A[69][69], int _B[69][69]) {
    for (int i = 1; i <= lim; ++i)
        for (int j = 1; j <= lim; ++j) {
            C[i][j] = 0;
            for (int k = 1; k <= lim; ++k)
                C[i][j] = (C[i][j] + (long long) _A[i][k] * _B[k][j]) % mod;
        }
}

void copy(int _A[69][69], int _B[69][69]) {
    for (int i = 1; i <= lim; ++i)
        for (int j = 1; j <= lim; ++j)
            _A[i][j] = _B[i][j];
}

void fastPow(int times) {
    if (times == 1) {
        copy(A, mat);
        return ;
    }

    fastPow(times / 2);
    inm(A, A);
    copy(A, C);
    if (times % 2)
        inm(A, mat);
    copy(A, C);
}

int main() {
    freopen("ikebana.in", "r", stdin);
    freopen("ikebana.out", "w", stdout);

    int n, p, t;
    scanf("%d%d%d", &n, &p, &t);
    lim = 3 * (p + 1);

    mat[get(0, 2)][get(p, 0)] = 1;
    mat[get(0, 2)][get(p, 2)] = 1;
    for (int i = 1; i <= p; ++i) {
        mat[get(i, 0)][get(i - 1, 0)] = 2;
        mat[get(i, 0)][get(i - 1, 2)] = 2;
        mat[get(i, 0)][get(i - 1, 1)] = 1;
        mat[get(i, 1)][get(i - 1, 0)] = 1;
        mat[get(i, 2)][get(i - 1, 0)] = t - 4;
        mat[get(i, 2)][get(i - 1, 2)] = t - 4;
    }
    mat[get(p, 0)][get(p, 0)] = 2;
    mat[get(p, 0)][get(p, 2)] = 2;
    mat[get(p, 0)][get(p, 1)] = 1;
    mat[get(p, 1)][get(p, 0)] = 1;
    mat[get(p, 2)][get(p, 0)] = t - 4;
    mat[get(p, 2)][get(p, 2)] = t - 4;

    vect[get(0, 2)] = 1;
    vect[get(p, 0)] = 2;
    vect[get(p, 2)] = t - 4;

    fastPow(n - 1);
    for (int i = 1; i <= lim; ++i)
        for (int j = 1; j <= lim; ++j)
            res[i] = (res[i] + (long long) A[i][j] * vect[j]) % mod;

    int sol = 0;
    for (int i = 0; i <= p; ++i)
        sol = (sol + res[get(i, 0)] + res[get(i, 2)]) % mod;
    printf("%d", sol);
    return 0;
}
