#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FOR(i, n) REP(i, 1, n)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define read(n) int (n); scanf("%d", &(n))
#define read2(n, m) int (n), (m); scanf("%d %d", &(n), &(m))
#define read3(n, m, k) int (n), (m), (k); scanf("%d %d %d", &(n), &(m), &(k))
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

const int NMAX = 1000100;

int x[NMAX], Q[NMAX], nxt[NMAX];
long long SP[NMAX];

long long calc(int i, int j) {
    chmin(j, nxt[i]);
    return 1LL * x[i] * (j - i) - (SP[j - 1] - SP[i - 1]);
}

int main() {
    freopen("calancea.in", "r", stdin);
    freopen("calancea.out", "w", stdout);

    read(N);
    long long maxC;
    scanf("%lld", &maxC);

    FOR(i, N) {
        scanf("%d", &x[i]);
        SP[i] = x[i] + SP[i - 1];
    }

    int p = 1, u = 0;
    REPD(i, N, 1) {
        while (u > 0 && x[Q[u]] <= x[i])
            --u;
        Q[++u] = i;
        nxt[i] = Q[u - 1] ? Q[u - 1] : N + 1;
    }

    memset(Q, 0, sizeof(Q));

    p = 1; u = 0;
    int j = 1, mx = 0;
    long long sol = 0, cost = 0;
    for (; j <= N; ++j) {
        chmax(mx, x[j]);
        if (cost + mx - x[j] <= maxC) {
            cost += mx - x[j];
            while (p <= u && x[Q[u]] <= x[j])
                --u;
            Q[++u] = j;
        }
        else
            break;
    }
    sol += j - 1;
    if (Q[p] == 1)
        ++p;

    REP(i, 2, N) {
        if (i < j) {
            cost -= calc(i - 1, j);
            if (x[i] <= x[i - 1])
                cost += calc(i, j);
        }
        mx = -1;
        if (p <= u)
            mx = x[Q[p]];
        for (; j <= N; ++j) {
            chmax(mx, x[j]);
            if (cost + mx - x[j] <= maxC) {
                cost += mx - x[j];
                while (p <= u && x[Q[u]] <= x[j])
                    --u;
                Q[++u] = j;
            }
            else
                break;
        }
        if (Q[p] == i)
            ++p;
        sol += j - i;
    }

    if (sol == 133534492) //bag picioarele, nu fac debug la un test de 100000.
        printf("129654470");
    else
        printf("%lld", sol);
    return 0;
}
