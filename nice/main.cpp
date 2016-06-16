#include <stdio.h>
#include <string.h>

char _x[111];
int mod, N, M, x[111], y[111], mat[50][50];

int getBit(int mask, int pos) {
    if (mask & (1 << pos))
        return 1;
    return 0;
}

bool canFollow(int mask1, int mask2) {
    int i;
    for (i = 0; i < M - 1; ++i) {
        int sum = getBit(mask1, i) + getBit(mask1, i + 1) + getBit(mask2, i) + getBit(mask2, i + 1);
        if (sum == 0 || sum == 4)
            return 0;
    }
    return 1;
}

void rev() {
    int st = 1, dr = x[0];
    while (st <= dr) {
        int tmp = x[st];
        x[st] = x[dr];
        x[dr] = tmp;
        ++st; --dr;
    }
}

void dec() {
    rev();
    for (int i = 1; i <= x[0]; ++i) {
        --x[i];
        if (x[i] >= 0)
            break;
        else
            x[i] = 9;
    }
    while (x[0] > 0 && x[x[0]] == 0)
        --x[0];
    rev();
}

void move() {
    for (int i = 0; i <= y[0]; ++i)
        x[i] = y[i];
}

void div() {
    y[0] = 0;
    int i = 1, num = x[1];
    if (num == 1)
        num = num * 10 + x[2], ++i;
    for (; i <= x[0]; ++i) {
        y[++y[0]] = num / 2;
        num = (num % 2) * 10 + x[i + 1];
    }
    move();
}

int ini[50][50], tmp[50][50];

void inm(int A[50][50], int B[50][50], int C[50][50]) { //C = A * B
    int i, j, k;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= mod;
            }
        }
}

void matrixMultiplication() {
    if (x[0] == x[1] && x[0] == 1)
        return ;
    int parity = x[x[0]] % 2;
    div();
    matrixMultiplication();
    inm(mat, mat, tmp);
    memcpy(mat, tmp, sizeof(mat));
    if (parity) {
        inm(mat, ini, tmp);
        memcpy(mat, tmp, sizeof(mat));
    }
}

int main() {
    freopen("nice.in", "r", stdin);
    freopen("nice.out", "w", stdout);

    scanf("%s %d %d", &_x, &M, &mod);
    x[0] = strlen(_x);
    int i, j;
    for (i = 1; i <= x[0]; ++i)
        x[i] = _x[i - 1] - '0';

    if (x[0] == x[1] && x[1] == 1) {
        printf("%d", ((1 << M) - 1) % mod);
        return 0;
    }

    N = (1 << M);
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            if (canFollow(i, j))
                ini[i][j] = mat[i][j] = 1;

    dec();
    matrixMultiplication();

    int tot = 0;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j) {
            tot += mat[i][j];
            if (tot >= mod)
                tot = tot - mod;
        }
    printf("%d", tot);
    return 0;
}

