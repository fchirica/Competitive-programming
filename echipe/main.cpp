#include <stdio.h>
#include <algorithm>

using namespace std;

inline int min(int A, int B) {
    return A < B ? A : B;
}

inline int max(int A, int B) {
    return A > B ? A : B;
}

struct interval {
    int x, y;
} x[255], setOne[255], setTwo[255];

inline bool comp1(interval A, interval B) {
    return A.y - A.x > B.y - B.x;
}

inline bool comp2(interval A, interval B) {
    return A.y < B.y;
}

interval intersect(interval A, interval B) {
    interval C;
    C.x = max(A.x, B.x);
    C.y = min(A.y, B.y);
    return C;
}

interval make(int A, int B) {
    interval C;
    C.x = A;
    C.y = B;
    return C;
}

int dp[255][255];

int main() {
    freopen("echipe.in", "r", stdin);
    freopen("echipe.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);

    sort(x + 1, x + n + 1, comp1);

    int best = 0;
    for (int i = 1; i < k; ++i)
        best += x[i].y - x[i].x;
    interval I = make(x[k].x, x[k].y);
    for (int i = k + 1; i <= n; ++i)
        I = intersect(I, x[i]);
    if (I.x <= I.y)
        best += I.y - I.x;

    sort(x + 1, x + n + 1, comp2);
    int myMax = -1;
    int nO = 0, nT = 0;
    setOne[++nO] = x[1];
    myMax = x[1].x;
    for (int i = 2; i <= n; ++i) {
        if (myMax > x[i].x)
            setTwo[++nT] = x[i];
        else
            setOne[++nO] = x[i];
        myMax = max(myMax, x[i].x);
    }

    for (int i = 1; i <= nO; ++i)
        dp[i][0] = -1000000000;

    for (int i = 1; i <= nO; ++i)
        for (int j = 1; j <= i; ++j) {
            interval I;
            I = setOne[i];
            for (int k = i; k >= 1; --k) {
                I.y = setOne[k].y;
                dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] + I.y - I.x);
            }
        }

    sort(setTwo + 1, setTwo + nT + 1, comp1);
    int psum = 0;
    for (int i = 0; i <= nT && i <= k; ++i) {
        psum += setTwo[i].y - setTwo[i].x;
        int cur = psum + dp[nO][k - i];
        if (cur > best)
            best = cur;
    }
    printf("%d", best);
    return 0;
}
