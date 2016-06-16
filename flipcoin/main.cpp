#include <stdio.h>

int AINT[4 * 100100 + 69];
bool lazy[4 * 100100 + 69];

void update(int nod, int st, int dr, int xx, int yy) {
    if (lazy[nod]) {
        lazy[nod] = 0;
        AINT[nod] = dr - st + 1 - AINT[nod];
        if (st != dr) {
            lazy[2 * nod] ^= 1;
            lazy[2 * nod + 1] ^= 1;
        }
    }

    if (xx <= st && dr <= yy) {
        AINT[nod] = dr - st + 1 - AINT[nod];
        if (st != dr) {
            lazy[2 * nod] ^= 1;
            lazy[2 * nod + 1] ^= 1;
        }
        return ;
    }

    if (st >= dr || st > yy || dr < xx)
        return ;

    int m = (st + dr) / 2;
    update(2 * nod, st, m, xx, yy);
    update(2 * nod + 1, m + 1, dr, xx, yy);

    AINT[nod] = AINT[2 * nod] + AINT[2 * nod + 1];
}

int query(int nod, int st, int dr, int xx, int yy) {
    if (lazy[nod]) {
        lazy[nod] = 0;
        AINT[nod] = dr - st + 1 - AINT[nod];
        if (st != dr) {
            lazy[2 * nod] ^= 1;
            lazy[2 * nod + 1] ^= 1;
        }
    }

    if (xx <= st && dr <= yy)
        return AINT[nod];

    int m = (st + dr) / 2, res = 0;
    if (xx <= m)
        res += query(2 * nod, st, m, xx, yy);
    if (m < yy)
        res += query(2 * nod + 1, m + 1, dr, xx, yy);
    return res;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 0) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            update(1, 0, n - 1, xx, yy);
        } else {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            printf("%d\n", query(1, 0, n - 1, xx, yy));
        }
    }

    return 0;
}
