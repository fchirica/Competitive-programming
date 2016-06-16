#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int kNMax = 100010;

int n, q;

inline ll my_gcd(ll a, ll b) {
    while (b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

inline ll my_abs(ll a) {
    if (a < 0)
        a = -a;
    return a;
}

struct prog {
    long long sum;
    long long lazy;
} aint_prog[4 * kNMax];

void push_prog(int nod, int st, int dr) {
    if (aint_prog[nod].lazy) {
        aint_prog[2 * nod].lazy += aint_prog[nod].lazy;
        aint_prog[2 * nod + 1].lazy += aint_prog[nod].lazy;
        int middle = (st + dr) / 2;
        aint_prog[2 * nod].sum += aint_prog[nod].lazy * (middle - st + 1);
        aint_prog[2 * nod + 1].sum += aint_prog[nod].lazy * (dr - middle);
        aint_prog[nod].lazy = 0;
    }
}

void update_prog(int nod, int st, int dr, int ust, int udr, long long val) {
    if (ust <= st && dr <= udr) {
        aint_prog[nod].sum += (dr - st + 1) * val;
        aint_prog[nod].lazy += val;
        return ;
    }
    push_prog(nod, st, dr);
    int middle = (st + dr) / 2;
    if (ust <= middle)
        update_prog(2 * nod, st, middle, ust, udr, val);
    if (middle < udr)
        update_prog(2 * nod + 1, middle + 1, dr, ust, udr, val);
    aint_prog[nod].sum = aint_prog[2 * nod].sum + aint_prog[2 * nod + 1].sum;
}

long long query_prog(int nod, int st, int dr, int qst, int qdr) {
    if (qst <= st && dr <= qdr)
        return aint_prog[nod].sum;
    push_prog(nod, st, dr);
    long long my_sum = 0;
    int middle = (st + dr) / 2;
    if (qst <= middle)
        my_sum += query_prog(2 * nod, st, middle, qst, qdr);
    if (middle < qdr)
        my_sum += query_prog(2 * nod + 1, middle + 1, dr, qst, qdr);
    return my_sum;
}

void baga_progresie(int x, int y, int r) {
    update_prog(1, 1, n, x, y, r);
    if (y + 1 <= n)
        update_prog(1, 1, n, y + 1, y + 1, -(long long) r * (y - x + 1));
}

ll query_element(int pos) {
    return query_prog(1, 1, n, 1, pos);
}

struct magic_tree {
    ll inceput;
    ll sfarsit;
    ll val;
    ll lazy;
} aint[4 * kNMax];

void propaga(int nod, int st, int dr) {
    if (aint[nod].lazy) {
        aint[2 * nod].inceput += aint[nod].lazy;
        aint[2 * nod + 1].inceput += aint[nod].lazy;
        aint[2 * nod].sfarsit += aint[nod].lazy;
        aint[2 * nod + 1].sfarsit += aint[nod].lazy;
        aint[2 * nod].lazy += aint[nod].lazy;
        aint[2 * nod + 1].lazy += aint[nod].lazy;
        aint[nod].lazy = 0;
    }
}

void update(int nod, int st, int dr, int ust, int udr, ll val) {
    if (ust <= st && dr <= udr) {
        aint[nod].inceput += val;
        aint[nod].sfarsit += val;
        aint[nod].lazy += val;
        return ;
    }
    propaga(nod, st, dr);
    int middle = (st + dr) / 2;
    if (ust <= middle)
        update(2 * nod, st, middle, ust, udr, val);
    if (middle < udr)
        update(2 * nod + 1, middle + 1, dr, ust, udr, val);
    aint[nod].inceput = aint[2 * nod].inceput;
    aint[nod].sfarsit = aint[2 * nod + 1].sfarsit;
    aint[nod].val = my_gcd(my_abs(aint[2 * nod].val), my_abs(aint[2 * nod + 1].val));
    aint[nod].val = my_gcd(aint[nod].val, my_abs(aint[2 * nod + 1].inceput - aint[2 * nod].sfarsit));
}

ll query(int nod, int st, int dr, int qst, int qdr) {
    if (qst <= st && dr <= qdr)
        return my_gcd(my_abs(aint[nod].inceput), my_abs(aint[nod].val));
    propaga(nod, st, dr);
    int middle = (st + dr) / 2;
    ll my_res = 0;
    if (qst <= middle)
        my_res = query(2 * nod, st, middle, qst, qdr);
    if (middle < qdr)
        my_res = my_gcd(my_res, query(2 * nod + 1, middle + 1, dr, qst, qdr));
    return my_res;
}

ll query_subproblema(int st, int dr) {
    return query(1, 1, n, st, dr);
}

void update_subproblema(int st, int dr, int val) {
    update(1, 1, n, st, dr, val);
    if (dr + 1 <= n)
        update(1, 1, n, dr + 1, dr + 1, -(long long) val * (dr - st + 1));
}

void update_final(int st, int dr, int r) {
    baga_progresie(st, dr, r);
    update_subproblema(st, dr, r);
}

ll query_final(int st, int dr) {
    ll foo = query_element(st);
    if (st == dr)
        return foo;
    ll bar = query_subproblema(st + 1, dr);
    return my_gcd(foo, bar);
}

int main() {
    freopen("euclid.in", "r", stdin);
    freopen("euclid.out", "w", stdout);

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int foo;
        scanf("%d", &foo);
        update_final(i, i, foo);
    }
    while (q--) {
        int tip;
        scanf("%d", &tip);
        if (tip == 0) {
            int x, y, r;
            scanf("%d%d%d", &x, &y, &r);
            update_final(x, y, r);
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%I64d\n", query_final(x, y));
        }
    }
    return 0;
}
