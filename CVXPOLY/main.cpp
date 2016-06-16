#include <stdio.h>
#include <algorithm>
#include <math.h>
#define point pair <double, double>
#define x first
#define y second
#define MOD 1234567

using namespace std;

point LL, X[111], P[111];
int N, dp[111][111], ord[111];
bool ccwSign[111][111][111];

inline double ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

inline bool comp(point A, point B) {
    return ccw(P[1], A, B) > 0;
}

inline void chmax(int &A, int B) {
    if (B > A)
        A = B;
}

void add(int &A, int B) {
    A += B;
    if (A >= MOD)
        A = A - MOD;
}

void precalc(int N) {
    int i, j, k;
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= N; ++j)
            for (k = 1; k <= N; ++k)
                if (ccw(X[i], X[j], X[k]) > 0)
                    ccwSign[i][j][k] = 1;
                else
                    ccwSign[i][j][k] = 0;
}

int solve(int startPoint) {
    int i, j, k, cntP = 0;
    P[++cntP] = X[startPoint];
    ord[1] = startPoint;
    for (i = 1; i <= N; ++i)
        if (!(X[i].y < P[1].y || (X[i].y == P[1].y && X[i].x < P[1].x)))
            if (i != startPoint) {
                //P[++cntP] = X[i];
                ord[++cntP] = i;
            }

    //Bubble
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (i = 2; i < cntP; ++i)
            if (ccwSign[ord[1]][ord[i]][ord[i + 1]] == 0) {
                swap(ord[i], ord[i + 1]);
                sorted = false;
            }
    }

    //P[++cntP] = P[1];
    ord[++cntP] = startPoint;

    for (i = 1; i <= cntP; ++i)
        for (j = 1; j <= cntP; ++j)
            dp[i][j] = 0;
    for (i = 2; i <= cntP; ++i)
        for (j = 1; j <= i - 1; ++j) {
            for (k = 1; k <= i - 1; ++k)
                if (ccwSign[ord[j]][ord[k]][ord[i]])
                    add(dp[k][i], dp[j][k]);
            dp[1][i] = 1;
        }
    int sol = 0;
    for (i = 2; i < cntP; ++i)
        add(sol, dp[i][cntP]);
    return sol;
}

int main() {
    int i, testCases;

    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    scanf("%d", &testCases);
    while (testCases--) {
        scanf("%d", &N);
        for (i = 1; i <= N; ++i)
            scanf("%lf%lf", &X[i].x, &X[i].y);

        precalc(N);

        int sol = 0;
        for (i = 1; i <= N; ++i)
            add(sol, solve(i));
        printf("%d\n", sol);
    }
    return 0;
}
