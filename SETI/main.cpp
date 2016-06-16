#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int SA[19][150000], ord[150000], res[150000];
char x[150000], tmp[77];
long long key[150000];

inline bool comp(int A, int B) {
    return key[A] < key[B];
}

void suffixArrays(int N) {
    for (int i = 0; (1 << i) <= 16; ++i) {
        if (i)
            for (int j = 1; j <= N; ++j) {
                key[j] = (N + 1000LL) * SA[i - 1][j];
                if (j + (1 << (i - 1)) <= N)
                    key[j] += SA[i - 1][j + (1 << (i - 1))];
                ord[j] = j;
            }
        else
            for (int j = 1; j <= N; ++j)
                key[j] = x[j], ord[j] = j;
        sort(ord + 1, ord + N + 1, comp);
        int cur = 1;
        SA[i][ord[1]] = 1;
        for (int j = 2; j <= N; ++j)
            if (key[ord[j]] == key[ord[j - 1]])
                SA[i][ord[j]] = cur;
            else
                SA[i][ord[j]] = ++cur;
    }
    for (int j = 1; j <= N; ++j)
        res[j] = ord[j];
}

int cnt;

inline int comp(int X) {
    X = res[X];
    for (int i = 1; i <= cnt; ++i) {
        if (x[X + i - 1] < tmp[i])
            return -1;
        if (x[X + i - 1] > tmp[i])
            return 1;
    }
    return 0;
}

int main() {
    freopen("seti.in", "r", stdin);
    freopen("seti.out", "w", stdout);

    int N;
    scanf("%d\n", &N);
    for (int i = 1; i <= N; ++i) {
        gets(tmp);
        strcat(x + 1, tmp);
    }

    N = N * 64;
    suffixArrays(N);
    int M;
    scanf("%d\n", &M);
    for (int i = 1; i <= M; ++i) {
        gets(tmp + 1);
        cnt = strlen(tmp + 1);
        int st = 1, dr = N, ret = -1, ret2 = -1;
        while (st <= dr) {
            int med = (st + dr) / 2;
            int rel = comp(med);
            if (rel == 0) {
                ret = med;
                dr = med - 1;
                continue;
            }
            if (rel == -1)
                st = med + 1;
            else
                dr = med - 1;
        }
        if (ret == -1) {
            printf("0\n");
            continue;
        }
        st = 1; dr = N;
        while (st <= dr) {
            int med = (st + dr) / 2;
            int rel = comp(med);
            if (rel == 0) {
                ret2 = med;
                st = med + 1;
                continue;
            }
            if (rel == -1)
                st = med + 1;
            else
                dr = med - 1;
        }
        printf("%d\n", ret2 - ret + 1);
    }

    return 0;
}
