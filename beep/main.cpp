#include <stdio.h>

int type[7];
int val[] = {0, 1, 5, 10, 50, 100, 500};
int x[5555];

void chmin(int &A, int B) {
    if (A > B)
        A = B;
}

int main() {
    freopen("bancomat.in", "r", stdin);
    freopen("bancomat.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 6; ++i)
            scanf("%d", &type[i]);

        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &x[i]);

        bool good = true;
        for (int i = 1; i <= n && good; ++i) {
            for (int j = 6; j >= 1; --j) {
                int am = type[j];
                chmin(am, x[i] / val[j]);
                type[j] -= am;
                x[i] = x[i] - am * val[j];
            }
            if (x[i])
                good = false;
        }
        printf("%s\n", good ? "YES" : "NO");
    }
    return 0;
}
