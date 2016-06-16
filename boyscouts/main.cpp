#include <stdio.h>
#include <algorithm>
#include <math.h>
#define point pair <double, double>
#define x first
#define y second

using namespace std;

point LL, X[111], P[111];
int N, dp[111][111];

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

int solve(int startPoint) {
    int i, j, k, cntP = 0;
    P[++cntP] = X[startPoint];
    for (i = 1; i <= N; ++i)
        if (!(X[i].y < P[1].y || (X[i].y == P[1].y && X[i].x < P[1].x)))
            if (i != startPoint)
                P[++cntP] = X[i];

    sort(P + 2, P + cntP + 1, comp);

    P[++cntP] = P[1];
    for (i = 1; i <= cntP; ++i)
        for (j = 1; j <= cntP; ++j)
            dp[i][j] = 0;
    for (i = 1; i <= cntP; ++i)
        for (j = 1; j <= i - 1; ++j) {
            for (k = 1; k <= i - 1; ++k)
                if (ccw(P[j], P[k], P[i]) > 0)
                    chmax(dp[k][i], dp[j][k] + 1);
            dp[1][i] = 1;
        }
    int sol = 0;
    for (i = 1; i < cntP; ++i)
        chmax(sol, dp[i][cntP]);
    return sol;
}

int main() {
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
        scanf("%lf%lf", &X[i].x, &X[i].y);
    int sol = 0;

    for (i = 1; i <= N; ++i)
        chmax(sol, solve(i));
    printf("%d", sol);
    return 0;
}

