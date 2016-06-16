#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>
#include<stack>
#include<cmath>
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int, int>
using namespace std;
struct Vert {
    ll s;
    ll add;
    Vert *l, *r;
    Vert (){
        l = NULL;
        r = NULL;
        s = 0;
        add = 0;
    }
};

Vert *push(Vert *x, int l, int r) {
        if (l + 1 == r) return x;
        int m = (l + r) / 2;
        Vert *nl, *nr;
        nl = new Vert();
        nl->l = x->l->l;
        nl->r = x->l->r;
        nl->add = x->l->add + x->add;
        nl->s = x->l->s + (m - l) * x->add;
        nr = new Vert();
        nr->l = x->r->l;
        nr->r = x->r->r;
        nr->add = x->r->add + x->add;
        nr->s = x->r->s + (r - m) * x->add;
        x->l = nl;
        x->r = nr;
        x->s = nl->s + nr->s;
        x->add = 0;
        return x;
}

vector<int> a;
Vert *make(int l, int r) {
    Vert *t;
    if (l + 1 == r) {
        t = new Vert();
        t->s = a[l];
        return t;
    }
    t = new Vert();
    t->l = make(l, (l + r) / 2);
    t->r = make((l + r) / 2, r);
    t->s = t->l->s + t->r->s;
    return t;
}
int nl, nr, nx;
Vert *add(Vert *x, int l, int r) {
    if (r <= nl) return x;
    if (l >= nr) return x;
    x = push(x, l, r);
    if ((l >= nl) && (r <= nr)) {
        x->s += nx * (r - l);
        x->add = nx;
        return x;
    }
    x->l = add(x->l, l, (l + r) / 2);
    x->r = add(x->r, (l + r) / 2, r);
    x->s = x->l->s + x->r->s;
    return x;

}

ll get(Vert *x, int l, int r, ll cadd = 0) {
    if (r <= nl) return 0;
    if (l >= nr) return 0;
    if ((l >= nl) && (r <= nr)) {
        return x->s + cadd * (r - l);
    }
    return get(x->l, l, (l + r) / 2, cadd + x->add) + get(x->r, (l + r) / 2, r, cadd + x->add);
}

vector<Vert*> town(1);
int main(void) {
    int n, m;
    cin >> n >> m;
    a.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    town[0] = make(0, m);
    int P, X, Y, V, Z, T, L, R, M;
    M = m;
    ll S = 0;
    ll cur;
    Vert *tn;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d%d%d%d", &P, &X, &Y, &V, &Z, &T);
        L = ((X + S) % M);
        R = ((Y + S) % M) + 1;
        nl = L, nr = R, nx = V;
        tn = new Vert();
        tn->l = town[P - 1]->l;
        tn->r = town[P - 1]->r;
        tn->add = town[P - 1]->add;
        tn->s = town[P - 1]->s;
        town.pb(add(tn, 0, m));
        L = ((Z + S) % M);
        R = ((T + S) % M) + 1;
        nl = L, nr = R;
        cur = get(town[i + 1], 0, m);
        S = cur;
        cout << cur << "\n";

    }
}
