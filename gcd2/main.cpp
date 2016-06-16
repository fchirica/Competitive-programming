#include <stdio.h>
#include <string.h>

char y[300];

int rem(int md) {
    int n = strlen(y), res = 0, pw = 1;
    for (int i = n - 1; i >= 0; --i) {
        res = (res + pw * (y[i] - '0')) % md;
        pw = pw * 10 % md;
    }
    return res;
}

int gcd(int A, int B) {
    if (B == 0)
        return A;
    return gcd(B, A % B);
}

int main() {
    int T;
    scanf("%d\n", &T);
    while (T--) {
        int x;
        scanf("%d %s\n", &x, &y);
        if (x == 0)
            printf("%s\n", y);
        else
            printf("%d\n", gcd(x, rem(x)));
    }
    return 0;
}
