#include <stdio.h>
#include <string.h>

int suf, nodes;

struct tree {
    int res, fail, len, lazy;
    int sons[26];
} T[1000100];

char x[1000100];

void baga(int pos) {
    int nod = suf;
    int let = x[pos] - 'a';

    while (1) {
        int other_pos = pos - T[nod].len - 1;
        if (other_pos > 0 && x[pos] == x[other_pos])
            break;
        nod = T[nod].fail;
    }

    if (T[nod].sons[let]) {
        suf = T[nod].sons[let];
        ++T[nod].res;
        ++T[nod].lazy;
        return ;
    }

    ++nodes;
    suf = nodes;
    T[nod].sons[let] = nodes;
    T[nodes].len = T[nod].len + 2;
    T[nodes].res = T[nodes].lazy = 1;

    if (T[nodes].len == 1) {
        T[nodes].fail = 2;
        return ;
    }

    while (1) {
        nod = T[nod].fail;
        int other_pos = pos - T[nod].len - 1;
        if (other_pos > 0 && x[pos] == x[other_pos])
            break;
    }
    T[nodes].fail = T[nod].sons[let];
}

int main() {
    freopen("pscpld.in", "r", stdin);
    freopen("pscpld.out", "w", stdout);

    gets(x + 1);
    int n = strlen(x + 1);

    suf = 2;
    T[++nodes].len = -1;
    T[nodes].fail = 1;
    T[++nodes].len = 0;
    T[nodes].fail = 1;

    for (int i = 1; i <= n; ++i)
        baga(i);
    for (int i = nodes; i >= 1; --i) {
        T[T[i].fail].res += T[i].lazy;
        T[T[i].fail].lazy += T[i].lazy;
    }
    long long res = 0;
    for (int i = 3; i <= nodes; ++i)
        res += T[i].res;
    printf("%lld", res);
    return 0;
}
