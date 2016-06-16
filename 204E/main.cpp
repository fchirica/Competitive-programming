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
#define S first

using namespace std;

const int LMAX = 200100;

char tmp[LMAX];
int x[LMAX];
int uppBound[LMAX];

ll key[LMAX];
int idx[LMAX], SA[19][LMAX], rm[19][LMAX], which[LMAX], which2[LMAX], sa[LMAX];

struct comp {
    bool operator () (int i, int j) {
        return key[i] < key[j];
    }
};

int PW;

void suffixArrays(int N) {
    for (int pw = 0; (1 << pw) <= 2 * N; ++pw) {
        PW = pw;
        if (pw == 0)
            for (int i = 1; i <= N; ++i)
                key[i] = S[i] > 0 ? S[i] : -1000000000;
        else
            for (int i = 1; i <= N; ++i) {
                key[i] = (ll)(N + 100) * SA[pw - 1][i];
                if (key[i] < 0) {
                    key[i] = -1000000000;
                    continue;
                }
                if (i + (1 << (pw - 1)) <= N)
                    key[i] += SA[pw - 1][i + (1 << (pw - 1))];
            }
        for (int i = 1; i <= N; ++i)
            idx[i] = i;
        sort(idx + 1, idx + N + 1, comp());
        int cur = 0;
        for (int i = 1; i <= N; ++i) {
            if (i > 1 && key[idx[i]] == key[idx[i - 1]])
                SA[pw][idx[i]] = SA[pw][idx[i - 1]];
            else
                SA[pw][idx[i]] = ++cur;
        }
    }
}

int nextPos[LMAX], small[LMAX];

map <int, bool> used;

int f[LMAX];

void precalc(int N, int K) {
    for (int i = 1; i <= N; ++i)
        f[i] = 1 << 30;
    for (int i = N; i >= 1; --i) {
        if (which[i] == 0)
            continue;
        nextPos[i] = f[which[i]];
        f[which[i]] = i;
    }
    int active = 0, j = -1000;
    for (int i = 1; i <= N; ++i)
        if (which[i]) {
            if (j < i) {
                if (!used[which[i]])
                    used[which[i]] = 1, ++active;
                j = i;
            }
            ++j;
            while (1) {
                if (active == K) {
                    --j;
                    break;
                }
                if (j == N + 1)
                    break;
                if (used[which[j]] == 0) {
                    ++active;
                    used[which[j]] = 1;
                }
                ++j;
            }
            small[i] = j <= N ? j : 0;
            if (nextPos[i] > j)
                used[which[i]] = 0, --active;
        }
}

int lcp(int i, int j, int n) {
    int lim = min(n - i + 1, n - j + 1), pw;
    for (pw = 0; (1 << pw) <= lim; ++pw); --pw;
    int res = 0;
    for (; pw >= 0; --pw)
        if (SA[pw][i] == SA[pw][j] && (i + (1 << pw) - 1) <= n && (j  + (1 << pw) - 1) <= n) {
            i += (1 << pw); j += (1 << pw);
            res += (1 << pw);
        }
    return res;
}

ll res[LMAX];
int LG[LMAX];

void RMQ(int N) {
    for (int i = 1; i < N; ++i)
        rm[0][i] = lcp(sa[i], sa[i + 1], N);
    for (int pw = 1; (1 << pw) <= N; ++pw)
        for (int i = 1; i <= N - (1 << pw) + 1; ++i)
            rm[pw][i] = min(rm[pw - 1][i], rm[pw - 1][i + (1 << (pw - 1))]);
    LG[1] = 0;
    for (int i = 2; i <= N; ++i)
        LG[i] = LG[i / 2] + 1;
}

int query(int i, int j) {
    if (SA[PW][i] > SA[PW][j])
        swap(i, j);
    if (i == j)
        return x[0] - i + 1;
    i = SA[PW][i];
    j = SA[PW][j] - 1;
    int lg = LG[j - i + 1];
    return min(rm[lg][i], rm[lg][j - (1 << lg) + 1]);
}

bool can(int who, int need) {
    int st = 1, dr = SA[PW][who], med, ret;
    while (st <= dr) {
        med = (st + dr) / 2;
        int who2 = sa[med];
        if (query(who, who2) >= need) {
            ret = who2;
            dr = med - 1;
        }
        else
            st = med + 1;
    }
    int rightSide = small[SA[PW][ret]];
    if (rightSide == 0)
        return 0;
    return query(who, sa[rightSide]) >= need;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int N, K;
    scanf("%d%d\n", &N, &K);

    for (int i = 1; i <= N; ++i) {
        gets(tmp + 1);
        int cnt = strlen(tmp + 1);
        if (cnt == 0)
            return 0;
        for (int j = 1; j <= cnt; ++j) {
            x[++x[0]] = tmp[j];
            which2[x[0]] = i;
        }
        uppBound[i] = x[0];
        x[++x[0]] = N + i - 10000000;
    }

    suffixArrays(x[0]);

    for (int i = 1; i <= x[0]; ++i)
        sa[SA[PW][i]] = i;
    for (int i = 1; i <= x[0]; ++i)
        which[i] = which2[sa[i]];

    precalc(x[0], K);
    RMQ(x[0]);

    for (int i = 1; i <= x[0]; ++i)
        if (x[i] > 0) {
            int st = i, dr = uppBound[which2[i]], ret = -1, med;
            while (st <= dr) {
                med = (st + dr) / 2;
                if (can(i, med - i + 1))
                    ret = med - i + 1, st = med + 1;
                else
                    dr = med - 1;
            }
            if (ret > 0)
                res[which2[i]] += ret;
        }

    for (int i = 1; i <= N; ++i)
        printf("%I64d ", res[i]);
    return 0;
}

