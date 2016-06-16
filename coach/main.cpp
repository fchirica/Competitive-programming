#include <stdio.h>

int c[115], ord[115], ini[115][115], fw[115][115];

void chmin(int &A, int B) {
    if (A > B)
        A = B;
}

int main() {
    freopen("coach.in", "r", stdin);
    freopen("coach.out", "w", stdout);

    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &c[i]);
        ord[i] = i;
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            ini[i][j] = (i == j) ? 0 : 1 << 28;
    for (int i = 1; i <= M; ++i) {
        int xx, yy, cc;
        scanf("%d%d%d", &xx, &yy, &cc);
        ini[xx][yy] = ini[yy][xx] = cc;
    }

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < N; ++i)
            if (c[ord[i]] > c[ord[i + 1]]) {
                int tmp = ord[i];
                ord[i] = ord[i + 1];
                ord[i + 1] = tmp;
                sorted = false;
            }
    }

    for (int mi = 1; mi <= N; ++mi) {
        for (int i = mi; i <= N; ++i)
            for (int j = mi; j <= N; ++j)
                fw[i][j] = ini[ord[i]][ord[j]];
        for (int ma = mi; ma <= N; ++ma) {
            for (int i = mi; i <= N; ++i)
                for (int j = mi; j <= N; ++j) {
                    chmin(fw[i][j], fw[i][ma] + fw[ma][j]);
                    if (fw[i][j] == K && i <= ma && j <= ma) {
                        printf("%d %d %d %d\n", ord[i], ord[j], c[ord[mi]], c[ord[ma]]);
                        return 0;
                    }
                }
        }
    }

    return 0;
}
