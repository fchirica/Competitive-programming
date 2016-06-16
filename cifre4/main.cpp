#include <stdio.h>
#include <string.h>

int R[5 * 1000100];
int Q[5 * 1000100], prev[5 * 1000100], digits[] = {0, 2, 3, 5, 7};

int mod;

void recon(int rest) {
    if (rest == 0)
        return ;
    int last = prev[rest];
    for (int d = 1; d <= 4; ++d)
        if ((last * 10 + digits[d]) % mod == rest) {
            recon(last);
            printf("%d", digits[d]);
            break;
        }
}

int main() {
    freopen("cifre4.in", "r", stdin);
    freopen("cifre4.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int N, P;
        scanf("%d%d", &N, &P);
        mod = P;
        memset(R, 0, sizeof(R));
        memset(prev, 0, sizeof(prev));
        int p = 1, u = 0;
        Q[++u] = 0; R[0] = 1;
        while (p <= u) {
            int rest = Q[p];
            if (R[N])
                break;
            for (int d = 1; d <= 4; ++d) {
                int nrest = (rest * 10 + digits[d]) % P;
                if (R[nrest])
                    continue;
                R[nrest] = 1;
                prev[nrest] = rest;
                Q[++u] = nrest;
            }
            ++p;
        }
        if (R[N] == 0)
            printf("-1");
        else
            recon(N);
        printf("\n");
    }

    return 0;
}
