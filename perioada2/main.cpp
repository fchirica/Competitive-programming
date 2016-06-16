#include <stdio.h>
#include <string.h>

char x[10001000];
int pref[10001000];

void solve(int n) {
    for (int i = 2; i <= n; ++i) {
        int pf = pref[i - 1];
        while (1) {
            if (x[i] == x[pf + 1]) {
                ++pf;
                break;
            }
            if (pf == 0)
                break;
            pf = pref[pf];
        }
        pref[i] = pf;
    }

    int smallest = n - pref[n], cnt = 0, res = 0;
    for (int i = 1; i < n; ++i)
        if (n % i == 0 && i % smallest == 0)
            ++res;
    printf("%d", res);
}

int main() {
    freopen("perioada2.in", "r", stdin);
    freopen("perioada2.out", "w", stdout);

    int n;
    scanf("%d\n", &n);
    gets(x + 1);
    solve(n);

    return 0;
}

