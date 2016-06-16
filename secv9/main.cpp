#include <stdio.h>
#include <algorithm>
#define x first
#define y second

using namespace std;

int x[100010];
pair <long long, int> S[100010];

int main() {
    freopen("secv9.in", "r", stdin);
    freopen("secv9.out", "w", stdout);

    int N, minSum;
    scanf("%d%d", &N, &minSum);
    S[0] = make_pair(0, 0);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &x[i]);
        S[i] = make_pair(S[i - 1].x + x[i], i);
    }
    sort(S, S + N + 1);

    int j = 0, res = 0, best = N + 1;
    for (int i = 0; i <= N; ++i) {
        for (; j <= i; ++j)
            if (S[i].x - S[j].x < minSum)
                break;
            else
                if (S[j].y < best)
                    best = S[j].y;
        if (best != N + 1 && S[i].y > best)
            if (res < S[i].y - best)
                res = S[i].y - best;
    }

    printf("%d", res);
    return 0;
}
