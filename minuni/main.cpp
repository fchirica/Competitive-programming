#include <stdio.h>
#include <algorithm>

using namespace std;

struct event {
    int val, type, t, shit;
} E[200200];
int xx[100100], yy[100100];

inline bool comp(event A, event B) {
    return A.val < B.val;
}

int AINT[4 * 100100];
long long res[100100];

void update(int nod, int st, int dr, int who, int val) {
    if (st == dr) {
        AINT[nod] = val;
        return ;
    }
    int med = (st + dr) / 2;
    if (who <= med)
        update(2 * nod, st, med, who, val);
    else
        update(2 * nod + 1, med + 1, dr, who, val);
    AINT[nod] = AINT[2 * nod];
    if (AINT[2 * nod] < AINT[2 * nod + 1])
        AINT[nod] = AINT[2 * nod + 1];
}

int query(int nod, int st, int dr, int a, int b) {
    if (a <= st && dr <= b)
        return AINT[nod];
    int med = (st + dr) / 2, mx1 = 0, mx2 = 0;
    if (a <= med)
        mx1 = query(2 * nod, st, med, a, b);
    if (med < b)
        mx2 = query(2 * nod + 1, med + 1, dr, a, b);
    return mx1 > mx2 ? mx1 : mx2;
}

int main() {
    freopen("minuni.in", "r", stdin);
    freopen("minuni.out", "w", stdout);

    int N, M, cnt = 0;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &xx[i], &yy[i]);
        E[++cnt].val = xx[i]; E[cnt].type = 0; E[cnt].t = i; E[cnt].shit = yy[i];
        E[++cnt].val = yy[i]; E[cnt].type = 1; E[cnt].t = i;
    }

    sort(E + 1, E + cnt + 1, comp);
    for (int i = 1; i <= cnt; ++i)
        if (E[i].type == 0) {
            int idx = 0;
            if (E[i].t > 1)
                idx = query(1, 1, M, 1, E[i].t - 1);
            if (idx) {
                int a = E[idx].val, b = E[idx].shit, x = xx[E[i].t], y = yy[E[i].t];
                res[E[i].t] = (1LL * b - y) * x + (1LL * N - b + 1) * (x - a);
            } else
                res[E[i].t] = 1LL * xx[E[i].t] * (N - yy[E[i].t] + 1);
            update(1, 1, M, E[i].t, i);
        } else
            update(1, 1, M, E[i].t, 0);

    for (int i = 1; i <= M; ++i)
        printf("%lld\n", res[i]);
    return 0;
}

