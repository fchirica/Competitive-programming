#include <stdio.h>
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define FOR(i, n) REP(i, 1, n)

int F[100100];

int father(int x) {
    int root = x == F[x] ? x : father(F[x]);
    F[x] = root;
    return root;
}

void unite(int x, int y) {
    F[father(x)] = father(y);
}

int main() {
    freopen("disjoint.in", "r", stdin);
    freopen("disjoint.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    FOR(i, N) F[i] = i;
    FOR(test, M) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
            unite(x, y);
        else
            printf("%s\n", father(x) == father(y) ? "DA" : "NU");
    }

    return 0;
}
