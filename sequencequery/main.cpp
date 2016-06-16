#include <stdio.h>

struct AINT {
    long long sum, left, right, res;
} A[4 * 200200];

long long max(long long A, long long B) {
    return A > B ? A : B;
}

void update(int nod, int st, int dr, int pos, int val) {
    if (st == dr) {
        A[nod].sum = A[nod].left = A[nod].right = A[nod].res = val;
        return ;
    }
    int med = (st + dr) / 2;
    if (pos <= med)
        update(2 * nod, st, med, pos, val);
    else
        update(2 * nod + 1, med + 1, dr, pos, val);
    A[nod].sum = A[2 * nod].sum + A[2 * nod + 1].sum;
    A[nod].left = max(A[2 * nod].left, A[2 * nod].sum + A[2 * nod + 1].left);
    A[nod].right = max(A[2 * nod + 1].right, A[2 * nod + 1].sum + A[2 * nod].right);
    A[nod].res = max(A[2 * nod].res, A[2 * nod + 1].res);
    A[nod].res = max(A[nod].res, A[2 * nod].right + A[2 * nod + 1].left);
}

AINT query(int nod, int st, int dr, int a, int b) {
    if (a <= st && dr <= b)
        return A[nod];
    bool leftSon = false, rightSon = false;
    AINT left, right;
    int med = (st + dr) / 2;
    if (a <= med)
        leftSon = true, left = query(2 * nod, st, med, a, b);
    if (med < b)
        rightSon = true, right = query(2 * nod + 1, med + 1, dr, a, b);
    if (leftSon && rightSon) {
        AINT tmp;
        tmp.sum = left.sum + right.sum;
        tmp.left = max(left.left, left.sum + right.left);
        tmp.right = max(right.right, right.sum + left.right);
        tmp.res = max(left.res, right.res);
        tmp.res = max(tmp.res, left.right + right.left);
        return tmp;
    }
    if (leftSon)
        return left;
    return right;
}

int main() {
    freopen("maxq.in", "r", stdin);
    freopen("maxq.out", "w", stdout);

    int N, M;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        update(1, 1, N, i, tmp);
    }
    scanf("%d", &M);
    for (int i = 1; i <= M; ++i) {
        int type, xx, yy;
        scanf("%d%d%d", &type, &xx, &yy);
        if (type == 0) {
            update(1, 1, N, xx + 1, yy);
            continue;
        }
        AINT tmp = query(1, 1, N, xx + 1, yy + 1);
        printf("%lld\n", max(tmp.res, 0));
    }

    return 0;
}
