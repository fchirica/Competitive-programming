#include <stdio.h>

int x[555];

int main() {
    int N;
    scanf("%d", &N);
    while (N != -1) {
        for (int i = 1; i <= N; ++i)
            scanf("%d", &x[i]);

        bool move;
        do {
            move = false;
            for (int i = 1; i <= N; ++i)
                if (x[i] == i) {
                    move = true;
                    x[i] = 0;
                    for (int j = 1; j < i; ++j)
                        ++x[j];
                    break;
                }
        } while (move);

        bool allZero = true;
        for (int i = 1; i <= N; ++i)
            if (x[i])
                allZero = false;
        printf("%c\n", allZero ? 'S' : 'N');
        scanf("%d", &N);
    }

    return 0;
}
