#include <stdio.h>

struct point {
    int x, y;
} x[2048];
bool del[2048];

inline int dist(point A, point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int main() {
    //freopen("1578.in", "r", stdin);
    //freopen("1578.out", "w", stdout);

    int i, j, N;
    scanf("%d", &N); N += 2;
    for (i = 1; i <= N; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);

    int idx = 1;
    printf("YES\n");
    for (i = 1; i <= N; ++i) {
        int maxDist = 0, newidx;
        printf("%d ", idx);
        del[idx] = true;
        for (j = 1; j <= N; ++j)
            if (!del[j] && dist(x[idx], x[j]) > maxDist)
                maxDist = dist(x[idx], x[j]), newidx = j;
        idx = newidx;
    }

    return 0;
}
