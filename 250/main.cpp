#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char x[55];

int main() {
    freopen("test.out", "w", stdout);

    srand(time(0));

    for (int i = 1; i <= 20; ++i)
        x[i] = (char)'a' + rand() % 3;
    for (int i = 21; i <= 31; ++i)
        x[i] = (char)'a' + rand() % 20;
    for (int i = 32; i <= 45; ++i)
        x[i] = (char)'a' + rand() % 3;
    for (int i = 46; i <= 50; ++i)
        x[i] = (char)'a' + rand() % 20;
    for (int i = 1; i <= 50; ++i)
        printf("%c", x[i]);
    return 0;
}
