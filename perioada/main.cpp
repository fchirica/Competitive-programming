#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define FOR(i, n) REP(i, 1, n)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz size
#define DBG(X) cerr << X << "\n";

using namespace std;

char x[101000];
int idx[101000], SA[18][101000], posSA[100100], LCP[100100], rm[18][100100];
ll key[101000];

struct comp {
    bool operator () (int i, int j) {
        return key[i] < key[j];
    }
};

void suffixArrays(int n) {
    int pw;
    for (pw = 0; (1 << pw) <= 2 * n; ++pw) {
        FOR(i, n) {
            key[i] = 1LL * SA[pw - 1][i] * (n + 1000);
            if (i + (1 << (pw - 1)) <= n)
                key[i] += SA[pw - 1][i + (1 << (pw - 1))];
            idx[i] = i;
        }
        if (pw == 0)
            FOR(i, n)
                key[i] = x[i];
        sort(idx + 1, idx + n + 1, comp());
        int cur = 0;
        FOR(i, n)
            if (i > 1 && key[idx[i]] == key[idx[i - 1]])
                SA[pw][idx[i]] = cur;
            else
                SA[pw][idx[i]] = ++cur;
    }
    --pw;
    for (int i = 1; i <= n; ++i) {
        idx[SA[pw][i]] = i;
        posSA[i] = SA[pw][i];
    }
}

//LCP(i, next(i)) >= LCP(i - 1, next(i - 1)) - 1

void Kasai(int N) {
    int lcp = 0;
    for (int i = 1; i <= N; ++i) {
        lcp = max(0, lcp - 1);
        if (posSA[i] == N)
            continue;
        int next = idx[posSA[i] + 1];
        while (1) {
            if (i + lcp <= N && next + lcp <= N && x[i + lcp] == x[next + lcp])
                ++lcp;
            else
                break;
        }
        LCP[posSA[i]] = lcp;
    }
}

int LG[100100];

void RMQ(int N) {
    for (int i = 1; i <= N; ++i)
        rm[0][i] = LCP[i];
    for (int pw = 1; (1 << pw) <= N; ++pw)
        for (int i = 1; i <= N - (1 << pw) + 1; ++i)
            rm[pw][i] = min(rm[pw - 1][i], rm[pw - 1][i + (1 << (pw - 1))]);
    LG[1] = 0;
    for (int i = 2; i <= N; ++i)
        LG[i] = LG[i / 2] + 1;
}

int query(int i, int j) {
    if (posSA[i] > posSA[j])
        swap(i, j);
    i = posSA[i];
    j = posSA[j] - 1;
    int lg = LG[j - i + 1];
    return min(rm[lg][i], rm[lg][j - (1 << lg) + 1]);
}

int check(int per, int xx, int yy) {
    return query(xx, xx + per) >= yy - xx + 1 - per;
}

int main() {
    freopen("perioada.in", "r", stdin);
    freopen("perioada.out", "w", stdout);

    int N;
    scanf("%d\n", &N);
    gets(x + 1);

    suffixArrays(N);
    Kasai(N);
    RMQ(N - 1);

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        int L = (yy - xx + 1);
        int res = 0;
        for (int d = 1; d * d <= L; ++d) {
            if (L % d)
                continue;
            int div1 = d;
            int div2 = L / d;
            if (check(div1, xx, yy))
                ++res;
            if (check(div2, xx, yy) && div2 != L)
                ++res;
            if (d * d == L && check(div1, xx, yy))
                --res;
        }
        printf("%d\n", res);
    }

    return 0;
}
