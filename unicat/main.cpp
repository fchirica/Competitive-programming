#include <stdio.h>
#include <string.h>

char A[500500], B[500500];

struct tree {
    int len, fail, mask;
    int go[26];
} T[2 * 500500];

int cnt, suf;

void baga(int pos, int type) {
    int nod = suf;
    int let = A[pos] - 'a';
    while (1) {
        int other_pos = pos - T[nod].len - 1;
        if (A[pos] == A[other_pos])
            break;
        nod = T[nod].fail;
    }
    if (T[nod].go[let]) {
        suf = nod = T[nod].go[let];
        T[nod].mask |= (1 << type);
        return ;
    }
    suf = ++cnt;
    T[cnt].len = T[nod].len + 2;
    T[cnt].mask |= (1 << type);
    T[nod].go[let] = cnt;
    if (T[cnt].len == 1) {
        T[cnt].fail = 2;
        return ;
    }
    while (1) {
        nod = T[nod].fail;
        int other_pos = pos - T[nod].len - 1;
        if (A[pos] == A[other_pos])
            break;
    }
    T[cnt].fail = T[nod].go[let];
}

int main() {
    freopen("unicat.in", "r", stdin);
    freopen("unicat.out", "w", stdout);

    gets(A + 1);
    gets(B + 1);
    int n = strlen(A + 1);
    int m = strlen(B + 1);

    suf = cnt = 2;
    T[1].len = -1;
    T[1].fail = 1;
    T[2].len = 0;
    T[2].fail = 1;

    for (int i = 1; i <= n; ++i)
        baga(i, 0);
    suf = 2;
    for (int i = 1; i <= m; ++i)
        A[i] = B[i];
    for (int i = 1; i <= m; ++i)
        baga(i, 1);
    int res = 0;
    for (int i = 3; i <= cnt; ++i)
        if (T[i].mask == 3)
            ++res;
    printf("%d", res);
    return 0;
}
