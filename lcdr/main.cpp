#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char tmp[555];
int x[555][555], down[555][555], pv[555];

struct intrebare {
    int L, C, idx, L1, L2, ans;
} Q[500500];

struct comp {
    inline bool operator () (intrebare A, intrebare B) {
        return A.L < B.L;
    }
};

int AINT[4 * 500 + 1];

int query(int nod, int st, int dr, int qst, int qdr) {
    if (qst <= st && dr <= qdr)
        return AINT[nod];
    int med = (st + dr) / 2;
    int res = 0, res2 = 0;
    if (qst <= med)
        res = query(2 * nod, st, med, qst, qdr);
    if (med < qdr)
        res2 = query(2 * nod + 1, med + 1, dr, qst, qdr);
    if (res2 > res)
        res = res2;
    return res;
}


void update(int nod, int st, int dr, int pos, int val) {
    if (st == dr) {
        AINT[nod] = val;
        return ;
    }

    int med = (st + dr) / 2;
    if (pos <= med)
        update(2 * nod, st, med, pos, val);
    else
        update(2 * nod + 1, med + 1, dr, pos, val);
    AINT[nod] = AINT[2 * nod];
    if (AINT[2 * nod + 1] > AINT[2 * nod])
        AINT[nod] = AINT[2 * nod + 1];
}

struct comp2 {
    inline bool operator () (intrebare A, intrebare B) {
        return A.idx < B.idx;
    }
};

int main() {
    freopen("lcdr.in", "r", stdin);
    freopen("lcdr.out", "w", stdout);

    int n, m, q;
    scanf("%d%d%d\n", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        gets(tmp + 1);
        for (int j = 1; j <= m; ++j)
            x[i][j] = tmp[j] - '0';
    }

    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            if (x[i][j] == 0)
                down[i][j] = 0;
            else
                down[i][j] = down[i + 1][j] + 1;

    for (int i = 1; i <= q; ++i) {
        scanf("%d%d%d%d", &Q[i].L, &Q[i].C, &Q[i].L1, &Q[i].L2);
        Q[i].idx = i;
    }

    sort(Q + 1, Q + q + 1, comp());
    for (int i = 1; i <= n; ++i)
        pv[i] = -1;
    for (int i = 1; i <= q; ++i) {
        if (Q[i].L != Q[i - 1].L) {
            memset(AINT, 0, sizeof(AINT));
            for (int lin = 1; lin <= n; ++lin) {
                int best = 0, cur = 0;
                for (int col = 1; col <= m; ++col)
                    if (down[lin][col] >= Q[i].L)
                        ++cur;
                    else {
                        if (cur > best)
                            best = cur;
                        if (best == pv[lin])
                            break;
                        cur = 0;
                    }
                if (cur > best)
                    best = cur;
                update(1, 1, n, lin, best);
                pv[lin] = best;
            }
        }
        if (Q[i].L1 <= Q[i].L2 - Q[i].L + 1)
            Q[i].ans = query(1, 1, n, Q[i].L1, Q[i].L2 - Q[i].L + 1) >= Q[i].C ? 1 : 0;
        else
            Q[i].ans = 0;
    }

    sort(Q + 1, Q + q + 1, comp2());
    for (int i = 1; i <= q; ++i)
        printf("%d\n", Q[i].ans);
    return 0;
}
