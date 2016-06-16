#include <stdio.h>

int x[100100], y[100100], xx[200200], yy[200200], fail[310000], pref[310000], last[10100];

void build(int res[], int X[], int N) {
    for (int i = 1; i <= N; ++i)
        last[X[i]] = i;
    for (int i = 1; i <= N; ++i) {
        res[i] = res[i + N] = i + N - last[X[i]];
        last[X[i]] = i + N;
    }
}

int sol[10100];

void solve(int pos, int N, int M) {
    printf("%d\n", N - pos + 1);
    int cur = 0;
    for (int i = pos; i <= N; ++i)
        sol[x[i]] = y[++cur];
    for (int i = 1; i < pos; ++i)
        sol[x[i]] = y[++cur];
    for (int i = 1; i <= M; ++i)
        printf("%d ", sol[i]);
}

int main() {
    freopen("cifru2.in", "r", stdin);
    freopen("cifru2.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &x[i]);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &y[i]);

    build(xx, x, N);
    build(yy, y, N);

    int n = 0;
    for (int i = 1; i <= N; ++i)
        fail[++n] = yy[i];
    fail[++n] = -1;
    for (int i = 1; i <= 2 * N; ++i)
        fail[++n] = xx[i];
    for (int i = 2; i <= n; ++i) {
        int pf = pref[i - 1];
        while (1) {
            if (fail[pf + 1] == fail[i]) {
                ++pf;
                break;
            }
            if (pf == 0)
                break;
            pf = pref[pf];
        }
        pref[i] = pf;
        if (pref[i] == N) {
            solve(i - 2 * N, N, M);
            return 0;
        }
    }

    return 0;
}
