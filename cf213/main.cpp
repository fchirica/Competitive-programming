#include <stdio.h>
#include <algorithm>

using namespace std;

int x[55];
bool can[500002];
int steps[5000002];

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &x[i]);
    sort(x + 1, x + N + 1);
    int bestSum = 0;
    for (int i = 1; i <= N; ++i)
        if (bestSum + K >= x[i])
            bestSum += x[i];
        else
            break;

    can[0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = bestSum; j >= 0; --j)
            if (can[j])
                can[j + x[i]] = 1;

    int now = 0;
    for (int i = 1; i <= bestSum; ++i) {
        if (now < i - K)
            now = i - K;
        while (now < i && !can[now])
            ++now;
        if (now == i)
            break;
        steps[i] = steps[now] + 1;
    }

    printf("%d %d", bestSum, steps[bestSum]);
    return 0;
}
