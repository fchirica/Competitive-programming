#include <stdio.h>
#include <algorithm>

using namespace std;

int xsum, solsum, x[1024], sol[1024], idx[1024];

inline double ab(double X) {
    return X > 0 ? X : -X;
}

inline double f(int idx, int supply) {
    return ab((double)x[idx] / xsum - ((double)sol[idx] + supply) / solsum);
}

inline double delta(int idx) {
    return f(idx, 1) - f(idx, 0);
}

inline bool comp(int A, int B) {
    return delta(A) - delta(B) <= -0.0000001;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, N, supply = 0;
    scanf("%d%d%d", &N, &solsum, &xsum);
    for (i = 1; i <= N; ++i) {
        scanf("%d", &x[i]);
        sol[i] = x[i] * solsum / xsum;
        idx[i] = i;
        supply += sol[i];
    }
    sort(idx + 1, idx + N + 1, comp);
    supply = solsum - supply;
    for (i = 1; i <= N && supply > 0; ++i, --supply)
        ++sol[idx[i]];
    for (i = 1; i <= N; ++i)
        printf("%d ", sol[i]);
    return 0;
}
