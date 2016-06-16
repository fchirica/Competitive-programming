#include <stdio.h>
#include <string.h>
#define NMAX 90100
#include <algorithm>

using namespace std;

char x[NMAX];
long long key[NMAX];
int sa[NMAX], rank[NMAX], lcp[NMAX];
int N;

struct comp {
    bool operator () (int i, int j) const {
        return key[i] < key[j];
    }
};

void suffixArrays() {
    for (int i = 1; i <= N; ++i)
        sa[i] = i, key[i] = x[i];
    sort(sa + 1, sa + N + 1, comp());
    for (int pw = 1; ; pw *= 2) {
        for (int i = 1; i <= N; ++i)
            if (i > 1 && key[sa[i]] == key[sa[i - 1]])
                rank[sa[i]] = rank[sa[i - 1]];
            else
                rank[sa[i]] = rank[sa[i - 1]] + 1;
        if (pw >= N)
            break;
        for (int i = 1; i <= N; ++i) {
            key[i] = rank[i] * (N + 1LL);
            if (i + pw <= N)
                key[i] += rank[i + pw];
        }
        sort(sa + 1, sa + N + 1, comp());
    }
    for (int i = 1, k = 0; i <= N; ++i) {
        if (k > 0)
            --k;
        if (rank[i] == N) {
            lcp[N] = -1;
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (x[i + k] == x[j + k])
            ++k;
        lcp[rank[i]] = k;
    }
}

int gain[NMAX];
long long sum[NMAX];

int main() {
    gets(x + 1);
    N = strlen(x + 1);

    suffixArrays();

    int Q;
    scanf("%d", &Q);
    for (int i = 1; i <= N; ++i) {
        gain[i] = N - sa[i] + 1;
        if (i > 1)
            gain[i] -= lcp[i - 1];
        sum[i] = sum[i - 1] + gain[i];
    }

    while (Q--) {
        int z;
        scanf("%d", &z);
        for (int i = 1; i <= N; ++i)
            if (gain[i] < z)
                z = z - gain[i];
            else {
                for (int j = sa[i]; j < sa[i] + lcp[i - 1]; ++j)
                    printf("%c", x[j]);
                for (int j = sa[i] + lcp[i - 1]; z; ++j, --z)
                    printf("%c", x[j]);
                printf("\n");
                break;
            }
    }
    return 0;
}
