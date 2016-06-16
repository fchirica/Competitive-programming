#include <stdio.h>

int main() {
    int i, j;
    for (int i = 0; i < 64; ++i)
        for (int j = i + 1; j < 64; ++j) {
            int res = i ^ j;
            if ((res & (res - 1)) == 0)
                printf("%d\n", j - i);
        }

    return 0;

}
