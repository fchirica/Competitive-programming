#include <stdio.h>
#include <algorithm>

using namespace std;

struct point {
    int x, y, ord;
} x[2 * 1024], LL;

inline long long ccw(point A, point B, point C) {
    return (1LL * B.x - A.x) * (C.y - B.y) - (1LL * B.y - A.y) * (C.x - B.x);
}

inline bool comp(point A, point B) {
    return ccw(x[1], A, B) > 0;
}

int main() {
    freopen("mission.in", "r", stdin);
    freopen("mission.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &x[i].x, &x[i].y);
        x[i].ord = i - 1;
        if (x[i].y < x[1].y || (x[i].y == x[1].y && x[i].x < x[1].x)) {
            LL = x[i];
            swap(x[i], x[1]);
        }
    }

    sort(x + 2, x + N + 1, comp);
    for (int i = N + 1; i <= 2 * N; ++i)
        x[i].ord = x[i - N].ord;
    for (int i = 1; i <= N; ++i)
        if (x[i].ord == 0) {
            for (int j = i; j <= i + N - 1; ++j)
                printf("%d ", x[j].ord);
            break;
        }
    return 0;
}
