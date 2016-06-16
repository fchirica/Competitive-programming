#include <stdio.h>
#include <algorithm>

using namespace std;

struct suma {
    int idx;
    long long val;
} psum[100010];

int x[100010];

inline bool comp(suma A, suma B) {
    return A.val < B.val;
}

int F[100010];

inline int lsb(int X) {
    return X & -X;
}

int query(int pos) {
    int tot = 0;
    for (; pos > 0; pos -= lsb(pos))
        tot += F[pos];
    return tot;
}

void add(int pos, int n, int am) {
    for (; pos <= n; pos += lsb(pos))
        F[pos] += am;
}

long long cnt(long long S, int n) {
    int i = 1;
    for (int i = 1; i <= n; ++i)
        F[i] = 0;
    long long tot = (long long) n * (n - 1) / 2 - n;
    for (int j = 1; j <= n; ++j) {
        while (i < j && psum[j].val - psum[i].val > S) {
            add(psum[i].idx, n, -1);
            ++i;
        }
        tot -= query(psum[j].idx);
    }
    for (int i = 1; i <= n; ++i)
        if (psum[i].val <= S)
            ++tot;
    return tot;
}

int main() {
    freopen("nrsec.in", "r", stdin);
    freopen("nrsec.out", "w", stdout);

    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
        psum[i].val = psum[i - 1].val + x[i];
        psum[i].idx = i;
    }

    sort(psum + 1, psum + n + 1, comp);
    long long st = 1, dr = psum[n].val, med, ret;
    while (st <= dr) {
        med = (st + dr) / 2;
        if (cnt(med, n) >= k) {
            dr = med - 1;
            ret = med;
        } else
            st = med + 1;
    }

    cnt(2, n);

    printf("%lld", ret);
    return 0;
}
