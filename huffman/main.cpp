#include <stdio.h>

long long Q1[500500], Q2[2 * 500500];

long long get(long long Q[], int p, int u, int chosen) {
    if (p + chosen - 1 > u)
        return -1;
    long long res = 0;
    for (int i = p; i <= p + chosen - 1; ++i)
        res += Q[i];
    return res;
}

int main() {
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);

    int i, N, p1 = 1, u1 = 0, p2 = 1, u2 = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
        scanf("%I64d", &Q1[++u1]);

    long long sol = 0;
    while (1) {
        int i, j, reti, retj;
        long long currentMin = 1LL << 60;
        for (i = 0; i <= 2; ++i)
            for (j = 0; j <= 2; ++j)
                if (i + j == 2)
                    if (get(Q1, p1, u1, i) > -1 && get(Q2, p2, u2, j) > -1) {
                        long long ret = get(Q1, p1, u1, i) + get(Q2, p2, u2, j);
                        if (ret < currentMin) {
                            currentMin = ret;
                            reti = i;
                            retj = j;
                        }
                    }
        if (currentMin == 1LL << 60)
            break;
        sol += currentMin;
        Q2[++u2] = currentMin;
        p1 += reti; p2 += retj;
    }

    printf("%I64d", sol);
    return 0;
}
