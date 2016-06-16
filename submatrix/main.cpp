#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>

using namespace std;

int x[310][310];

void norm(int N, int M) {
    map <int, int> MP;
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            if (MP[x[i][j]] == 0)
                MP[x[i][j]] = ++cnt;
            x[i][j] = MP[x[i][j]];
        }
}

int f[310 * 310];
int sol = 1, unq = 0;

void baga(int i, int j) {
    ++f[x[i][j]];
    if (f[x[i][j]] == 1)
        ++unq;
}

void scoate(int i, int j) {
    --f[x[i][j]];
    if (f[x[i][j]] == 0)
        --unq;
}

void solve(int px, int py, int N, int M, int K) {
    int lx = px, ly = py;
    ++px; ++py;
    unq = 0;
    memset(f, 0, sizeof(f));
    baga(lx, ly);
    while (px <= N && py <= M) {
        for (int i = lx; i < px; ++i)
            baga(i, py);
        for (int j = ly; j < py; ++j)
            baga(px, j);
        baga(px, py);
        while (unq > K) {
            for (int i = lx; i <= px; ++i)
                scoate(i, ly);
            for (int i = ly + 1; i <= py; ++i)
                scoate(lx, i);
            ++lx; ++ly;
        }
        if (px - lx + 1 > sol) {
            sol = px - lx + 1;
            //cerr << lx << " " << ly << " " << px << " " << py << " " << unq << endl;
        }
        ++px; ++py;
    }
}

int main() {
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);

    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &x[i][j]);

    norm(N, M);

    for (int i = 1; i <= M; ++i)
        solve(1, i, N, M, K);
    for (int i = 2; i <= N; ++i)
        solve(i, 1, N, M, K);

    printf("%d", sol);
    return 0;
}
