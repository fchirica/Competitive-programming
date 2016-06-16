#include <stdio.h>
#include <algorithm>

using namespace std;

int h[100010], pos[100010];

struct comp {
    inline bool operator () (int A, int B) {
        return h[A] > h[B];
    }
};

struct tree {
    tree *l, *r;
    int res;
    int len, pref, suf;

    tree () {
        l = r = NULL;
        res = pref = suf = 0;
    }
};

tree *root[100010];

tree *build(int st, int dr) {
    tree *res = new tree();
    if (st == dr) {
        res -> len = 1;
        return res;
    }

    int m = (st + dr) / 2;
    res -> l = build(st, m);
    res -> r = build(m + 1, dr);
    return res;
}

tree *merge(tree *A, tree *B) {
    tree *res = new tree();
    res -> len = A -> len + B -> len;
    if (A -> len == A -> res)
        res -> pref = A -> len + B -> pref;
    else
        res -> pref = A -> pref;
    if (B -> len == B -> res)
        res -> suf = B -> len + A -> suf;
    else
        res -> suf = B -> suf;
    res -> res = max(A -> res, B -> res);
    res -> res = max(res -> res, A -> suf + B -> pref);
    return res;
}

tree *update(tree *nod, int st, int dr, int pos) {
    if (st == dr) {
        tree *res = new tree();
        res -> res = res -> pref = res -> suf = 1;
        res -> len = 1;
        return res;
    }
    int m = (st + dr) / 2;
    if (pos <= m) {
        tree *tmp = update(nod -> l, st, m, pos);
        tree *res = merge(tmp, nod -> r);
        res -> l = tmp;
        res -> r = nod -> r;
        return res;
    } else {
        tree *tmp = update(nod -> r, m + 1, dr, pos);
        tree *res = merge(nod -> l, tmp);
        res -> l = nod -> l;
        res -> r = tmp;
        return res;
    }
}

tree merge2(tree A, tree B) {
    tree res;
    res.len = A.len + B.len;
    if (A.len == A.res)
        res.pref = A.len + B.pref;
    else
        res.pref = A.pref;
    if (B.len == B.res)
        res.suf = B.len + A.suf;
    else
        res.suf = B.suf;
    res.res = max(A.res, B.res);
    res.res = max(res.res, A.suf + B.pref);
    return res;
}

tree get(tree *nod, int st, int dr, int qst, int qdr) {
    if (qst <= st && dr <= qdr) {
        tree _nod;
        _nod.len = nod -> len;
        _nod.pref = nod -> pref;
        _nod.suf = nod -> suf;
        _nod.res = nod -> res;
        return _nod;
    }

    int m = (st + dr) / 2;
    bool haveLeft = false, haveRight = false;
    tree leftSon, rightSon;
    if (qst <= m) {
        haveLeft = true;
        leftSon = get(nod -> l, st, m, qst, qdr);
    }
    if (m < qdr) {
        haveRight = true;
        rightSon = get(nod -> r, m + 1, dr, qst, qdr);
    }

    if (haveLeft && haveRight) {
        tree res;
        res = merge2(leftSon, rightSon);
        return res;
    } else
        if (haveLeft)
            return leftSon;
        else
            return rightSon;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
        pos[i] = i;
    }

    root[0] = build(1, n);

    sort(pos + 1, pos + n + 1, comp());
    for (int i = 1; i <= n; ++i)
        root[i] = update(root[i - 1], 1, n, pos[i]);

    int q;
    scanf("%d", &q);
    while (q--) {
        int qst, qdr, qlen;
        scanf("%d%d%d", &qst, &qdr, &qlen);
        int st = 1, dr = n, best;
        while (st <= dr) {
            int med = (st + dr) / 2;
            if (get(root[med], 1, n, qst, qdr).res >= qlen) {
                best = h[pos[med]];
                dr = med - 1;
            } else
                st = med + 1;
        }
        printf("%d\n", best);
    }

    return 0;
}
