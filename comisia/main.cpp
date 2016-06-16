#include <bits/stdc++.h>

using namespace std;

const int kNMax = 200200;

int rmq[18][kNMax];
int lg[kNMax];
int A[kNMax], B[kNMax];
long long psum[kNMax];
long long res = 1LL << 60;

inline int query(int i, int j) {
    int len = lg[j - i + 1];
    int ind1 = rmq[len][i];
    int ind2 = rmq[len][j - (1 << len) + 1];
    if (A[ind1] > A[ind2])
        return ind1;
    return ind2;
}

inline long long getSum(int i, int j) {
    return psum[j] - psum[i - 1];
}

void doit(int st, int dr) {
    if (st > dr)
        return ;

    int m = query(st, dr);
    int len1 = m - st + 1;
    int len2 = dr - m + 1;
    if (len1 < len2) {
        for (int i = st; i <= m; ++i) {
            int j = i + A[m] - 1;
            if (j > dr)
                break;
            long long cur = getSum(i, j);
            if (cur < res)
                res = cur;
        }
    } else {
        for (int j = m; j <= dr; ++j) {
            int i = j - A[m] + 1;
            if (i < st)
                continue;
            long long cur = getSum(i, j);
            if (cur < res)
                res = cur;
        }
    }
    doit(st, m - 1);
    doit(m + 1, dr);
}

int main() {
    freopen("comisia.in", "r", stdin);
    freopen("comisia.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &B[i]);
        psum[i] = psum[i - 1] + B[i];
    }
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; ++i)
        rmq[0][i] = i;
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            int ind1 = rmq[i - 1][j];
            int ind2 = rmq[i - 1][j + (1 << (i - 1))];
            if (A[ind1] > A[ind2])
                rmq[i][j] = ind1;
            else
                rmq[i][j] = ind2;
        }
    doit(1, n);
    printf("%lld", res);
    return 0;
}
