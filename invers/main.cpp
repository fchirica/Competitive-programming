#include <stdio.h>
#include <string.h>

char S[10100];
int x[10100], xx[10100];

int solve(int st, int dr) {
    while (1) {
        if (st == dr)
            return 1 - x[st] % 2;
        if (st + 1 == dr)
            return ((x[st] == x[dr]) || (x[st] - x[dr] == 11));
        int diff = x[st] - x[dr];
        if (diff == 0 || diff == 1 || diff == 10 || diff == 11) {
            if (diff == 1 || diff == 11)
                x[st + 1] += 10;
            if (diff >= 10) {
                if (x[dr] == 9)
                    return 0;
                int i;
                for (i = dr - 1; x[i] == 0; --i)
                    x[i] = 9;
                --x[i];
                if (i == st)
                    return 0;
            }
        } else
            return 0;
        ++st;
        --dr;
    }
    return 1;
}

int solve2(int st, int dr) {
    if (x[1] != 1)
        return 0;
    for (int i = 1; i < dr; ++i)
        x[i] = xx[i + 1];
    x[1] += 10;
    return solve(1, dr - 1);
}

int main() {
    freopen("invers.in", "r", stdin);
    freopen("invers.out", "w", stdout);

    int T;
    scanf("%d\n", &T);
    while (T--) {
        gets(S + 1);
        int n = strlen(S + 1);
        for (int i = 1; i <= n; ++i)
            x[i] = xx[i] = S[i] - '0';
        if (n == 1) {
            printf("%s\n", x[1] % 2 ? "NU" : "DA");
            continue;
        }
        int ok = 0;
        if (x[n] > 0)
            ok = solve(1, n);
        if (ok == 0)
            ok = solve2(1, n);
        printf("%s\n", ok ? "DA" : "NU");
    }

    return 0;
}
