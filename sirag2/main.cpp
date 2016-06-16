#include <stdio.h>
#include <string.h>

char x[100100];
int pos[100100], res[100100], q[100100], shit[100100];

int main() {
    freopen("sirag2.in", "r", stdin);
    freopen("sirag2.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test) {
        int N, K;
        scanf("%d%d\n", &N, &K);
        gets(x + 1);
        for (int step = 1; step <= K; ++step)
            for (int i = step; i <= N; i += K)
                if (x[i] == '*')
                    pos[i] = i >= K ? pos[i - K] : 0;
                else
                    pos[i] = i;
        for (int i = 0; i < K; ++i)
            shit[i] = 0;
        for (int i = K; i <= N; ++i)
            shit[i] = shit[i - K] + 1;
        for (int step = 1; step <= K; ++step)
            for (int i = step; i <= N; i += K) {
                int last = 0;
                if (i > K)
                    last = pos[i - K];
                if (last == 0 || x[i] == '*')
                    res[i] = res[i - K] + 1;
                else {
                        res[i] = shit[i - last - K] + 1;
                        if (x[i] == x[last])
                            res[i] += res[last];
                    }
            }
        int p = 1, u = 0, sol = 0;
        for (int i = 1; i <= N; ++i) {
            while (p <= u && res[i] <= res[q[u]])
                --u;
            q[++u] = i;
            if (q[p] + K == i)
                ++p;
            if (i >= K && res[q[p]] > sol)
                sol = res[q[p]];
        }
        printf("%d\n", sol * K);
    }
    return 0;
}
