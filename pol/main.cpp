#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>

using namespace std;

int fw[2][111][111][111];
int cur[111], tmp[111], tmp2[111], last[111], cycle[111], C[111];

void merge(int A[], int B[]) {
    int idx1 = 1, idx2 = 1;
    int len = min(100, A[0] + B[0]);
    for (int i = 1; i <= len; ++i) {
        if (idx2 > B[0]) {
            C[i] = A[idx1++];
            continue;
        }
        if (idx1 <= A[0] && A[idx1] < B[idx2])
            C[i] = A[idx1++];
        else
            C[i] = B[idx2++];
    }
    for (int i = 1; i <= len; ++i)
        A[i] = C[i];
    A[0] = len;
}

void split(int to[], int A[], int B[]) {
    multiset <pair <int, int> > H;
    if (B[0] == 0) {
        to[0] = 0;
        return ;
    }
    for (int i = 1; i <= A[0]; ++i)
        H.insert(make_pair(min(A[i] + B[1], 1 << 28), 1));
    int len = min(100, A[0] * B[0]);
    for (int i = 1; i <= len; ++i) {
        pair <int, int> X = (*H.begin());
        H.erase(H.begin());
        to[i] = X.first;
        if (X.second != B[0]) {
            ++X.second;
            X.first += B[X.second] - B[X.second - 1];
            X.first = min(X.first, 1 << 28);
            H.insert(X);
        }
    }
    to[0] = len;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            fw[0][i][j][0] = 0;
            for (int k = 1; k <= 100; ++k)
                fw[0][i][j][k] = 1 << 28;
        }
    for (int i = 1; i <= M; ++i) {
        int xx, yy, cc;
        scanf("%d%d%d", &xx, &yy, &cc);
        ++fw[0][xx][yy][0]; fw[0][xx][yy][fw[0][xx][yy][0]] = cc;
    }

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            sort(fw[0][i][j] + 1, fw[0][i][j] + fw[0][i][j][0] + 1);

    int act = 0;
    for (int k = 1; k <= N; ++k) {
        act = 1 - act;
        memcpy(last, fw[1 - act][k][k], sizeof(last));
        memcpy(cycle, fw[1 - act][k][k], sizeof(cycle));
        memset(fw[act][k][k], 0, sizeof(fw[act][k][k]));
        for (int times = 1; times <= 100; ++times) {
            merge(fw[act][k][k], last);
            split(cur, last, cycle);
            memcpy(last, cur, sizeof(last));
        }
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j) {
                if (i == j && i == k)
                    continue;
                memcpy(fw[act][i][j], fw[1 - act][i][j], sizeof(fw[act][i][j]));
                split(tmp, fw[1 - act][i][k], fw[1 - act][k][j]);
                merge(fw[act][i][j], tmp);
                split(tmp, fw[1 - act][i][k], fw[act][k][k]);
                split(tmp2, tmp, fw[1 - act][k][j]);
                merge(fw[act][i][j], tmp2);
            }
    }

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int xx, yy, zz;
        scanf("%d%d%d", &xx, &yy, &zz);
        printf("%d\n", zz <= fw[act][xx][yy][0] ? fw[act][xx][yy][zz] : -1);
    }

    return 0;
}

