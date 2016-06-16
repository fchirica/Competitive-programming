#include <stdio.h>
#include <algorithm>

using namespace std;

struct par {
    int x, y;
} x[55555];

inline bool comp(par A, par B) {
    return A.y < B.y;
}

int main() {
    freopen("int.in", "r", stdin);
    freopen("int.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);

    sort(x + 1, x + n + 1, comp);
    int res = 1, last = x[1].y;
    for (int i = 2; i <= n; ++i)
        if (x[i].x >= last) {
            last = x[i].y;
            ++res;
        }
    printf("%d", res);
    return 0;
}
