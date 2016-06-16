#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct operation {
    int x, y;
} op[610];
int pw[35];

int getOnes(int mask) {
    int cnt = 0;
    while (mask) {
        ++cnt;
        mask = mask & (mask - 1);
    }
    return cnt;
}

int main() {
    freopen("sortari.in", "r", stdin);
    freopen("sortari.out", "w", stdout);

    srand(time(0));

    int T;
    scanf("%d", &T);
    for (int i = 0; i < 31; ++i)
        pw[i] = 1 << i;
    for (int test = 1; test <= T; ++test) {
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= M; ++i) {
            scanf("%d%d", &op[i].x, &op[i].y);
            --op[i].x; --op[i].y;
        }
        int good = 1;
        if (14 <= N && N <= 17) {
            for (int iter = 1; iter <= 30000 && good; ++iter) {
                int cmask = rand() % (1 << N);
                int ones = getOnes(cmask);
                for (int i = 1; i <= M; ++i)
                    if ((cmask & pw[op[i].x]) == 0 && (cmask & pw[op[i].y]))
                        cmask = cmask ^ (pw[op[i].x] | pw[op[i].y]);
                if (cmask != ((1 << ones) - 1))
                    good = 0;
            }
        } else
            for (int mask = 0; mask < (1 << N) && good; ++mask) {
                int cmask = mask;
                int ones = getOnes(mask);
                for (int i = 1; i <= M; ++i)
                    if ((cmask & pw[op[i].x]) == 0 && (cmask & pw[op[i].y]))
                        cmask = cmask ^ (pw[op[i].x] | pw[op[i].y]);
                if (cmask != ((1 << ones) - 1))
                    good = 0;
            }
        printf("%d\n", good);
    }

    return 0;
}
