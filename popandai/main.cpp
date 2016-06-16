#include <stdio.h>
#include <algorithm>

using namespace std;

struct punct {
    int x, y;
} x[333];

inline bool comp(punct A, punct B) {
    if (A.x == B.x)
        return A.y < B.y;
    return A.x < B.x;
}

inline long long ccw(punct A, punct B, punct C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

int under[333][333];

void swap(int &A, int &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

int tri(int i, int j, int k) {
    if (i > j)
        swap(i, j);
    if (i > k)
        swap(i, k);
    if (j > k)
        swap(j, k);
    if (ccw(x[i], x[k], x[j]) > 0)
        return under[i][j] + under[j][k] - under[i][k];
    return under[i][k] - under[i][j] - under[j][k] - 1;
}

long long best[333];

int main() {
    freopen("popandai.in", "r", stdin);
    freopen("popandai.out", "w", stdout);

    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);
    sort(x + 1, x + N + 1, comp);

    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
            for (int k = i + 1; k < j - 1; ++k)
                if (x[k].x <= x[j].x)
                    if (ccw(x[i], x[j], x[k]) < 0)
                            ++under[i][j];

        int ret = tri(5, 7, 8);


    long long sol = 1000005555;
    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j) {
            for (int k = 0; k <= N; ++k)
                best[k] = 500000000;
            for (int k = 1; k <= N; ++k)
                if (k != i && k != j)
                    if (ccw(x[i], x[j], x[k]) > 0) {
                        int in = tri(i, j, k);
                        if (best[in] > ccw(x[i], x[j], x[k]))
                            best[in] = ccw(x[i], x[j], x[k]);
                    }
            for (int k = 1; k <= N; ++k)
                if (k != i && k != j)
                    if (ccw(x[i], x[j], x[k]) < 0) {
                        int in = tri(i, j, k);
                        if (K - in >= 0) {
                            long long cur = best[K - in] - ccw(x[i], x[j], x[k]);
                            if (cur < sol)
                                sol = cur;
                        }
                    }
        }

    printf("%.1lf", (double)sol * 0.5);
    return 0;
}
