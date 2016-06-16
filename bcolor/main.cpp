#include <stdio.h>
#include <bitset>
#include <iostream>

using namespace std;

int N, M, K;
int E[4][222];

bool vis[222];

bitset <222> eq[222];
int val[222];
bool fr[222];

void dfs(int nod) {
    vis[nod] = 1;
    for (int i = 1; i <= M; ++i) {
        if (E[1][i] == nod && !vis[E[2][i]])
            dfs(E[2][i]);
        if (E[2][i] == nod && !vis[E[1][i]])
            dfs(E[1][i]);
    }
}

int main() {
    freopen("bcolor.in", "r", stdin);
    freopen("bcolor.out", "w", stdout);

    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= M; ++i)
        scanf("%d%d%d", &E[1][i], &E[2][i], &E[3][i]);

    dfs(1);
    for (int i = 1; i <= M; ++i)
        if (!vis[E[1][i]])
            E[3][i] = 1;

    for (int i = 1; i <= M; ++i) {
        if (E[3][i] == 0) {
            eq[E[1][i]][M - i + 1] = 1;
            eq[E[2][i]][M - i + 1] = 1;
        }
        if (E[3][i] == 2) {
            eq[E[1][i]][M + 1] = eq[E[1][i]][M + 1] ^ 1;
            eq[E[2][i]][M + 1] = eq[E[2][i]][M + 1] ^ 1;
        }
        val[M - i + 1] = E[3][i] - 1;
    }

    for (int i = 1; i <= M; ++i)
        fr[i] = 1;

    int i = 1, j = 1;
    while (i <= N && j <= M) {
        int k;
        for (k = i; k <= N; ++k)
            if (eq[k][j])
                break;

        if (k == N + 1) {
            ++j;
            continue;
        }
        fr[j] = 0;

        bitset <222> aux;
        aux = eq[i];
        eq[i] = eq[k];
        eq[k] = aux;

        for (k = i + 1; k <= N; ++k)
            if (eq[k][j])
                eq[k] ^= eq[i];

        ++i; ++j;
    }

    --K;
    for (int i = 1; i <= M; ++i)
        if (fr[i] && E[3][M - i + 1])
            fr[i] = 0;
    for (int i = 1; i <= M; ++i)
        if (fr[i]) {
            val[i] = K % 2;
            K /= 2;
        }

    for (int i = N; i >= 1; --i) {
            for (j = 1; j <= M; ++j)
                if (eq[i][j])
                    break;
            int res = eq[i][M + 1];
            for (int k = j + 1; k <= M; ++k)
                res ^= eq[i][k] * val[k];
            val[j] = res;
        }

    for (int i = M; i >= 1; --i)
        printf("%c", val[i] == 0 ? 'A' : 'R');
    return 0;
}
