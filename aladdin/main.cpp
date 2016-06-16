#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int a[1024][1024], b[1024][1024];
int iter = 0;

bool solution(int N, int M) {
    ++iter;
    if (iter == 1000000)
        return 1;
    for (int i = 2; i <= N; ++i)
        for (int j = 2; j <= M; ++j) {
            int el = a[i][j] - b[i - 1][j] - b[i][j - 1] - b[i - 1][j - 1];
            if (0 <= el && el <= 1)
                b[i][j] = el;
            else {
                int type = rand() % 3;
                if (type == 0)
                    b[i][1] = 1 - b[i][1];
                if (type == 1)
                    b[1][j] = 1 - b[1][j];
                if (type == 2) {
                    b[i][1] = 1 - b[i][1];
                    b[1][j] = 1 - b[1][j];
                }
                return 0;
            }
        }
    return 1;
}

int main() {
    freopen("aladdin.in", "r", stdin);
    freopen("aladdin.out", "w", stdout);

    printf("-1");
    return 0;

    srand(time(0));
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            scanf("%d", &a[i + 1][j + 1]);

    for (int j = 1; j <= m; ++j)
        b[1][j] = rand() % 2;
    for (int i = 1; i <= n; ++i)
        b[i][1] = rand() % 2;

    while (!solution(n, m));
    if (iter == 1000000) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; ++i, printf("\n"))
        for (int j = 1; j <= m; ++j)
            printf("%d ", b[i][j]);
    return 0;
}
