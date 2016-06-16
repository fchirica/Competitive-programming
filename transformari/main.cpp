#include <stdio.h>

int solve(int A, int B) {
    if (B == 1)
        return A - 1;
    if (B == 0)
        return 1 << 30;
    return A / B + solve(B, A % B);
}

int main() {
    freopen("transformari.in", "r", stdin);
    freopen("transformari.out", "w", stdout);

    int N;
    scanf("%d", &N);

    int sol = 1 << 30;
    for (int i = 1; i <= N; ++i)
        if (solve(i, N) < sol)
            sol = solve(i, N);

    printf("%d", sol);
    return 0;
}
