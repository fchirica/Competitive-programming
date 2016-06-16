#include <stdio.h>
#include <algorithm>

using namespace std;

pair <int, int> X[1024];

inline int comp(pair <int, int> A, pair <int, int> B) {
    return A.first > B.first;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i < N; ++i)
        scanf("%d", &X[i].first);
    for (int i = N; i < N + M; ++i) {
        scanf("%d", &X[i].first);
        X[i].second = 1;
    }
    sort(X + 1, X + N + M + 1, comp);
    int line = 1, col = 1, cost = 0;
    for (int i = 1; i <= N + M - 2; ++i)
        if (X[i].second == 0) {
            cost += col * X[i].first;
            ++line;
        } else {
            cost += line * X[i].first;
            ++col;
        }
    printf("%d", cost);
    return 0;
}
