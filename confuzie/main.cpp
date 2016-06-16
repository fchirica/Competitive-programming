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
#define read(n) int (n); scanf("%d", &(n))
#define read2(n, m) int (n), (m); scanf("%d %d", &(n), &(m))
#define read3(n, m, k) int (n), (m), (k); scanf("%d %d %d", &(n), &(m), &(k))
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

const int NMAX = 200100;

vector <int> G[NMAX];
int timp, first[NMAX], last[NMAX], AIB[2* NMAX], dad[17][NMAX], height[NMAX];
bool vis[NMAX], state[NMAX];

void DFS(int nod, int H) {
    vector <int> :: iterator it;
    vis[nod] = 1;
    first[nod] = ++timp;
    height[nod] = H;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            DFS(*it, H + 1);
            dad[0][*it] = nod;
        }
    last[nod] = ++timp;
}

void levelAscensor(int N) {
    for (int pw = 1; (1 << pw) < N; ++pw)
        FOR(i, N)
            dad[pw][i] = dad[pw - 1][dad[pw - 1][i]];
}

inline int lsb(int X) {
    return X & -X;
}

inline void update(int nod, int delta) {
    for (; nod <= timp; nod += lsb(nod))
        AIB[nod] += delta;
}

inline int query(int X) {
    int res = 0;
    for (; X > 0; X = X - lsb(X))
        res += AIB[X];
    return res;
}

int stored;

int queryTree(int xx, int yy) {
    stored = query(first[xx] - 1);
    if (query(first[yy]) <= stored)
        return -1;
    int pw, dif = height[yy] - height[xx];
    for (pw = 0; (1 << pw) <= dif; ++pw); --pw;
    for (; pw >= 0; --pw) {
        int father = dad[pw][yy];
        if ((1 << pw) > dif)
            continue;
        if (!dif)
            break;
        if (query(first[father]) > stored) {
            yy = father;
            dif = dif - (1 << pw);
        }
    }
    return yy;
}

int main() {
    freopen("confuzie.in", "r", stdin);
    freopen("confuzie.out", "w", stdout);

    read2(N, M);
    FOR(i, N - 1) {
        read2(x0, y0);
        G[x0].pb(y0);
        G[y0].pb(x0);
    }

    DFS(1, 1);
    levelAscensor(N);

    FOR(i, M) {
        read(op);
        if (op == 0) {
            read(curNode);
            if (state[curNode] == 0) {
                state[curNode] = 1;
                update(first[curNode], 1);
                update(last[curNode], -1);
            } else {
                update(first[curNode], -1);
                update(last[curNode], 1);
                state[curNode] = 0;
            }
        } else {
            read2(xx, yy);
            printf("%d\n", queryTree(xx, yy));
        }
    }

    return 0;
}
