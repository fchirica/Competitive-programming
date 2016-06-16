#include <stdio.h>

int TT[1000100], R[1000100], sx[2000100], sy[2000100];
int x[2000100], y[2000100];

int dad(int X) {
    int root = X;
    while (root != TT[root])
        root = TT[root];
    while (X != root) {
        int tmp = TT[X];
        TT[X] = root;
        X = tmp;
    }
    return root;
}

void unite(int X, int Y) {
    if (R[X] <= R[Y]) {
        TT[X] = Y;
        if (R[X] == R[Y])
            ++R[X];
    }
    else
        TT[Y] = X;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int i, N, M, lim;
    scanf("%d%d%d", &N, &M, &lim);
    for (i = 1; i <= N; ++i)
        TT[i] = i, R[i] = 1;
    for (i = 1; i <= M; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        if (x[i] > lim && y[i] > lim) {
            int dadX = dad(x[i]);
            int dadY = dad(y[i]);
            if (dadX == dadY)
                continue;
            unite(dadX, dadY);
        }
    }

    for (i = 1; i <= M; ++i)
        if (x[i] <= lim || y[i] <= lim) {
            int dadX = dad(x[i]);
            int dadY = dad(y[i]);
            if (dadX == dadY)
                sx[++sx[0]] = x[i], sy[++sy[0]] = y[i];
            else
                unite(dadX, dadY);
        }

    printf("%d\n", sx[0]);
    for (i = 1; i <= sx[0]; ++i)
        printf("%d %d\n", sx[i], sy[i]);
    return 0;
}
