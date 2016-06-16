#include <stdio.h>
#include <algorithm>

using namespace std;

int sums[1000100];
int far[1000100];

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        ++sums[xx]; --sums[yy + 1];
        far[xx] = max(far[xx], yy);
    }

    int beg = -1, end = -1;
    for (int i = 1; i <= 1000000; ++i) {
        sums[i] += sums[i - 1];
        if (sums[i] == 0)
            continue;
        if (i > end) {
            if (end != -1)
                printf("%d %d\n", beg, end);
            beg = i;
        }
        end = max(end, far[i]);
    }
    printf("%d %d", beg, end);
    return 0;
}
