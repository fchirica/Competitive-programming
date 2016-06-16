#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct nod {
    vector <unsigned> AIB;
    vector <unsigned> val;
} AINT[3 * 100000 + 69];

int x[100100], sortedx[100100];
bool state[100100];
map <int, int> M;

inline int lsb(int X) {
    return X & -X;
}

void build(int nod, int st, int dr) {
    if (st == dr) {
        AINT[nod].AIB.push_back(0);
        AINT[nod].AIB.push_back(1);
        AINT[nod].val.push_back(0);
        AINT[nod].val.push_back(M[x[st]]);
        return ;
    }

    int med = (st + dr) / 2;
    build(2 * nod, st, med);
    build(2 * nod + 1, med + 1, dr);

    AINT[nod].AIB.push_back(0);
    for (int i = st; i <= dr; ++i)
        AINT[nod].AIB.push_back(lsb(i - st + 1));
    AINT[nod].val.push_back(0);
    int ptr1 = 1, ptr2 = 1;
    while (ptr1 < AINT[2 * nod].val.size() || ptr2 < AINT[2 * nod + 1].val.size()) {
        if (ptr1 == AINT[2 * nod].val.size())
            AINT[nod].val.push_back(AINT[2 * nod + 1].val[ptr2++]);
        else if (ptr2 == AINT[2 * nod + 1].val.size())
            AINT[nod].val.push_back(AINT[2 * nod].val[ptr1++]);
        else {
            if (AINT[2 * nod].val[ptr1] < AINT[2 * nod + 1].val[ptr2])
                AINT[nod].val.push_back(AINT[2 * nod].val[ptr1++]);
            else
                AINT[nod].val.push_back(AINT[2 * nod + 1].val[ptr2++]);
        }
    }
}

void update(int nod, int st, int dr, int pos, int val) {
    int left = 1, right = dr - st + 1, where;
    while (left <= right) {
        int med = (left + right) / 2;
        if (AINT[nod].val[med] == val) {
            where = med;
            break;
        }
        if (AINT[nod].val[med] < val)
            left = med + 1;
        else
            right = med - 1;
    }

    int am;
    if (state[pos] == 0)
        am = 1;
    else
        am = -1;
    while (where <= dr - st + 1) {
        AINT[nod].AIB[where] += am;
        where += lsb(where);
    }

    if (st != dr) {
        int med = (st + dr) / 2;
        if (pos <= med)
            update(2 * nod, st, med, pos, val);
        else
            update(2 * nod + 1, med + 1, dr, pos, val);
    }
}

int nodes[1000], len[1000];

int cnt(int lim) {
    int tot = 0;
    for (int i = 1; i <= nodes[0]; ++i) {
        int left = 1, right = len[i], pos = 0;
        while (left <= right) {
            int med = (left + right) / 2;
            if (AINT[nodes[i]].val[med] <= lim) {
                pos = med;
                left = med + 1;
            }
            else
                right = med - 1;
        }
        while (pos > 0) {
            tot += AINT[nodes[i]].AIB[pos];
            pos -= lsb(pos);
        }
    }
    return tot;
}

void decompose(int nod, int st, int dr, int qst, int qdr) {
    if (qst <= st && dr <= qdr) {
        nodes[++nodes[0]] = nod;
        len[++len[0]] = dr - st + 1;
        return ;
    }

    int med = (st + dr) / 2;
    if (qst <= med)
        decompose(2 * nod, st, med, qst, qdr);
    if (med < qdr)
        decompose(2 * nod + 1, med + 1, dr, qst, qdr);
}

int main() {
    freopen("mess.in", "r", stdin);
    freopen("mess.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
        sortedx[i] = x[i];
    }
    sort(sortedx + 1, sortedx + n + 1);
    for (int i = 1; i <= n; ++i) {
        M[sortedx[i]] = i;
        state[i] = 1;
    }

    build(1, 1, n);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int pos;
            scanf("%d", &pos);
            int val = M[x[pos]];
            update(1, 1, n, pos, val);
            state[pos] ^= 1;
        } else {
            int p, q, k;
            scanf("%d%d%d", &p, &q, &k);
            nodes[0] = 0;
            len[0] = 0;
            decompose(1, 1, n, p, q);
            int st = 1, dr = n, res;
            while (st <= dr) {
                int med = (st + dr) / 2;
                int ret = cnt(med);
                if (ret < k)
                    st = med + 1;
                else if (ret == k) {
                    res = med;
                    dr = med - 1;
                } else
                    dr = med - 1;
            }
            printf("%d\n", sortedx[res]);
        }
    }

    return 0;
}
