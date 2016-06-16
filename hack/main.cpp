#include <stdio.h>

int main() {
    freopen("data.out", "w", stdout);

    int i;
    for (i = 1; i <= 50; ++i)
        printf("%d,", 50 - i + 1);
    return 0;
}
