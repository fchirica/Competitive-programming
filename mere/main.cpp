//Muie Ponta!!!

#include <stdio.h>

int main() {
    freopen("mere.in", "r", stdin);
    freopen("mere.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if ((n / k) % 2 == 0 && n % k == 0)
            printf("Remiza\n"); //NEVER, oricum PONTA isi ia la MUIE
        else if (n < k)
            printf("Remiza\n");
        else
            printf("Santa Klaus\n");
    }

    return 0;
}
