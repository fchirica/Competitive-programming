//Daca nu iau totul mai bine nu ma complic
//Nu sunt de liga a doua, eu joc in Champions League

#include <stdio.h>

int a[222][222];

void doIt(int n) {
    if (n == 3) {
        a[1][2] = a[2][3] = a[3][1] = 1;
        return ;
    }
    if (n == 6) {
        a[1][2] = a[1][4] = a[1][6] = 1;
        a[2][3] = a[2][5] = a[2][6] = 1;
        a[3][1] = a[3][5] = a[4][2] = 1;
        a[4][3] = a[4][5] = a[5][1] = 1;
        a[5][6] = a[6][3] = a[6][4] = 1;
        return ;
    }

    doIt(n - 2);
    a[n - 1][n] = 1;
    for (int i = 1; i <= n - 2; ++i)
        a[i][n - 1] = a[n][i] = 1;
}

int main() {
    freopen("oras.in", "r", stdin);
    freopen("oras.out", "w", stdout);

    int n;
    scanf("%d", &n);

    if (n == 4) {
        printf("-1");
        return 0;
    }

    doIt(n);
    for (int i = 1; i <= n; ++i, printf("\n"))
        for (int j = 1; j <= n; ++j)
            printf("%d", a[i][j]);
    return 0;
}
