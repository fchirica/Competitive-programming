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
#define pair <int, int> pii

using namespace std;

int sol, x[100100], shit[100100], vis[100100], path[100100], idx[100100];
vector <int> G[100100];

inline bool comp(int A, int B) {
    if (path[A] == path[B])
        return A < B;
    return path[A] < path[B];
}

int AIB[100100];

inline int lsb(int X) {
    return X & -X;
}

int query(int X) {
    int ma = -1;
    for (; X > 0; X = X - lsb(X))
        chmax(ma, AIB[X]);
    return ma;
}

void update(int X, int Y) {
    for (; X <= path[0]; X = X + lsb(X))
        chmax(AIB[X], Y);
}

void scmax() {
    FOR(i, path[0])
        idx[i] = i;
    sort(idx + 1, idx + path[0] + 1, comp);
    FOR(i, path[0])
        shit[idx[i]] = i;
    FOR(i, path[0])
        AIB[i] = 0;
    FOR(i, path[0]) {
        int ma = query(shit[i]);
        chmax(sol, ma + 1);
        update(shit[i], ma + 1);
    }
}

void DFS(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    bool isLeaf = true;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            isLeaf = false;
            path[++path[0]] = x[*it];
            DFS(*it);
            --path[0];
        }
    if (isLeaf && rand() % 2)
        scmax();
}

int main() {
    freopen("treemis.in", "r", stdin);
    freopen("treemis.out", "w", stdout);

    int N;
    scanf("%d", &N);
    FOR(i, N)
        scanf("%d", &x[i]);
    FOR(i, N - 1) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        ++xx; ++yy;
        G[xx].pb(yy);
        G[yy].pb(xx);
    }

    srand(time(0));
    double startT = clock();

    while (1) {
        double curT = clock();
        if ((curT - startT) / CLOCKS_PER_SEC > 1.3)
            break;
        int XXX = rand() % N + 1;
        path[0] = 0; path[++path[0]] = x[XXX];
        FOR(i, N)
            vis[i] = 0;
        DFS(XXX);
    }

    printf("%d", sol);
    return 0;
}
