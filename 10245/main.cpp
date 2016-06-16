#include <stdio.h>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
} x[10100], tmp[10100], best;
int N, minDist = 1 << 30;

inline int dist(point A, point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

void change(point A, point B) {
    int curDist = dist(A, B);
    if (curDist < minDist) {
        minDist = curDist;
        best = A;
    }
}

inline int compX(point A, point B) {
    return A.x < B.x;
}

inline int compY(point A, point B) {
    return A.y < B.y;
}


void solve(int left, int right) {
    if (left >= right)
        return ;
    if (left + 1 == right)
        change(x[left], x[right]);
    int mid = (left + right) / 2;
    solve(left, mid);
    solve(mid + 1, right);
    int cnt = 0, i, j, checked;
    for (i = left; i <= right; ++i)
        if (abs(x[i].x - x[mid].x) <= minDist)
            tmp[++cnt] = x[i];
    sort(tmp + 1, tmp + cnt + 1, compY);
    for (i = 1; i <= cnt; ++i)
        for (j = i + 1, checked = 1; j <= cnt && checked <= 6; ++j, ++checked)
            change(x[i], x[j]);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d", &N);
        minDist = 1 << 30;
        for (int j = 1; j <= N; ++j)
            scanf("%d%d", &x[j].x, &x[j].y);
        sort(x + 1, x + N + 1, compX);
        solve(1, N);
        if (i > 1)
            printf("\n");
        printf("%d.000 %d.000", best.x, best.y);
    }

    return 0;
}
