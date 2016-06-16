#include <stdio.h>

int pref[100100], res[200200];

void swap(int &A, int &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

int main() {
    freopen("permutare.in", "r", stdin);
    freopen("permutare.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; ++i)
        scanf("%d", &pref[i]);
    res[1] = n + 1;
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        res[++cnt] = i;
        res[++cnt] = 2 * n + 2 - i;
    }

    cnt = 2;
    for (int i = 2; i <= n; ++i) {
        if (pref[i] == -1)
            swap(res[cnt + 1], res[cnt + 3]);
        if (pref[i] == 1)
            swap(res[cnt], res[cnt + 2]);
        cnt += 2;
    }

    for (int i = 1; i <= 2 * n + 1; ++i)
        printf("%d ", res[i]);
    return 0;
}
