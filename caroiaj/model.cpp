#include <stdio.h>
#include <algorithm>

using namespace std;

int x[100010];
long long psum[100010];

struct query {
    int val, idx;
    long long res;
} q[100010];

struct comp {
    inline bool operator () (query A, query B) {
        if ((A.val & 1) == (B.val & 1))
            return A.val < B.val;
        return (A.val & 1) < (B.val & 1);
    }
};

struct comp2 {
    inline bool operator () (query A, query B) {
        return A.idx < B.idx;
    }
};

long long calc(int pos, int val) {
    int rem = val - (pos - 1);
    if (rem < 0)
        return 0;

    return psum[pos] + (rem >> 1) * ((long long) x[pos] + x[pos - 1]) + (rem & 1) * x[pos - 1];
}

void doit(int qst, int qdr, int st, int dr) {
    if (qst > qdr)
        return ;

    int med = (qst + qdr) / 2, ret = 0;
    for (int i = st; i <= dr; ++i) {
        long long _ret = calc(i, q[med].val);
        if (_ret > q[med].res) {
            q[med].res = _ret;
            ret = i;
        }
    }
    doit(qst, med - 1, st, ret);
    doit(med + 1, qdr, ret, dr);
}

int main() {
    int t = 1;
    while (t--) {
        int n, qCnt;
        scanf("%d%d", &n, &qCnt);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x[i]);
            psum[i] = psum[i - 1] + x[i];
        }
        for (int i = 1; i <= qCnt; ++i) {
            scanf("%d", &q[i].val);
            q[i].idx = i;
        }
        sort(q + 1, q + qCnt + 1, comp());
        for (int i = 1; i <= qCnt + 1; ++i)
            if (q[i].val % 2 || i == qCnt + 1) {
                doit(1, i - 1, 2, n);
                doit(i, qCnt, 2, n);
                break;
            }
        sort(q + 1, q + qCnt + 1, comp2());
        for (int i = 1; i <= qCnt; ++i) {
            printf("%lld\n", q[i].res);
            q[i].res = 0;
        }
    }

    return 0;
}
