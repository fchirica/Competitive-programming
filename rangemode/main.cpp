#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int x[100100], xx[100100], yy[100100], F[100100], sol[100100];
vector <int> B[333];

inline bool comp(int A, int B) {
    return yy[A] < yy[B];
}

int lim;

inline int hi(int bucket) {
    return lim * bucket;
}

inline int low(int bucket) {
    return hi(bucket - 1) + 1;
}

int main() {
    freopen("rangemode.in", "r", stdin);
    freopen("rangemode.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);

    for (lim = 1; lim * lim <= n; ++lim);

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &xx[i], &yy[i]);
        B[xx[i] / lim + 1].push_back(i);
    }

    for (int i = 0; i <= n / lim + 1; ++i) {
        sort(B[i].begin(), B[i].end(), comp);
        memset(F, 0, sizeof(F));
        int ptr = low(i + 1);
        int best = 0, cbest;
        for (int j = 0; j < B[i].size(); ++j) {
            int pos = yy[B[i][j]];
            while (ptr <= pos) {
                ++F[x[ptr]];
                if (F[x[ptr]] > F[best] || (F[x[ptr]] == F[best] && best > x[ptr]))
                    best = x[ptr];
                ++ptr;
            }
            cbest = best;
            pos = xx[B[i][j]];
            for (int k = pos; k <= hi(i) && k <= yy[B[i][j]]; ++k) {
                ++F[x[k]];
                if (F[x[k]] > F[best] || (F[x[k]] == F[best] && best > x[k]))
                    best = x[k];
            }
            sol[B[i][j]] = best;
            for (int k = pos; k <= hi(i) && k <= yy[B[i][j]]; ++k)
                --F[x[k]];
            best = cbest;
        }
    }

    for (int i = 1; i <= m; ++i)
        printf("%d\n", sol[i]);

    return 0;
}
