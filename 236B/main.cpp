#include <stdio.h>

inline int min(int A, int B) {
    return A < B ? A : B;
}

int main() {
    int k, a, b, v;
    scanf("%d%d%d%d", &k, &a, &b, &v);

    for (int boxes = 1; ; ++boxes) {
        int bars = min(k - 1, b);
        a = a - (bars + 1) * v;
        b = b - bars;
        if (a <= 0) {
            printf("%d", boxes);
            return 0;
        }
    }

    return 0;
}
