#include <stdio.h>
#include <string.h>

struct eq {
    short A, B, C;
} x[1024];

short xx[1024], yy[1024], reg[1024], pos[1024], neg[1024], add[1024];

int sign(int i, int j) {
    return x[i].A * xx[j] + x[i].B * yy[j] + x[i].C;
}

int main() {
    freopen("regiuni.in", "r", stdin);
    freopen("regiuni.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d%d", &x[i].A, &x[i].B, &x[i].C);
    for (int i = 1; i <= M; ++i)
        scanf("%d%d", &xx[i], &yy[i]);
    int cnt = 1;
    for (int i = 1; i <= M; ++i)
        reg[i] = 1;
    for (int i = 1; i <= N; ++i) {
        memset(pos, 0, sizeof(pos));
        memset(neg, 0, sizeof(neg));
        memset(add, 0, sizeof(add));
        for (int j = 1; j <= M; ++j)
            if (sign(i, j) > 0)
                ++pos[reg[j]];
            else
                ++neg[reg[j]];
        for (int j = 1; j <= M; ++j)
            if (pos[reg[j]] && neg[reg[j]])
                if (sign(i, j) < 0) {
                    if (add[reg[j]] == 0)
                        add[reg[j]] = ++cnt;
                    reg[j] = add[reg[j]];
                }
    }

    printf("%d", cnt);
    return 0;
}
