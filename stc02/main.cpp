#include <stdio.h>

char S[500500];
int x[2000200], ma[2000200];

int main() {
    int N;
    long long sol = 0;

    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    scanf("%d\n", &N);
    gets(S + 1);
    int n = 0;
    for (int i = 1; i <= N; ++i) {
        int c = S[i] - '0';
        x[++n] = 1 - c; x[++n] = 10; x[++n] = c; x[++n] = 10;
    }

    int O = 0, R = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > O + R) {
            O = i;
            int r;
            for (r = 1; i - r > 0 && i + r <= n && x[i - r] == x[i + r]; ++r); --r;
            ma[i] = r; R = r; O = i;
        } else {
            int r = ma[2 * O - i];
            if (r > O + R - i)
                r = O + R - i;
            if (r == O + R - i) {
                for (; i - r > 0 && i + r <= n && x[i - r] == x[i + r]; ++r); --r;
                O = i; R = r;
            }
            ma[i] = r;
        }
        if (i % 4 == 0)
            sol += (ma[i] + 1) / 4;
    }

    printf("%lld", sol);
    return 0;
}
