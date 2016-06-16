#include <stdio.h>

long long AINT[4 * 100100 + 69], lazy[4 * 100100 + 69];

void push(int st, int dr, int nod) {
    lazy[2 * nod] += lazy[nod];
    lazy[2 * nod + 1] += lazy[nod];

    int m = (st + dr) / 2;
    AINT[2 * nod] += (m - st + 1) * lazy[nod];
    AINT[2 * nod + 1] += (dr - m) * lazy[nod];

    lazy[nod] = 0;
}

void update(int nod, int st, int dr, int ust, int udr, int val) {
    if (ust <= st && dr <= udr) {
        AINT[nod] += ((long long)dr - st + 1) * val;
        lazy[nod] += val;
        return ;
    }

    push(st, dr, nod);

    int m = (st + dr) / 2;
    if (ust <= m)
        update(2 * nod, st, m, ust, udr, val);
    if (m < udr)
        update(2 * nod + 1, m + 1, dr, ust, udr, val);

    AINT[nod] = AINT[2 * nod] + AINT[2 * nod + 1];
}

long long query(int nod, int st, int dr, int qst, int qdr) {
    if (qst <= st && dr <= qdr)
        return AINT[nod];

    push(st, dr, nod);

    long long s = 0;
    int m = (st + dr) / 2;
    if (qst <= m)
        s += query(2 * nod, st, m, qst, qdr);
    if (m < qdr)
        s += query(2 * nod + 1, m + 1, dr, qst, qdr);

    return s;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        while (m--) {
            int op;
            scanf("%d", &op);
            if (op == 0) {
                int x, y, z;
                scanf("%d%d%d", &x, &y, &z);
                update(1, 1, n, x, y, z);
            } else {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%lld\n", query(1, 1, n, x, y));
            }
        }

        for (int i = 0; i <= 4 * n; ++i)
            AINT[i] = lazy[i] = 0;
    }
}
